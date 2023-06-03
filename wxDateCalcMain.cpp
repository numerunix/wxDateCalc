/***************************************************************
 * Name:      wxDateCalcMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Giulio Sorrentino (gsorre84@gmail.com)
 * Created:   2022-12-14
 * Copyright: Giulio Sorrentino (https://numerone.altervista.org)
 * License:
 **************************************************************/

#ifdef WX_PRECOMP
#include "wx_pch.h"
#endif

#ifdef __BORLANDC__
#pragma hdrstop
#endif //__BORLANDC__

#include "wxDateCalcMain.h"

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__WXMAC__)
        wxbuild << _T("-Mac");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

BEGIN_EVENT_TABLE(wxDateCalcFrame, wxFrame)
    EVT_CLOSE(wxDateCalcFrame::OnClose)
    EVT_MENU(idMenuQuit, wxDateCalcFrame::OnQuit)
    EVT_MENU(idMenuAbout, wxDateCalcFrame::OnAbout)
    EVT_BUTTON(ID_BUTTON_OK, wxDateCalcFrame::OnOk)
    EVT_PAINT(wxDateCalcFrame::OnPaint)
END_EVENT_TABLE()

wxDateCalcFrame::wxDateCalcFrame(wxFrame *frame, const wxString& title)
    : wxFrame(frame, -1, title, wxDefaultPosition, wxSize(300,300))
{
#if wxUSE_MENUS
    // create a menu bar
    wxMenuBar* mbar = new wxMenuBar();
    wxMenu* fileMenu = new wxMenu(_T(""));
    fileMenu->Append(idMenuQuit, _("&Quit\tAlt-F4"), _("Quit the application"));
    mbar->Append(fileMenu, _("&File"));

    wxMenu* helpMenu = new wxMenu(_T(""));
    helpMenu->Append(idMenuAbout, _("&About\tF1"), _("Show info about this application"));
    mbar->Append(helpMenu, _("&Help"));

    SetMenuBar(mbar);
#endif // wxUSE_MENUS

#if wxUSE_STATUSBAR
    // create a status bar with some information about the used wxWidgets version
    CreateStatusBar(2);
    SetStatusText(_("Hello Code::Blocks user!"),0);
    SetStatusText(wxbuildinfo(short_f), 1);
#endif // wxUSE_STATUSBAR
    config=new wxConfig("wxDateCalc");
    int giorno, mese;
    int anno;
    if (!config->Read("day", &giorno))
        giorno=25;
    if (!config->Read("month", &mese))
        mese=11;
    if (!config->Read("year", &anno))
        anno=2022;
    data=wxDateTime(giorno, static_cast<wxDateTime::Month>(mese), anno);
    wxBoxSizer *vbox=new wxBoxSizer(wxVERTICAL);
    calendar=new wxCalendarCtrl(this, wxID_ANY);
    calendar->SetDate(data);
    vbox->Add(new wxStaticText(this, wxID_ANY, _("Insert the date: ")), 0, wxALL, 4);
    vbox->Add(calendar, 0, wxALL, 4);
    calcola=new wxButton(this, ID_BUTTON_OK, _("Calculate"));
    wxString s=wxFileName::GetPathSeparator();
    img=new wxImage(wxGetHomeDir()+s+_("Images")+s+wxT("background.jpg"));
    vbox->Add(calcola, 0, wxALL, 4);
    SetSizer(vbox);
    Layout();
    //Fit();

}


void wxDateCalcFrame::salvaData() {
    config->Write("day", data.GetDay());
    config->Write("month", static_cast<unsigned short>(data.GetMonth()));
    config->Write("year", static_cast<int>(data.GetYear()));
}

wxDateCalcFrame::~wxDateCalcFrame()
{
    salvaData();
    delete config;
    delete img;
}

void wxDateCalcFrame::OnClose(wxCloseEvent &event)
{
    Destroy();

}

void wxDateCalcFrame::OnQuit(wxCommandEvent &event)
{
    Destroy();
}

void wxDateCalcFrame::OnAbout(wxCommandEvent &event)
{
	wxAboutDialogInfo info;
	info.AddDeveloper("Giulio Sorrentino <gsorre84@gmail.com>");
	info.SetCopyright("(c) 2022 Giulio Sorrentino");
	info.SetLicense("GPL v3 o (a tua discrezione) qualsiasi versione successiva.");
	info.SetName("wxDateCalc");
        info.SetVersion("0.2");
	info.SetWebSite("https://github.com/numerunix/wxdatecalc");
    wxArrayString traduttori = wxArrayString();
    traduttori.Add("Giulio Sorrentino <gsorre84@gmail.com>");
    info.SetDescription(_("Un altro countdown in wxwidgets"));
    info.SetTranslators(traduttori);
    #ifndef _WIN32
        info.SetIcon(wxIcon(background_xpm));
    #endif
    wxAboutBox(info);
}

void wxDateCalcFrame::OnOk(wxCommandEvent &evt) {
    data=calendar->GetDate();
    wxDateTime t1=wxDateTime::Now();
    wxTimeSpan ts=data.Subtract(t1);
    if (ts.GetValue()<0) {
      wxNotificationMessage *msg = new wxNotificationMessage(_("Error"), _("Invalid lvalue"), this);
        msg->Show();
        delete msg;
        msg = NULL;
        return;
    }
    wxString giorni, ore, minuti;
    giorni.Printf("%d", ts.GetDays());
    ore.Printf("%d", ts.GetHours()%24);
    minuti.Printf("%d", ts.GetMinutes()%60);
    wxNotificationMessage *msg = new wxNotificationMessage(_("Information"), _("There are ")+giorni+_(" days, ")+ore+_(" hours and ")+minuti+_(" minutes left."), this);
    msg->Show();
    delete msg;
}


void wxDateCalcFrame::OnPaint(wxPaintEvent &evt) {
    wxPaintDC dc(this);
    wxCoord width, height;
   if (img->IsOk()) {
        wxImage img1=wxImage(*img);
        GetClientSize(&width, &height);
        img1.Rescale(width, height);
        dc.DrawBitmap(wxBitmap(img1), 0,0);
   }
}

