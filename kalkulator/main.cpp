#if defined(UNICODE) && !defined(_UNICODE)
    #define _UNICODE
#elif defined(_UNICODE) && !defined(UNICODE)
    #define UNICODE
#endif

#include <tchar.h>
#include <windows.h>
#include <stdio.h>
#include <string>
#include <iostream>

LRESULT CALLBACK WindowProcedure (HWND, UINT, WPARAM, LPARAM);


HINSTANCE hInst;
HWND statyczna1;
char charowiec[256];
std::string stringer;
std::string l1;
std::string l2;
int liczba=1;
int reset;
double a;
double b;
double wynik;
int dzialanie;

TCHAR szClassName[ ] = _T("Kalkulator");

int WINAPI WinMain (HINSTANCE hThisInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR lpszArgument,
                     int nCmdShow)
{
    HWND hwnd;
    MSG messages;
    WNDCLASSEX wincl;

    wincl.hInstance = hThisInstance;
    wincl.lpszClassName = szClassName;
    wincl.lpfnWndProc = WindowProcedure;
    wincl.style = CS_DBLCLKS;
    wincl.cbSize = sizeof (WNDCLASSEX);

    wincl.hIcon = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hIconSm = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hCursor = LoadCursor (NULL, IDC_ARROW);
    wincl.lpszMenuName = NULL;
    wincl.cbClsExtra = 0;
    wincl.cbWndExtra = 0;
    wincl.hbrBackground = (HBRUSH) COLOR_BACKGROUND;

    if (!RegisterClassEx (&wincl))
        return 0;

    hwnd = CreateWindowEx (
           0,
           szClassName,
           _T("Kalkulator"),
           WS_OVERLAPPEDWINDOW,
           CW_USEDEFAULT,
           CW_USEDEFAULT,
           544,
           375,
           HWND_DESKTOP,
           NULL,
           hThisInstance,
           NULL
           );


    HWND edit1;
    HWND edit2;
    HWND button1;
    HWND button2;
    HWND button3;
    HWND button4;
    HWND button5;
    HWND button6;
    HWND button7;
    HWND button8;
    HWND button9;
    HWND button0;
    HWND buttonplus;
    HWND buttonminus;
    HWND buttonmnoz;
    HWND buttondziel;
    HWND buttonlicz;
    HWND buttonclear;

    #define ID_BUTTON1 101
    #define ID_BUTTON2 102
    #define ID_BUTTON3 103
    #define ID_BUTTON4 104
    #define ID_BUTTON5 105
    #define ID_BUTTON6 106
    #define ID_BUTTON7 107
    #define ID_BUTTON8 108
    #define ID_BUTTON9 109
    #define ID_BUTTON0 100

    #define ID_BUTTONPLUS 201
    #define ID_BUTTONMINUS 202
    #define ID_BUTTONMNOZ 203
    #define ID_BUTTONDZIEL 204

    #define ID_BUTTONLICZ 205
    #define ID_BUTTONCLEAR 206

    hInst = hThisInstance;


    button1 = CreateWindowEx(NULL,"BUTTON","1",WS_CHILD|WS_VISIBLE,50,100,50,50,hwnd,(HMENU)ID_BUTTON1,hThisInstance,NULL);
    button2 = CreateWindowEx(NULL,"BUTTON","2",WS_CHILD|WS_VISIBLE,101,100,50,50,hwnd,(HMENU)ID_BUTTON2,hThisInstance,NULL);
    button3 = CreateWindowEx(NULL,"BUTTON","3",WS_CHILD|WS_VISIBLE,152,100,50,50,hwnd,(HMENU)ID_BUTTON3,hThisInstance,NULL);
    button4 = CreateWindowEx(NULL,"BUTTON","4",WS_CHILD|WS_VISIBLE,50,151,50,50,hwnd,(HMENU)ID_BUTTON4,hThisInstance,NULL);
    button5 = CreateWindowEx(NULL,"BUTTON","5",WS_CHILD|WS_VISIBLE,101,151,50,50,hwnd,(HMENU)ID_BUTTON5,hThisInstance,NULL);
    button6 = CreateWindowEx(NULL,"BUTTON","6",WS_CHILD|WS_VISIBLE,152,151,50,50,hwnd,(HMENU)ID_BUTTON6,hThisInstance,NULL);
    button7 = CreateWindowEx(NULL,"BUTTON","7",WS_CHILD|WS_VISIBLE,50,202,50,50,hwnd,(HMENU)ID_BUTTON7,hThisInstance,NULL);
    button8 = CreateWindowEx(NULL,"BUTTON","8",WS_CHILD|WS_VISIBLE,101,202,50,50,hwnd,(HMENU)ID_BUTTON8,hThisInstance,NULL);
    button9 = CreateWindowEx(NULL,"BUTTON","9",WS_CHILD|WS_VISIBLE,152,202,50,50,hwnd,(HMENU)ID_BUTTON9,hThisInstance,NULL);
    button0 = CreateWindowEx(NULL,"BUTTON","0",WS_CHILD|WS_VISIBLE,101,253,50,50,hwnd,(HMENU)ID_BUTTON0,hThisInstance,NULL);

    buttonplus = CreateWindowEx(NULL,"BUTTON","+",WS_CHILD|WS_VISIBLE,203,100,50,50,hwnd,(HMENU)ID_BUTTONPLUS,hThisInstance,NULL);
    buttonminus = CreateWindowEx(NULL,"BUTTON","-",WS_CHILD|WS_VISIBLE,203,151,50,50,hwnd,(HMENU)ID_BUTTONMINUS,hThisInstance,NULL);
    buttonmnoz = CreateWindowEx(NULL,"BUTTON","*",WS_CHILD|WS_VISIBLE,203,202,50,50,hwnd,(HMENU)ID_BUTTONMNOZ,hThisInstance,NULL);
    buttondziel = CreateWindowEx(NULL,"BUTTON","/",WS_CHILD|WS_VISIBLE,203,253,50,50,hwnd,(HMENU)ID_BUTTONDZIEL,hThisInstance,NULL);

    buttonlicz = CreateWindowEx(NULL,"BUTTON","=",WS_CHILD|WS_VISIBLE,152,253,50,50,hwnd,(HMENU)ID_BUTTONLICZ,hThisInstance,NULL);
    buttonclear = CreateWindowEx(NULL,"BUTTON","C",WS_CHILD|WS_VISIBLE,50,253,50,50,hwnd,(HMENU)ID_BUTTONCLEAR,hThisInstance,NULL);

    statyczna1 = CreateWindowEx(NULL,"STATIC",NULL,WS_CHILD|WS_VISIBLE|SS_CENTER,50,45,200,40,hwnd,NULL,hInst,NULL);
    ShowWindow (hwnd, nCmdShow);

    while (GetMessage (&messages, NULL, 0, 0))
    {
        TranslateMessage(&messages);
        DispatchMessage(&messages);
    }

    return messages.wParam;
}

double oblicz(std::string l1, std::string l2, int dzialanie) {
    double wynik;
    a = atoi(l1.c_str());
    b = atoi(l2.c_str());
    if(dzialanie==1) {
        wynik=a+b;
    } else if(dzialanie==2) {
        wynik=a-b;
    } else if(dzialanie==3) {
        wynik=a*b;
    } else if(dzialanie==4) {
        wynik=a/b;
    } else {
        wynik=10020;
    }
    return wynik;
}


LRESULT CALLBACK WindowProcedure (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
        case WM_DESTROY:
            PostQuitMessage (0);
            break;
        case WM_COMMAND:
            switch(wParam) {
                case ID_BUTTON1:
                    if(reset==1) {
                        stringer = "";
                        reset=0;
                    }
                    if(liczba==1) {
                        l1=l1+"1";
                    } else if(liczba==2) {
                        l2=l2+"1";
                    }
                    stringer = stringer+"1";
                    SetWindowText(statyczna1, stringer.data());
                    break;
                case 102:
                    if(reset==1) {
                        stringer = "";
                        reset=0;
                    }
                    if(liczba==1) {
                        l1=l1+"2";
                    } else if(liczba==2) {
                        l2=l2+"2";
                    }
                    stringer = stringer+"2";
                    SetWindowText(statyczna1, stringer.data());
                    break;
                case 103:
                    if(reset==1) {
                        stringer = "";
                        reset=0;
                    }
                    if(liczba==1) {
                        l1=l1+"3";
                    } else if(liczba==2) {
                        l2=l2+"3";
                    }
                    stringer = stringer+"3";
                    SetWindowText(statyczna1, stringer.data());
                    break;
                case 104:
                    if(reset==1) {
                        stringer = "";
                        reset=0;
                    }
                    if(liczba==1) {
                        l1=l1+"4";
                    } else if(liczba==2) {
                        l2=l2+"4";
                    }
                    stringer = stringer+"4";
                    SetWindowText(statyczna1, stringer.data());
                    break;
                case 105:
                    if(reset==1) {
                        stringer = "";
                        reset=0;
                    }
                    if(liczba==1) {
                        l1=l1+"5";
                    } else if(liczba==2) {
                        l2=l2+"5";
                    }
                    stringer = stringer+"5";
                    SetWindowText(statyczna1, stringer.data());
                    break;
                case 106:
                    if(reset==1) {
                        stringer = "";
                        reset=0;
                    }
                    if(liczba==1) {
                        l1=l1+"6";
                    } else if(liczba==2) {
                        l2=l2+"6";
                    }
                    stringer = stringer+"6";
                    SetWindowText(statyczna1, stringer.data());
                    break;
                case 107:
                    if(reset==1) {
                        stringer = "";
                        reset=0;
                    }
                    if(liczba==1) {
                        l1=l1+"7";
                    } else if(liczba==2) {
                        l2=l2+"7";
                    }
                    stringer = stringer+"7";
                    SetWindowText(statyczna1, stringer.data());
                    break;
                case 108:
                    if(reset==1) {
                        stringer = "";
                        reset=0;
                    }
                    if(liczba==1) {
                        l1=l1+"8";
                    } else if(liczba==2) {
                        l2=l2+"8";
                    }
                    stringer = stringer+"8";
                    SetWindowText(statyczna1, stringer.data());
                    break;
                case 109:
                    if(reset==1) {
                        stringer = "";
                        reset=0;
                    }
                    if(liczba==1) {
                        l1=l1+"9";
                    } else if(liczba==2) {
                        l2=l2+"9";
                    }
                    stringer = stringer+"9";
                    SetWindowText(statyczna1, stringer.data());
                    break;
                case 100:
                    if(reset==1) {
                        stringer = "";
                        reset=0;
                    }
                    if(liczba==1) {
                        l1=l1+"0";
                    } else if(liczba==2) {
                        l2=l2+"0";
                    }
                    stringer = stringer+"0";
                    SetWindowText(statyczna1, stringer.data());
                    break;
                case 201:
                    liczba++;
                    reset=0;
                    if(liczba>=3) {
                        wynik = oblicz(l1,l2,dzialanie);
                        l2="";
                        stringer = std::to_string(wynik);
                        l1=stringer;
                    }
                    liczba=2;
                    dzialanie=1;
                    stringer = stringer+"+";
                    SetWindowText(statyczna1, stringer.data());
                    break;
                case 202:
                    liczba++;
                    reset=0;
                    if(liczba>=3) {
                        wynik = oblicz(l1,l2,dzialanie);
                        l2="";
                        stringer = std::to_string(wynik);
                        l1=stringer;
                    }
                    liczba=2;
                    dzialanie=2;
                    stringer = stringer+"-";
                    SetWindowText(statyczna1, stringer.data());
                    break;
                case 203:
                    liczba++;
                    reset=0;
                    if(liczba>=3) {
                        wynik = oblicz(l1,l2,dzialanie);
                        l2="";
                        stringer = std::to_string(wynik);
                        l1=stringer;
                    }
                    liczba=2;
                    dzialanie=3;
                    stringer = stringer+"*";
                    SetWindowText(statyczna1, stringer.data());
                    break;
                case 204:
                    liczba++;
                    reset=0;
                    if(liczba>=3) {
                        wynik = oblicz(l1,l2,dzialanie);
                        l2="";
                        stringer = std::to_string(wynik);
                        l1=stringer;
                    }
                    liczba=2;
                    dzialanie=4;
                    stringer = stringer+"/";
                    SetWindowText(statyczna1, stringer.data());
                    break;
                case 205:
                    stringer="";
                    wynik = oblicz(l1,l2,dzialanie);
                    stringer = std::to_string(wynik);
                    SetWindowText(statyczna1, stringer.data());
                    reset=1;
                    wynik=0;
                    a=0;
                    b=0;
                    l1=stringer;
                    l2="";
                    liczba=1;
                    break;
                case 206:
                    stringer = "";
                    liczba=1;
                    wynik=0;
                    a=0;
                    b=0;
                    l1="";
                    l2="";
                    dzialanie = 0;
                    SetWindowText(statyczna1, stringer.data());
                    break;
            }

        default:
            return DefWindowProc (hwnd, message, wParam, lParam);
    }

    return 0;
}

