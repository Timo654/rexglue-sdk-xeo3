/**
 ******************************************************************************
 * Xenia : Xbox 360 Emulator Research Project                                 *
 ******************************************************************************
 * Copyright 2022 Ben Vanik. All rights reserved.                             *
 * Released under the BSD license - see LICENSE in the root for more details. *
 ******************************************************************************
 *
 * @modified    Tom Clay, 2026 - Adapted for ReXGlue runtime
 */

// Disable warnings about unused parameters for kernel functions
#pragma GCC diagnostic ignored "-Wunused-parameter"

#include <rex/kernel/xboxkrnl/private.h>
#include <rex/logging.h>
#include <rex/hook.h>
#include <rex/types.h>
#include <rex/system/kernel_state.h>
#include <rex/system/xtypes.h>

namespace rex::kernel::xboxkrnl {

u32 HidReadKeys_entry(u32 unk1, u32 unk2, u32 unk3) {
  /* TODO(gibbed):
   * Games check for the following errors:
   *   0xC000009D - translated to 0x48F  - ERROR_DEVICE_NOT_CONNECTED
   *   0x103      - translated to 0x10D2 - ERROR_EMPTY
   * Other errors appear to be ignored?
   *
   * unk1 is 0
   * unk2 is a pointer to &unk3[2], possibly a 6-byte buffer
   * unk3 is a pointer to a 20-byte buffer
   */
  return 0xC000009D;
}

u32 HidGetCapabilities_entry(u32 unk1, u32 caps_ptr) {
  // HidGetCapabilities - ordinal 0x01EA
  // Returns capabilities for HID device (keyboard/mouse)
  // Not supported in rexglue - return unsuccessful
  return X_STATUS_UNSUCCESSFUL;
}

u32 HidGetLastInputTime_entry(mapped_u32 time_ptr) {
  // HidGetLastInputTime - ordinal 0x01F1
  // Returns the last time any HID input was received
  if (time_ptr) {
    *time_ptr = 0;
  }
  return X_STATUS_SUCCESS;
}

u32 HidReadMouseChanges_entry(u32 unk1, u32 unk2) {
  // HidReadMouseChanges - ordinal 0x0273
  // Reads mouse input changes - not supported in rexglue
  return X_STATUS_UNSUCCESSFUL;
}

}  // namespace rex::kernel::xboxkrnl

REX_EXPORT(__import__HidReadKeys, rex::kernel::xboxkrnl::HidReadKeys_entry)
REX_EXPORT(__import__HidGetCapabilities, rex::kernel::xboxkrnl::HidGetCapabilities_entry)
REX_EXPORT(__import__HidGetLastInputTime, rex::kernel::xboxkrnl::HidGetLastInputTime_entry)
REX_EXPORT(__import__HidReadMouseChanges, rex::kernel::xboxkrnl::HidReadMouseChanges_entry)

// XInputd stubs
REX_EXPORT_STUB(__import__XInputdGetCapabilities);
REX_EXPORT_STUB(__import__XInputdReadState);
REX_EXPORT_STUB(__import__XInputdWriteState);
REX_EXPORT_STUB(__import__XInputdNotify);
REX_EXPORT_STUB(__import__XInputdRawState);
REX_EXPORT_STUB(__import__XInputdGetDeviceStats);
REX_EXPORT_STUB(__import__XInputdResetDevice);
REX_EXPORT_STUB(__import__XInputdSetRingOfLight);
REX_EXPORT_STUB(__import__XInputdSetRFPowerMode);
REX_EXPORT_STUB(__import__XInputdSetRadioFrequency);
REX_EXPORT_STUB(__import__XInputdPassThroughRFCommand);
REX_EXPORT_STUB(__import__XInputdPowerDownDevice);
REX_EXPORT_STUB(__import__XInputdReadTextKeystroke);
REX_EXPORT_STUB(__import__XInputdSendStayAliveRequest);
REX_EXPORT_STUB(__import__XInputdFFGetDeviceInfo);
REX_EXPORT_STUB(__import__XInputdFFSetEffect);
REX_EXPORT_STUB(__import__XInputdFFUpdateEffect);
REX_EXPORT_STUB(__import__XInputdFFEffectOperation);
REX_EXPORT_STUB(__import__XInputdFFDeviceControl);
REX_EXPORT_STUB(__import__XInputdFFSetDeviceGain);
REX_EXPORT_STUB(__import__XInputdFFCancelIo);
REX_EXPORT_STUB(__import__XInputdFFSetRumble);
REX_EXPORT_STUB(__import__XInputdGetLastTextInputTime);
REX_EXPORT_STUB(__import__XInputdSetTextMessengerIndicator);
REX_EXPORT_STUB(__import__XInputdSetTextDeviceKeyLocks);
REX_EXPORT_STUB(__import__XInputdGetTextDeviceKeyLocks);
REX_EXPORT_STUB(__import__XInputdControl);
REX_EXPORT_STUB(__import__XInputdSetWifiChannel);
REX_EXPORT_STUB(__import__XInputdGetDevicePid);
REX_EXPORT_STUB(__import__XInputdGetFailedConnectionOrBind);
REX_EXPORT_STUB(__import__XInputdSetFailedConnectionOrBindCallback);
REX_EXPORT_STUB(__import__XInputdSetMinMaxAuthDelay);

// Drv stubs
REX_EXPORT_STUB(__import__DrvSetSysReqCallback);
REX_EXPORT_STUB(__import__DrvSetUserBindingCallback);
REX_EXPORT_STUB(__import__DrvSetContentStorageCallback);
REX_EXPORT_STUB(__import__DrvSetAutobind);
REX_EXPORT_STUB(__import__DrvGetContentStorageNotification);
REX_EXPORT_STUB(__import__DrvXenonButtonPressed);
REX_EXPORT_STUB(__import__DrvBindToUser);
REX_EXPORT_STUB(__import__DrvSetDeviceConfigChangeCallback);
REX_EXPORT_STUB(__import__DrvDeviceConfigChange);
REX_EXPORT_STUB(__import__DrvSetMicArrayStartCallback);
REX_EXPORT_STUB(__import__DrvSetAudioLatencyCallback);
