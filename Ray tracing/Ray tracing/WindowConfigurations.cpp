#include<Windows.h>

LRESULT CALLBACK SoftwareMainProcedure(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp);
WNDCLASS NewWindowClass(HBRUSH BGColor, HCURSOR Cursor, HINSTANCE hInst, HICON Icon, LPCWSTR Name, WNDPROC Procedure);

HBRUSH hBrush = CreateSolidBrush(RGB(255, 0, 0));
int i = 0;

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR args, int ncmdshow) {

	WNDCLASS SoftwareMainClass = NewWindowClass((HBRUSH)COLOR_WINDOW, LoadCursor(NULL, IDC_ARROW), hInst, LoadIcon(NULL, IDI_QUESTION),
		L"MainWndClass", SoftwareMainProcedure);

	if (!RegisterClassW(&SoftwareMainClass)) { return -1; };
	MSG SoftwareMainMessage = { 0 };


	CreateWindow(L"MainWndClass", L"First c++ window", WS_OVERLAPPEDWINDOW | WS_VISIBLE, 100, 100, 500, 250, NULL, NULL, NULL, NULL);

	while (GetMessage(&SoftwareMainMessage, NULL, NULL, NULL)) {
		TranslateMessage(&SoftwareMainMessage);
		//RedrawWindow()
		DispatchMessage(&SoftwareMainMessage);
	}
	return 0;
}

WNDCLASS NewWindowClass(HBRUSH BGColor, HCURSOR Cursor, HINSTANCE hInst, HICON Icon, LPCWSTR Name, WNDPROC Procedure) {
	WNDCLASS NWC = { 0 };

	NWC.hIcon = Icon;
	NWC.hCursor = Cursor;
	NWC.hInstance = hInst;
	NWC.lpszClassName = Name;
	NWC.hbrBackground = BGColor;
	NWC.lpfnWndProc = Procedure;

	return NWC;
}


LRESULT CALLBACK SoftwareMainProcedure(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp) {
	PAINTSTRUCT ps;

	RedrawWindow(hWnd, &ps.rcPaint, NULL, NULL);
	switch (msg) {
	case WM_CREATE:
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	/*case WM_PAINT:
		PAINTSTRUCT ps;
		BeginPaint(hWnd, &ps);
		while () {
			hBrush = CreateSolidBrush(RGB(i, 0, 0));
			FillRect(ps.hdc, &ps.rcPaint, hBrush);
			i = (i + 1) % 256;
			Sleep(1);
		}

		EndPaint(hWnd, &ps);*/
	default: return DefWindowProc(hWnd, msg, wp, lp);
	}
	return 0;
}