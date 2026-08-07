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

#include <rex/kernel/xam/private.h>
#include <rex/logging.h>
#include <rex/hook.h>
#include <rex/types.h>
#include <rex/system/kernel_state.h>
#include <rex/system/xtypes.h>

namespace rex {
namespace kernel {
namespace xam {

u32 XamVoiceIsActiveProcess_entry() {
  // Returning 0 here will short-circuit a bunch of voice stuff.
  return 0;
}

u32 XamVoiceCreate_entry(u32 unk1,  // 0
                         u32 unk2,  // 0xF
                         mapped_u32 out_voice_ptr) {
  // Null out the ptr.
  out_voice_ptr.Zero();
  return X_ERROR_ACCESS_DENIED;
}

u32 XamVoiceClose_entry(mapped_void voice_ptr) {
  return 0;
}

u32 XamVoiceHeadsetPresent_entry(mapped_void voice_ptr) {
  return 0;
}

}  // namespace xam
}  // namespace kernel
}  // namespace rex

REX_EXPORT(__import__XamVoiceIsActiveProcess, rex::kernel::xam::XamVoiceIsActiveProcess_entry)
REX_EXPORT(__import__XamVoiceCreate, rex::kernel::xam::XamVoiceCreate_entry)
REX_EXPORT(__import__XamVoiceClose, rex::kernel::xam::XamVoiceClose_entry)
REX_EXPORT(__import__XamVoiceHeadsetPresent, rex::kernel::xam::XamVoiceHeadsetPresent_entry)

REX_EXPORT_STUB(__import__XamMuteSound);
REX_EXPORT_STUB(__import__XamVoiceDisableMicArray);
REX_EXPORT_STUB(__import__XamVoiceGetBatteryStatus);
REX_EXPORT_STUB(__import__XamVoiceGetDirectionalData);
REX_EXPORT_STUB(__import__XamVoiceGetMicArrayAudio);
REX_EXPORT_STUB(__import__XamVoiceGetMicArrayAudioEx);
REX_EXPORT_STUB(__import__XamVoiceGetMicArrayFilenameDesc);
REX_EXPORT_STUB(__import__XamVoiceGetMicArrayStatus);
REX_EXPORT_STUB(__import__XamVoiceGetMicArrayUnderrunStatus);
REX_EXPORT_STUB(__import__XamVoiceMuteMicArray);
REX_EXPORT_STUB(__import__XamVoiceRecordUserPrivileges);
REX_EXPORT_STUB(__import__XamVoiceSetAudioCaptureRoutine);
REX_EXPORT_STUB(__import__XamVoiceSetMicArrayBeamAngle);
REX_EXPORT_STUB(__import__XamVoiceSetMicArrayIdleUsers);
REX_EXPORT_STUB(__import__XamVoiceSubmitPacket);
