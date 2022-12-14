/***************************************************************
 * Name:      wxDateCalcMain.h
 * Purpose:   Defines Application Frame
 * Author:    Giulio Sorrentino (gsorre84@gmail.com)
 * Created:   2022-12-14
 * Copyright: Giulio Sorrentino (https://numerone.altervista.org)
 * License:
 **************************************************************/

#ifndef WXDATECALCMAIN_H
#define WXDATECALCMAIN_H

#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif
#include <wx/calctrl.h>
#include <wx/aboutdlg.h>
#include <wx/config.h>
#include <wx/datetime.h>
#include <wx/utils.h> 
#include <wx/notifmsg.h>

#include "wxDateCalcApp.h"
#include "background.xpm"

class wxDateCalcFrame: public wxFrame
{
    public:
        wxDateCalcFrame(wxFrame *frame, const wxString& title);
        ~wxDateCalcFrame();
    private:
        enum
        {
            idMenuQuit = 1000,
            idMenuAbout,
            ID_BUTTON_OK
        };
        void OnClose(wxCloseEvent& event);
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnOk(wxCommandEvent &evt);
        void OnPaint(wxPaintEvent &evt);
        void salvaData();

        wxCalendarCtrl  *calendar;
        wxButton *calcola;
        wxImage *img;
        wxConfig *config;
        wxDateTime data;
        DECLARE_EVENT_TABLE()
};


#endif // WXDATECALCMAIN_H
