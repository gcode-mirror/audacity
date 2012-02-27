/**********************************************************************

  Audacity: A Digital Audio Editor

  Legacy.cpp

  Dominic Mazzoni

*******************************************************************//*!

\file Legacy.cpp
\brief Converts old Audacity file types.  Implements 
AutoRollbackRenamer.

  These routines convert Audacity project files from the
  0.98...1.0 format into an XML format that's compatible with
  Audacity 1.2.0 and newer.

*//****************************************************************//**

\class AutoRollbackRenamer
\brief AutoRollbackRenamer handles the renaming of files
which is needed when producing a new version of a file which may fail.
On failure the old version is put back in place.

*//*******************************************************************/


#include "Audacity.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <wx/defs.h>
#include <wx/ffile.h>
#include <wx/filefn.h>
#include <wx/intl.h>
#include <wx/msgdlg.h>
#include <wx/string.h>
#include <wx/textfile.h>

#include "Internat.h"
#include "Legacy.h"
#include "xml/XMLWriter.h"

class AutoRollbackRenamer {
public:
   AutoRollbackRenamer(wxString oldName, wxString newName) {
      mOldName = oldName;
      mNewName = newName;
      mRenameSucceeded = ::wxRenameFile(mOldName, mNewName);
      mFinished = false;
      mNewFile = NULL;
   }
   ~AutoRollbackRenamer()
   {
      if (mNewFile)
         fclose(mNewFile);

      if (mRenameSucceeded && !mFinished) {
         ::wxRemoveFile(mOldName);
         ::wxRenameFile(mNewName, mOldName);
      }
   }
   bool RenameSucceeded()
   {
      return mRenameSucceeded;
   }
   void Finished()
   {
      mFinished = true;
   }
   void SetNewFile(FILE *f)
   {
      mNewFile = f;
   }

   wxString mOldName, mNewName;
   bool mRenameSucceeded;
   bool mFinished;
   FILE *mNewFile;
};

bool ConvertLegacyTrack(wxTextFile *f, XMLFileWriter &xmlFile)
{
   wxString line;
   wxString kind;

   kind = (*f)[f->GetCurrentLine()];

   if (kind == wxT("WaveTrack")) {
      xmlFile.StartTag(wxT("wavetrack"));
      xmlFile.WriteAttr(wxT("name"), f->GetNextLine());

      wxString channel = f->GetNextLine();
      if (channel == wxT("left")) {
         xmlFile.WriteAttr(wxT("channel"), 0);
         line = f->GetNextLine();
      }
      else if (channel == wxT("right")) {
         xmlFile.WriteAttr(wxT("channel"), 1);
         line = f->GetNextLine();
      }
      else if (channel == wxT("mono")) {
         xmlFile.WriteAttr(wxT("channel"), 2);
         line = f->GetNextLine();
      }
      else {
         xmlFile.WriteAttr(wxT("channel"), 2);
         line = channel;
      }

      if (line == wxT("linked")) {
         xmlFile.WriteAttr(wxT("linked"), 1);
         line = f->GetNextLine();
      }

      if (line != wxT("offset"))
         return false;
      xmlFile.WriteAttr(wxT("offset"), f->GetNextLine());

      long envLen;

      if (f->GetNextLine() != wxT("EnvNumPoints"))
         return false;
      line = f->GetNextLine();
      line.ToLong(&envLen);
      if (envLen < 0 || envLen > 10000)
         return false;

      size_t envStart = f->GetCurrentLine();
      if (f->GetLineCount() < envStart+(2*envLen)+1)
         return false;

      f->GoToLine(envStart+(2*envLen));
      if (f->GetNextLine() != wxT("EnvEnd"))
         return false;
      if (f->GetNextLine() != wxT("numSamples"))
         return false;

      wxString numSamples = f->GetNextLine();

      if (f->GetNextLine() != wxT("rate"))
         return false;

      xmlFile.WriteAttr(wxT("rate"), f->GetNextLine());

      if (envLen > 0) {
         xmlFile.StartTag(wxT("envelope"));
         xmlFile.WriteAttr(wxT("numpoints"), envLen);

         long i;
         for(i=0; i<envLen; i++) {
            xmlFile.StartTag(wxT("controlpoint"));
            xmlFile.WriteAttr(wxT("t"), f->GetLine(envStart + 2*i + 1));
            xmlFile.WriteAttr(wxT("val"), f->GetLine(envStart + 2*i + 2));
            xmlFile.EndTag(wxT("controlpoint"));
         }

         xmlFile.EndTag(wxT("envelope"));
      }

      if (f->GetNextLine() != wxT("numBlocks"))
         return false;
      long numBlocks;
      line = f->GetNextLine();
      line.ToLong(&numBlocks);

      if (numBlocks < 0 || numBlocks > 131072)
         return false;

      xmlFile.StartTag(wxT("sequence"));
      xmlFile.WriteAttr(wxT("maxsamples"), 524288);
      xmlFile.WriteAttr(wxT("sampleformat"), 131073);
      xmlFile.WriteAttr(wxT("numsamples"), numSamples);

      long b;
      for(b=0; b<numBlocks; b++) {
         wxString start;
         wxString len;
         wxString name;

         if (f->GetNextLine() != wxT("Block start"))
            return false;
         start = f->GetNextLine();
         if (f->GetNextLine() != wxT("Block len"))
            return false;
         len = f->GetNextLine(); 
         if (f->GetNextLine() != wxT("Block info"))
            return false;
         name = f->GetNextLine();

         xmlFile.StartTag(wxT("waveblock"));
         xmlFile.WriteAttr(wxT("start"), start);

         xmlFile.StartTag(wxT("legacyblockfile"));
         if (name == wxT("Alias")) {
            wxString aliasPath = f->GetNextLine();
            wxString localLen = f->GetNextLine();
            wxString aliasStart = f->GetNextLine();
            wxString aliasLen = f->GetNextLine();
            wxString aliasChannel = f->GetNextLine();
            wxString localName = f->GetNextLine();

            xmlFile.WriteAttr(wxT("name"), localName);
            xmlFile.WriteAttr(wxT("alias"), 1);
            xmlFile.WriteAttr(wxT("aliaspath"), aliasPath);
            xmlFile.WriteAttr(wxT("aliasstart"), aliasStart);
            xmlFile.WriteAttr(wxT("aliaslen"), aliasLen);
            xmlFile.WriteAttr(wxT("aliaschannel"), aliasChannel);
            xmlFile.WriteAttr(wxT("summarylen"), localLen);
            xmlFile.WriteAttr(wxT("norms"), 1);
         }
         else {
            xmlFile.WriteAttr(wxT("name"), name);
            xmlFile.WriteAttr(wxT("len"), len);
            xmlFile.WriteAttr(wxT("summarylen"), 8244);
            xmlFile.WriteAttr(wxT("norms"), 1);
         }
         xmlFile.EndTag(wxT("legacyblockfile"));

         xmlFile.EndTag(wxT("waveblock"));
      }

      xmlFile.EndTag(wxT("sequence"));
      xmlFile.EndTag(wxT("wavetrack"));
      
      return true;
   }
   else if (kind == wxT("LabelTrack")) {
      line = f->GetNextLine();
      if (line != wxT("NumMLabels"))
         return false;

      long numLabels, l;

      line = f->GetNextLine();
      line.ToLong(&numLabels);
      if (numLabels < 0 || numLabels > 1000000)
         return false;

      xmlFile.StartTag(wxT("labeltrack"));
      xmlFile.WriteAttr(wxT("name"), wxT("Labels"));
      xmlFile.WriteAttr(wxT("numlabels"), numLabels);

      for(l=0; l<numLabels; l++) {
         wxString t, title;

         t = f->GetNextLine();
         title = f->GetNextLine();

         xmlFile.StartTag(wxT("label"));
         xmlFile.WriteAttr(wxT("t"), t);
         xmlFile.WriteAttr(wxT("title"), title);
         xmlFile.EndTag(wxT("label"));
      }

      xmlFile.EndTag(wxT("labeltrack"));

      line = f->GetNextLine();
      if (line != wxT("MLabelsEnd"))
         return false;

      return true;
   }
   else if (kind == wxT("NoteTrack")) {
      // Just skip over it - they didn't even work in version 1.0!

      do {
         line = f->GetNextLine();
         if (line == wxT("WaveTrack") ||
             line == wxT("NoteTrack") ||
             line == wxT("LabelTrack") ||
             line == wxT("EndTracks")) {
            f->GoToLine(f->GetCurrentLine()-1);
            return true;
         }
      } while (f->GetCurrentLine() < f->GetLineCount());

      return false;
   }
   else
      return false;
}

bool ConvertLegacyProjectFile(wxFileName filename)
{
   wxTextFile f;
   XMLFileWriter xmlFile;
   int index = 0;
   wxString backupName;

   do {
      index++;
      fflush(stdout);
      backupName = filename.GetPath() + wxFILE_SEP_PATH + filename.GetName() +
         wxT("_bak") + wxString::Format(wxT("%d"), index) + wxT(".") + filename.GetExt();
   } while(::wxFileExists(backupName));

   // This will move the original file out of the way, but 
   // move it back if we exit from this function early.
   AutoRollbackRenamer renamer(filename.GetFullPath(), backupName);
   if (!renamer.RenameSucceeded())
      return false;

   f.Open(backupName);
   if (!f.IsOpened())
      return false;

   wxString name = filename.GetFullPath();

   xmlFile.Open(name, wxT("wb"));
   if (!xmlFile.IsOpened())
      return false;

   renamer.SetNewFile(xmlFile.fp());

   xmlFile.Write(wxT("<?xml version=\"1.0\"?>\n"));

   wxString label;
   wxString value;

   if (f.GetFirstLine() != wxT("AudacityProject"))
      return false;
   if (f.GetNextLine() != wxT("Version"))
      return false;
   if (f.GetNextLine() != wxT("0.95"))
      return false;
   if (f.GetNextLine() != wxT("projName"))
      return false;

   xmlFile.StartTag(wxT("audacityproject"));
   xmlFile.WriteAttr(wxT("projname"), f.GetNextLine());
   xmlFile.WriteAttr(wxT("version"), wxT("1.1.0"));
   xmlFile.WriteAttr(wxT("audacityversion"),AUDACITY_VERSION_STRING);

   label = f.GetNextLine();
   while (label != wxT("BeginTracks")) {
      xmlFile.WriteAttr(label, f.GetNextLine());
      label = f.GetNextLine();
   }

   label = f.GetNextLine();
   while (label != wxT("EndTracks")) {
      bool success = ConvertLegacyTrack(&f, xmlFile);
      if (!success)
         return false;
      label = f.GetNextLine();
   }

   xmlFile.EndTag(wxT("audacityproject"));

   renamer.Finished();

   ::wxMessageBox(wxString::Format(_("Converted a 1.0 project file to the new format.\nThe old file has been saved as '%s'"), backupName.c_str()),
                  _("Opening Audacity Project"));

   return true;
}

// Indentation settings for Vim and Emacs and unique identifier for Arch, a
// version control system. Please do not modify past this point.
//
// Local Variables:
// c-basic-offset: 3
// indent-tabs-mode: nil
// End:
//
// vim: et sts=3 sw=3
// arch-tag: b15960fe-5b13-4cda-b2b1-da4dd59d1cd4
