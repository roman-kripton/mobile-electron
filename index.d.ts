////////////////////////////////////////////////////////////////////////////////
//
// Author - Вячеслав И. Э.
// Date - 21 май 2025
//
////////////////////////////////////////////////////////////////////////////////

///<reference path='node_modules/electron/electron.d.ts'/>

import BrowserWindow = Electron.CrossProcessExports.BrowserWindow;

/**
 * Активирует окно и возвращает фокус приложению
 * @param window
 */
export function focusWindow(window:BrowserWindow):void;