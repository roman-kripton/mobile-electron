'use strict';

const os = require('os');
const bindings = require('bindings');

exports.focusWindow = function focusWindow(window)
{
    const platform = os.platform();
    switch (platform)
    {
        case 'win32':
            bindings('focus').focusWindow(window.getNativeWindowHandle());
            break;

        default:
            window.setAlwaysOnTop(true);
            window.once("show", () => window.focus());
            window.show();
            window.setAlwaysOnTop(false);
            break;
    }
};
