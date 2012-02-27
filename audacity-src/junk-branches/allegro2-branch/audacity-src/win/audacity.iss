; Script generated by the Inno Setup Script Wizard.
; SEE THE DOCUMENTATION FOR DETAILS ON CREATING INNO SETUP SCRIPT FILES!

[Setup]
; compiler-related directives
OutputBaseFilename=audacity-win-1.3.0
SolidCompression=yes

; installer-related directives
AppName=Audacity 1.3 Beta
AppVerName=Audacity 1.3.0
AppPublisher=Audacity Team
AppPublisherURL=http://audacity.sourceforge.net
AppSupportURL=http://audacity.sourceforge.net
AppUpdatesURL=http://audacity.sourceforge.net
ChangesAssociations=yes
DefaultDirName={pf}\Audacity 1.3 Beta
; Always warn if dir exists, because we'll overwrite previous Audacity.
DirExistsWarning=yes
DisableProgramGroupPage=yes
UninstallDisplayIcon="{app}\audacity.exe"
LicenseFile=..\LICENSE.txt
InfoBeforeFile=..\README.txt
; min versions: Win95, NT 4.0
MinVersion=4.0,4.0

[Languages]
Name: "english"; MessagesFile: "compiler:Default.isl"
Name: "basque"; MessagesFile: "compiler:Languages\Basque.isl"
Name: "brazilianportuguese"; MessagesFile: "compiler:Languages\BrazilianPortuguese.isl"
Name: "catalan"; MessagesFile: "compiler:Languages\Catalan.isl"
Name: "czech"; MessagesFile: "compiler:Languages\Czech.isl"
Name: "danish"; MessagesFile: "compiler:Languages\Danish.isl"
Name: "dutch"; MessagesFile: "compiler:Languages\Dutch.isl"
Name: "finnish"; MessagesFile: "compiler:Languages\Finnish.isl"
Name: "french"; MessagesFile: "compiler:Languages\French.isl"
Name: "german"; MessagesFile: "compiler:Languages\German.isl"
Name: "hungarian"; MessagesFile: "compiler:Languages\Hungarian.isl"
Name: "italian"; MessagesFile: "compiler:Languages\Italian.isl"
Name: "norwegian"; MessagesFile: "compiler:Languages\Norwegian.isl"
Name: "polish"; MessagesFile: "compiler:Languages\Polish.isl"
Name: "portuguese"; MessagesFile: "compiler:Languages\Portuguese.isl"
Name: "russian"; MessagesFile: "compiler:Languages\Russian.isl"
Name: "slovak"; MessagesFile: "compiler:Languages\Slovak.isl"
Name: "slovenian"; MessagesFile: "compiler:Languages\Slovenian.isl"
Name: "spanish"; MessagesFile: "compiler:Languages\Spanish.isl"

[Tasks]
Name: desktopicon; Description: "Create a &desktop icon"; GroupDescription: "Additional icons:"; MinVersion: 4,4
Name: associate_aup; Description: "&Associate Audacity project files"; GroupDescription: "Other tasks:"; Flags: checkedonce; MinVersion: 4,4


[Files]
Source: "..\win\Release\audacity.exe"; DestDir: "{app}"; Flags: ignoreversion
Source: "..\win\Release\audacity-1.2-help.htb"; DestDir: "{app}"; Flags: ignoreversion
Source: "..\win\Release\Languages\ar\*.*"; DestDir: "{app}\Languages\ar"; Flags: ignoreversion
Source: "..\win\Release\Languages\bg\*.*"; DestDir: "{app}\Languages\bg"; Flags: ignoreversion
Source: "..\win\Release\Languages\ca\*.*"; DestDir: "{app}\Languages\ca"; Flags: ignoreversion
Source: "..\win\Release\Languages\cs\*.*"; DestDir: "{app}\Languages\cs"; Flags: ignoreversion
Source: "..\win\Release\Languages\da\*.*"; DestDir: "{app}\Languages\da"; Flags: ignoreversion
Source: "..\win\Release\Languages\de\*.*"; DestDir: "{app}\Languages\de"; Flags: ignoreversion
Source: "..\win\Release\Languages\el\*.*"; DestDir: "{app}\Languages\el"; Flags: ignoreversion
Source: "..\win\Release\Languages\es\*.*"; DestDir: "{app}\Languages\es"; Flags: ignoreversion
Source: "..\win\Release\Languages\eu\*.*"; DestDir: "{app}\Languages\eu"; Flags: ignoreversion
Source: "..\win\Release\Languages\fi\*.*"; DestDir: "{app}\Languages\fi"; Flags: ignoreversion
Source: "..\win\Release\Languages\fr\*.*"; DestDir: "{app}\Languages\fr"; Flags: ignoreversion
Source: "..\win\Release\Languages\ga\*.*"; DestDir: "{app}\Languages\ga"; Flags: ignoreversion
Source: "..\win\Release\Languages\hu\*.*"; DestDir: "{app}\Languages\hu"; Flags: ignoreversion
Source: "..\win\Release\Languages\it\*.*"; DestDir: "{app}\Languages\it"; Flags: ignoreversion
Source: "..\win\Release\Languages\ja\*.*"; DestDir: "{app}\Languages\ja"; Flags: ignoreversion
Source: "..\win\Release\Languages\lt\*.*"; DestDir: "{app}\Languages\lt"; Flags: ignoreversion
Source: "..\win\Release\Languages\mk\*.*"; DestDir: "{app}\Languages\mk"; Flags: ignoreversion
Source: "..\win\Release\Languages\nb\*.*"; DestDir: "{app}\Languages\nb"; Flags: ignoreversion
Source: "..\win\Release\Languages\nl\*.*"; DestDir: "{app}\Languages\nl"; Flags: ignoreversion
Source: "..\win\Release\Languages\pl\*.*"; DestDir: "{app}\Languages\pl"; Flags: ignoreversion
Source: "..\win\Release\Languages\pt\*.*"; DestDir: "{app}\Languages\pt"; Flags: ignoreversion
Source: "..\win\Release\Languages\ru\*.*"; DestDir: "{app}\Languages\ru"; Flags: ignoreversion
Source: "..\win\Release\Languages\sl\*.*"; DestDir: "{app}\Languages\sl"; Flags: ignoreversion
Source: "..\win\Release\Languages\sv\*.*"; DestDir: "{app}\Languages\sv"; Flags: ignoreversion
Source: "..\win\Release\Languages\uk\*.*"; DestDir: "{app}\Languages\uk"; Flags: ignoreversion
Source: "..\win\Release\Languages\zh\*.*"; DestDir: "{app}\Languages\zh"; Flags: ignoreversion
Source: "..\win\Release\Languages\zh_TW\*.*"; DestDir: "{app}\Languages\zh_TW"; Flags: ignoreversion
Source: "..\README.txt"; DestDir: "{app}"; Flags: ignoreversion
Source: "..\LICENSE.txt"; DestDir: "{app}"; Flags: ignoreversion
Source: "..\win\Release\Nyquist\bug.lsp"; DestDir: "{app}\Nyquist"; Flags: ignoreversion
Source: "..\win\Release\Nyquist\dspprims.lsp"; DestDir: "{app}\Nyquist"; Flags: ignoreversion
Source: "..\win\Release\Nyquist\evalenv.lsp"; DestDir: "{app}\Nyquist"; Flags: ignoreversion
Source: "..\win\Release\Nyquist\follow.lsp"; DestDir: "{app}\Nyquist"; Flags: ignoreversion
Source: "..\win\Release\Nyquist\init.lsp"; DestDir: "{app}\Nyquist"; Flags: ignoreversion
Source: "..\win\Release\Nyquist\misc.lsp"; DestDir: "{app}\Nyquist"; Flags: ignoreversion
Source: "..\win\Release\Nyquist\nyinit.lsp"; DestDir: "{app}\Nyquist"; Flags: ignoreversion
Source: "..\win\Release\Nyquist\nyqmisc.lsp"; DestDir: "{app}\Nyquist"; Flags: ignoreversion
Source: "..\win\Release\Nyquist\nyquist.lsp"; DestDir: "{app}\Nyquist"; Flags: ignoreversion
Source: "..\win\Release\Nyquist\printrec.lsp"; DestDir: "{app}\Nyquist"; Flags: ignoreversion
Source: "..\win\Release\Nyquist\profile.lsp"; DestDir: "{app}\Nyquist"; Flags: ignoreversion
Source: "..\win\Release\Nyquist\seq.lsp"; DestDir: "{app}\Nyquist"; Flags: ignoreversion
Source: "..\win\Release\Nyquist\seqfnint.lsp"; DestDir: "{app}\Nyquist"; Flags: ignoreversion
Source: "..\win\Release\Nyquist\seqmidi.lsp"; DestDir: "{app}\Nyquist"; Flags: ignoreversion
Source: "..\win\Release\Nyquist\sndfnint.lsp"; DestDir: "{app}\Nyquist"; Flags: ignoreversion
Source: "..\win\Release\Nyquist\system.lsp"; DestDir: "{app}\Nyquist"; Flags: ignoreversion
Source: "..\win\Release\Nyquist\test.lsp"; DestDir: "{app}\Nyquist"; Flags: ignoreversion
Source: "..\win\Release\Nyquist\xlinit.lsp"; DestDir: "{app}\Nyquist"; Flags: ignoreversion
; doesn't work:     Source: "..\win\Release\Plug-Ins\analyze.ny"; DestDir: "{app}\Plug-Ins"; Flags: ignoreversion
Source: "..\win\Release\Plug-Ins\beat.ny"; DestDir: "{app}\Plug-Ins"; Flags: ignoreversion
Source: "..\win\Release\Plug-Ins\clicktrack.ny"; DestDir: "{app}\Plug-Ins"; Flags: ignoreversion
Source: "..\win\Release\Plug-Ins\crossfadein.ny"; DestDir: "{app}\Plug-Ins"; Flags: ignoreversion
Source: "..\win\Release\Plug-Ins\crossfadeout.ny"; DestDir: "{app}\Plug-Ins"; Flags: ignoreversion
Source: "..\win\Release\Plug-Ins\delay.ny"; DestDir: "{app}\Plug-Ins"; Flags: ignoreversion
; redundant:     Source: "..\win\Release\Plug-Ins\fadein.ny"; DestDir: "{app}\Plug-Ins"; Flags: ignoreversion
; redundant:     Source: "..\win\Release\Plug-Ins\fadeout.ny"; DestDir: "{app}\Plug-Ins"; Flags: ignoreversion
Source: "..\win\Release\Plug-Ins\GVerb.dll"; DestDir: "{app}\Plug-Ins"; Flags: ignoreversion
Source: "..\win\Release\Plug-Ins\Hard Limiter.dll"; DestDir: "{app}\Plug-Ins"; Flags: ignoreversion
Source: "..\win\Release\Plug-Ins\highpass.ny"; DestDir: "{app}\Plug-Ins"; Flags: ignoreversion
Source: "..\win\Release\Plug-Ins\lowpass.ny"; DestDir: "{app}\Plug-Ins"; Flags: ignoreversion
Source: "..\win\Release\Plug-Ins\pluck.ny"; DestDir: "{app}\Plug-Ins"; Flags: ignoreversion
Source: "..\win\Release\Plug-Ins\sc4.dll"; DestDir: "{app}\Plug-Ins"; Flags: ignoreversion
Source: "..\win\Release\Plug-Ins\SilenceMarker.ny"; DestDir: "{app}\Plug-Ins"; Flags: ignoreversion
Source: "..\win\Release\Plug-Ins\tremolo.ny"; DestDir: "{app}\Plug-Ins"; Flags: ignoreversion
; redundant:     Source: "..\win\Release\Plug-Ins\undcbias.ny"; DestDir: "{app}\Plug-Ins"; Flags: ignoreversion


[Icons]
Name: "{commonprograms}\Audacity 1.3 Beta"; Filename: "{app}\audacity.exe"
Name: "{userdesktop}\Audacity 1.3 Beta"; Filename: "{app}\audacity.exe"; MinVersion: 4,4; Tasks: desktopicon

[InstallDelete]
; Get rid of Audacity 1.0.0 stuff that's no longer used.
Type: files; Name: "{app}\audacity-help.htb"
; Don't think we want to do this because user may have stored their own.
;   Type: filesandordirs; Name: "{app}\vst"

; We've switched from a folder in the start menu to just the Audacity.exe at the top level.
; Get rid of 1.0.0 folder and its icons.
Type: files; Name: "{commonprograms}\Audacity\audacity.exe"
Type: files; Name: "{commonprograms}\Audacity\unins000.exe"
Type: dirifempty; Name: "{commonprograms}\Audacity"

[Registry]
Root: HKCR; Subkey: ".AUP"; ValueType: string; ValueData: "Audacity.Project"; Flags: createvalueifdoesntexist uninsdeletekey; Tasks: associate_aup
Root: HKCR; Subkey: "Audacity.Project"; ValueType: string; ValueData: "Audacity Project File"; Flags: createvalueifdoesntexist uninsdeletekey; Tasks: associate_aup
Root: HKCR; Subkey: "Audacity.Project\shell"; ValueType: string; ValueData: ""; Flags: createvalueifdoesntexist uninsdeletekey; Tasks: associate_aup
Root: HKCR; Subkey: "Audacity.Project\shell\open"; Flags: createvalueifdoesntexist uninsdeletekey; Tasks: associate_aup
Root: HKCR; Subkey: "Audacity.Project\shell\open\command"; ValueType: string; ValueData: """{app}\audacity.exe"" ""%1"""; Flags: createvalueifdoesntexist uninsdeletekey; Tasks: associate_aup

[Run]
Filename: "{app}\audacity.exe"; Description: "Launch Audacity"; Flags: nowait postinstall skipifsilent
