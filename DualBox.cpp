#include <iostream>
#include <windows.h>


using namespace std;

double fScreenWidth = ::GetSystemMetrics(SM_CXSCREEN) - 1;
double fScreenHeight = ::GetSystemMetrics(SM_CYSCREEN) - 1;

POINT p;
HHOOK mHook, kHook, wHook;
POINT logical;

void moveSlave(HWND &master, HWND &slave, POINT p);

int main()
{

	HWND hwnd = FindWindow(NULL, TEXT("Diablo III"));
	if (hwnd)
	{
		SetWindowText(hwnd, TEXT("master"));
	}
	hwnd = FindWindow(NULL, TEXT("Diablo III"));
	if (hwnd)
	{
		SetWindowText(hwnd, TEXT("slave"));
	}


	HWND master = FindWindow(NULL, TEXT("master"));
	HWND slave = FindWindow(NULL, TEXT("slave"));

	while (true)
	{
		if (GetAsyncKeyState(VK_LBUTTON))
		{
			GetCursorPos(&p);
			moveSlave(master, slave, p);
			SendMessage(slave, WM_KEYDOWN, 'R', 0);
			SendMessage(slave, WM_KEYUP, 'R', 0);
			SendMessage(master, WM_KEYDOWN, 'R', 0);
			SendMessage(master, WM_KEYUP, 'R', 0);
		}
		if (GetAsyncKeyState(VK_RBUTTON))
		{
			GetCursorPos(&p);
			SendMessage(slave, WM_RBUTTONDOWN, MK_RBUTTON, MAKELPARAM(p.x, p.y));
			SendMessage(slave, WM_RBUTTONUP, MK_RBUTTON, MAKELPARAM(p.x,p.y));
		}
		if (GetAsyncKeyState(0x51))
		{
			PostMessage(slave, WM_KEYDOWN, 'Q', 0);
			PostMessage(slave, WM_KEYUP, 'Q', 0);
		}
		if (GetAsyncKeyState(0x57))
		{
			PostMessage(slave, WM_KEYDOWN, 'W', 0);
			PostMessage(slave, WM_KEYUP, 'W', 0);
		}
		if (GetAsyncKeyState(0x45))
		{
			PostMessage(slave, WM_KEYDOWN, 'E', 0);
			PostMessage(slave, WM_KEYUP, 'E', 0);
		}
		if (GetAsyncKeyState(0x52))
		{
			PostMessage(slave, WM_KEYDOWN, 'R', 0);
			PostMessage(slave, WM_KEYUP, 'R', 0);
		}
		if (GetAsyncKeyState(0x54))
		{
			PostMessage(slave, WM_KEYDOWN, 'T', 0);
			PostMessage(slave, WM_KEYDOWN, 'T', 0);
			Sleep(1000);
		}

		Sleep(50);
	}

	return 0;
}

void moveSlave(HWND &master, HWND &slave, POINT p)
{
	ScreenToClient(master, &p);
	POINT slaveAbsoluteCoords;
	ClientToScreen(slave, &slaveAbsoluteCoords);
	cout << "\np.x: " << p.x << "\n" << "p.y: " << p.y;
	if (p.x < 930)
	{
		SendMessage(slave, WM_LBUTTONDOWN, MK_LBUTTON, MAKELPARAM(p.x, p.y));
		SendMessage(slave, WM_LBUTTONUP, MK_LBUTTON, MAKELPARAM(p.x, p.y));
	}
}