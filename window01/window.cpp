#include "afxwin.h"

class CMyWindow : public CFrameWnd {
public:
    CMyWindow() {
        RECT myRect;
        myRect.left = 0;
        myRect.right = 800;
        myRect.top = 0;
        myRect.bottom = 600;

        Create(NULL, "Пример MFC окна", WS_OVERLAPPEDWINDOW, myRect, nullptr, nullptr, WS_EX_WINDOWEDGE, nullptr);

        myButton.Create("Okay", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, CRect(10, 10, 100, 40), this, 1);
        myStatic.Create("This is static text", WS_CHILD | WS_VISIBLE, CRect(10, 50, 100, 70), this, 2);
        editBox.Create(WS_VISIBLE | WS_CHILD | WS_BORDER | ES_LEFT | ES_AUTOHSCROLL, CRect(10, 80 + 10, 200, 80 + 30), this, 3);
    }

protected:
    afx_msg void OnButtonClicked() {
        CString text;
        editBox.GetWindowText(text);
        int a = 0, b = 0, c = 0;

        for (int i = 0; i < text.GetLength(); i++)
        {
            if (text.GetAt(i) =='}')
            {
                a++;
            }
            else if (text.GetAt(i) == '{')
            {
                b++;
            }
            else
            {
                c++;
            }
        }
        if (a != 0 && a==b && c == 0) 
        {
            MessageBox("открывающие скобки равно к закрывающим скобкам","My code", MB_ICONERROR);
        }
        else if (a > b && c == 0)
        {
            MessageBox("открывающие скобки меньше закрывающих скобок", "My code", MB_ICONERROR);
        }
        else if (b > a && c == 0)
        {
            MessageBox("открывающие скобки больше закрывающих скобок", "My code", MB_ICONERROR);
        }
        else if (c > 0)
        {
            MessageBox("В тексте содержется не корректноый символ", "My code", MB_ICONERROR);
        }
    }

    DECLARE_MESSAGE_MAP();
private:
    CButton myButton;
    CStatic myStatic;
    CEdit editBox;
};

BEGIN_MESSAGE_MAP(CMyWindow, CFrameWnd)
    ON_BN_CLICKED(1, &CMyWindow::OnButtonClicked)
END_MESSAGE_MAP()

class CMyApp : public CWinApp {
public:
    virtual BOOL InitInstance() {
        m_pMainWnd = new CMyWindow();
        m_pMainWnd->ShowWindow(SW_SHOW);
        m_pMainWnd->UpdateWindow();

        return TRUE;
    }
};

CMyApp myApplication;

