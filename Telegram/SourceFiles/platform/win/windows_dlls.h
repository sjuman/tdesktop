/*
This file is part of Telegram Desktop,
the official desktop application for the Telegram messaging service.

For license and copyright information please follow this link:
https://github.com/telegramdesktop/tdesktop/blob/master/LEGAL
*/
#pragma once

#include <windows.h>
#include <shlobj.h>
#include <roapi.h>
#include <dwmapi.h>

namespace Platform {
namespace Dlls {

void init();

// KERNEL32.DLL
using f_SetDllDirectory = BOOL(FAR STDAPICALLTYPE*)(LPCWSTR lpPathName);
extern f_SetDllDirectory SetDllDirectory;

void start();

template <typename Function>
bool load(HINSTANCE library, LPCSTR name, Function &func) {
	if (!library) return false;

	func = reinterpret_cast<Function>(GetProcAddress(library, name));
	return (func != nullptr);
}

// UXTHEME.DLL
using f_SetWindowTheme = HRESULT(FAR STDAPICALLTYPE*)(HWND hWnd, LPCWSTR pszSubAppName, LPCWSTR pszSubIdList);
extern f_SetWindowTheme SetWindowTheme;

// SHELL32.DLL
using f_SHAssocEnumHandlers = HRESULT(FAR STDAPICALLTYPE*)(PCWSTR pszExtra, ASSOC_FILTER afFilter, IEnumAssocHandlers **ppEnumHandler);
extern f_SHAssocEnumHandlers SHAssocEnumHandlers;

using f_SHCreateItemFromParsingName = HRESULT(FAR STDAPICALLTYPE*)(PCWSTR pszPath, IBindCtx *pbc, REFIID riid, void **ppv);
extern f_SHCreateItemFromParsingName SHCreateItemFromParsingName;

using f_SHOpenWithDialog = HRESULT(FAR STDAPICALLTYPE*)(HWND hwndParent, const OPENASINFO *poainfo);
extern f_SHOpenWithDialog SHOpenWithDialog;

using f_OpenAs_RunDLL = HRESULT(FAR STDAPICALLTYPE*)(HWND hWnd, HINSTANCE hInstance, LPCWSTR lpszCmdLine, int nCmdShow);
extern f_OpenAs_RunDLL OpenAs_RunDLL;

using f_SHQueryUserNotificationState = HRESULT(FAR STDAPICALLTYPE*)(QUERY_USER_NOTIFICATION_STATE *pquns);
extern f_SHQueryUserNotificationState SHQueryUserNotificationState;

using f_SHChangeNotify = void(FAR STDAPICALLTYPE*)(LONG wEventId, UINT uFlags, __in_opt LPCVOID dwItem1, __in_opt LPCVOID dwItem2);
extern f_SHChangeNotify SHChangeNotify;

using f_SetCurrentProcessExplicitAppUserModelID = HRESULT(FAR STDAPICALLTYPE*)(__in PCWSTR AppID);
extern f_SetCurrentProcessExplicitAppUserModelID SetCurrentProcessExplicitAppUserModelID;

// WTSAPI32.DLL

using f_WTSRegisterSessionNotification = BOOL(FAR STDAPICALLTYPE*)(HWND hWnd, DWORD dwFlags);
extern f_WTSRegisterSessionNotification WTSRegisterSessionNotification;

using f_WTSUnRegisterSessionNotification = BOOL(FAR STDAPICALLTYPE*)(HWND hWnd);
extern f_WTSUnRegisterSessionNotification WTSUnRegisterSessionNotification;

// PROPSYS.DLL

using f_PropVariantToString = HRESULT(FAR STDAPICALLTYPE*)(_In_ REFPROPVARIANT propvar, _Out_writes_(cch) PWSTR psz, _In_ UINT cch);
extern f_PropVariantToString PropVariantToString;

using f_PSStringFromPropertyKey = HRESULT(FAR STDAPICALLTYPE*)(_In_ REFPROPERTYKEY pkey, _Out_writes_(cch) LPWSTR psz, _In_ UINT cch);
extern f_PSStringFromPropertyKey PSStringFromPropertyKey;

// COMBASE.DLL

using f_RoGetActivationFactory = HRESULT(FAR STDAPICALLTYPE*)(_In_ HSTRING activatableClassId, _In_ REFIID iid, _COM_Outptr_ void ** factory);
extern f_RoGetActivationFactory RoGetActivationFactory;

using f_WindowsCreateStringReference = HRESULT(FAR STDAPICALLTYPE*)(_In_reads_opt_(length + 1) PCWSTR sourceString, UINT32 length, _Out_ HSTRING_HEADER * hstringHeader, _Outptr_result_maybenull_ _Result_nullonfailure_ HSTRING * string);
extern f_WindowsCreateStringReference WindowsCreateStringReference;

using f_WindowsDeleteString = HRESULT(FAR STDAPICALLTYPE*)(_In_opt_ HSTRING string);
extern f_WindowsDeleteString WindowsDeleteString;

// DWMAPI.DLL

using f_DwmIsCompositionEnabled = HRESULT(FAR STDAPICALLTYPE*)(_Out_ BOOL* pfEnabled);
extern f_DwmIsCompositionEnabled DwmIsCompositionEnabled;

} // namespace Dlls
} // namespace Platform
