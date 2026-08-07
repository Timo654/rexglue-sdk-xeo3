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

void HalReturnToFirmware_entry(u32 routine) {
  // void
  // IN FIRMWARE_REENTRY  Routine

  // Routine must be 1 'HalRebootRoutine'
  assert_true(routine == 1);

  // TODO(benvank): diediedie much more gracefully
  // Not sure how to blast back up the stack in LLVM without exceptions, though.
  REXKRNL_ERROR("Game requested shutdown via HalReturnToFirmware");
  exit(0);
}

}  // namespace rex::kernel::xboxkrnl

REX_EXPORT(__import__HalReturnToFirmware, rex::kernel::xboxkrnl::HalReturnToFirmware_entry)

REX_EXPORT_STUB(__import__HalGetCurrentAVPack);
REX_EXPORT_STUB(__import__HalGpioControl);
REX_EXPORT_STUB(__import__HalOpenCloseODDTray);
REX_EXPORT_STUB(__import__HalReadWritePCISpace);
REX_EXPORT_STUB(__import__HalRegisterPowerDownNotification);
REX_EXPORT_STUB(__import__HalRegisterSMCNotification);
REX_EXPORT_STUB(__import__HalSendSMCMessage);
REX_EXPORT_STUB(__import__HalSetAudioEnable);
REX_EXPORT_STUB(__import__HalIsExecutingPowerDownDpc);
REX_EXPORT_STUB(__import__HalGetPowerUpCause);
REX_EXPORT_STUB(__import__HalRegisterPowerDownCallback);
REX_EXPORT_STUB(__import__HalRegisterBackgroundModeTransitionCallback);
REX_EXPORT_STUB(__import__HalClampUnclampOutputDACs);
REX_EXPORT_STUB(__import__HalPowerDownToBackgroundMode);
REX_EXPORT_STUB(__import__HalNotifyAddRemoveBackgroundTask);
REX_EXPORT_STUB(__import__HalCallBackgroundModeNotificationRoutines);
REX_EXPORT_STUB(__import__HalGetMemoryInformation);
REX_EXPORT_STUB(__import__HalNotifyBackgroundModeTransitionComplete);
REX_EXPORT_STUB(__import__HalFinalizePowerLossRecovery);
REX_EXPORT_STUB(__import__HalSetPowerLossRecovery);
REX_EXPORT_STUB(__import__HalRegisterXamPowerDownCallback);
REX_EXPORT_STUB(__import__HalRegisterHdDvdRomNotification);
REX_EXPORT_STUB(__import__HalGetNotedArgonErrors);
REX_EXPORT_STUB(__import__HalReadArgonEeprom);
REX_EXPORT_STUB(__import__HalWriteArgonEeprom);
REX_EXPORT_STUB(__import__HalConfigureVeDevice);
