/**********************************************************************

  Audacity: A Digital Audio Editor

  ProjectsPrefs.h

  Joshua Haberman
  Dominic Mazzoni
  James Crook

**********************************************************************/

#ifndef __AUDACITY_PROJECT_PREFS__
#define __AUDACITY_PROJECT_PREFS__

#include <wx/defs.h>

#include <wx/window.h>

#include "../ShuttleGui.h"

#include "PrefsPanel.h"

class ProjectsPrefs:public PrefsPanel
{
 public:
   ProjectsPrefs(wxWindow * parent);
   ~ProjectsPrefs();
   virtual bool Apply();
   
 private:
   void Populate();
   void PopulateOrExchange(ShuttleGui & S);
};

#endif

// Indentation settings for Vim and Emacs and unique identifier for Arch, a
// version control system. Please do not modify past this point.
//
// Local Variables:
// c-basic-offset: 3
// indent-tabs-mode: nil
// End:
//
// vim: et sts=3 sw=3
// arch-tag: 300a00cc-0770-45a1-8ab5-88cfb7ae1239
