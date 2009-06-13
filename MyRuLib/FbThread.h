#ifndef __FBTHREAD_H__
#define __FBTHREAD_H__

#include <wx/wx.h>

class FbThread : public wxThread
{
public:
    static void MakeUpper(wxString & data);
    static void MakeLower(wxString & data);
public:
    FbThread(wxEvtHandler *frame, const wxString &filename);

    // thread execution starts here
    virtual void *Entry();

    // called when the thread exits - whether it terminates normally or is
    // stopped with Delete() (but not when it is Kill()ed!)
    virtual void OnExit();
	static int FindAuthor(wxString &full_name);
	static int FindSequence(wxString &name);
	static bool ParseXml(wxInputStream& stream, const wxString &name, const wxFileOffset size, int id_archive);
    int AddArchive();
private:
	static int NewId(int param);
private:
    unsigned m_count;
    wxString m_filename;
    wxEvtHandler *m_frame;
};

#endif // __FBTHREAD_H__