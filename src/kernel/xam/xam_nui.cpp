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

#include <rex/logging.h>
#include <rex/hook.h>
#include <rex/runtime.h>
#include <rex/system/flags.h>
#include <rex/system/kernel_state.h>

namespace rex {
namespace kernel {
namespace xam {

extern std::atomic<int> xam_dialogs_shown_;

struct X_NUI_DEVICE_STATUS {
  rex::be<uint32_t> unk0;
  rex::be<uint32_t> unk1;
  rex::be<uint32_t> unk2;
  rex::be<uint32_t> status;
  rex::be<uint32_t> unk4;
  rex::be<uint32_t> unk5;
};
static_assert(sizeof(X_NUI_DEVICE_STATUS) == 24, "Size matters");

void XamNuiGetDeviceStatus_entry(ppc_ptr_t<X_NUI_DEVICE_STATUS> status_ptr) {
  status_ptr.Zero();
  status_ptr->status = 0;  // Not connected.
}

u32 XamShowNuiTroubleshooterUI_entry(u32 unk1, u32 unk2, u32 unk3) {
  // unk1 is 0xFF - possibly user index?
  // unk2, unk3 appear to always be zero.

  if (REXCVAR_GET(headless)) {
    return 0;
  }
  // TODO(tomc): Implement imgui stuff
  // const Runtime* emulator = REX_KERNEL_STATE()->emulator();
  // ui::Window* display_window = emulator->display_window();
  // ui::ImGuiDrawer* imgui_drawer = emulator->imgui_drawer();
  // if (display_window && imgui_drawer) {
  //  rex::thread::Fence fence;
  //  if (display_window->app_context().CallInUIThreadSynchronous([&]() {
  //        rex::ui::ImGuiDialog::ShowMessageBox(
  //            imgui_drawer, "NUI Troubleshooter",
  //            "The game has indicated there is a problem with NUI (Kinect).")
  //            ->Then(&fence);
  //      })) {
  //    ++xam_dialogs_shown_;
  //    fence.Wait();
  //    --xam_dialogs_shown_;
  //  }
  //}

  return 0;
}

}  // namespace xam
}  // namespace kernel
}  // namespace rex

REX_EXPORT(__import__XamNuiGetDeviceStatus, rex::kernel::xam::XamNuiGetDeviceStatus_entry)
REX_EXPORT(__import__XamShowNuiTroubleshooterUI, rex::kernel::xam::XamShowNuiTroubleshooterUI_entry)

REX_EXPORT_STUB(__import__XamEnableNatalPlayback);
REX_EXPORT_STUB(__import__XamEnableNuiAutomation);
REX_EXPORT_STUB(__import__XamKinectGetHardwareType);
REX_EXPORT_STUB(__import__XamNatalDeviceAudioCalibrate);
REX_EXPORT_STUB(__import__XamNuiCameraAdjustTilt);
REX_EXPORT_STUB(__import__XamNuiCameraElevationAutoTilt);
REX_EXPORT_STUB(__import__XamNuiCameraElevationGetAngle);
REX_EXPORT_STUB(__import__XamNuiCameraElevationReverseAutoTilt);
REX_EXPORT_STUB(__import__XamNuiCameraElevationSetAngle);
REX_EXPORT_STUB(__import__XamNuiCameraElevationSetCallback);
REX_EXPORT_STUB(__import__XamNuiCameraElevationStopMovement);
REX_EXPORT_STUB(__import__XamNuiCameraGetTiltControllerType);
REX_EXPORT_STUB(__import__XamNuiCameraRememberFloor);
REX_EXPORT_STUB(__import__XamNuiCameraSetFlags);
REX_EXPORT_STUB(__import__XamNuiCameraTiltGetStatus);
REX_EXPORT_STUB(__import__XamNuiCameraTiltReportStatus);
REX_EXPORT_STUB(__import__XamNuiCameraTiltSetCallback);
REX_EXPORT_STUB(__import__XamNuiEnableChatMic);
REX_EXPORT_STUB(__import__XamNuiGetCameraIntrinsics);
REX_EXPORT_STUB(__import__XamNuiGetDepthCalibration);
REX_EXPORT_STUB(__import__XamNuiGetDeviceSerialNumber);
REX_EXPORT_STUB(__import__XamNuiGetFanRate);
REX_EXPORT_STUB(__import__XamNuiGetLoadedDepthCalibration);
REX_EXPORT_STUB(__import__XamNuiGetSupportString);
REX_EXPORT_STUB(__import__XamNuiGetSystemGestureControl);
REX_EXPORT_STUB(__import__XamNuiGetTrueColorInfo);
REX_EXPORT_STUB(__import__XamNuiHudEnableInputFilter);
REX_EXPORT_STUB(__import__XamNuiHudGetEngagedEnrollmentIndex);
REX_EXPORT_STUB(__import__XamNuiHudGetEngagedTrackingID);
REX_EXPORT_STUB(__import__XamNuiHudGetInitializeFlags);
REX_EXPORT_STUB(__import__XamNuiHudGetVersions);
REX_EXPORT_STUB(__import__XamNuiHudInterpretFrame);
REX_EXPORT_STUB(__import__XamNuiHudIsEnabled);
REX_EXPORT_STUB(__import__XamNuiHudSetEngagedTrackingID);
REX_EXPORT_STUB(__import__XamNuiIdentityAbort);
REX_EXPORT_STUB(__import__XamNuiIdentityEnrollForSignIn);
REX_EXPORT_STUB(__import__XamNuiIdentityGetColorTexture);
REX_EXPORT_STUB(__import__XamNuiIdentityGetEnrollmentInfo);
REX_EXPORT_STUB(__import__XamNuiIdentityGetQualityFlags);
REX_EXPORT_STUB(__import__XamNuiIdentityGetQualityFlagsMessage);
REX_EXPORT_STUB(__import__XamNuiIdentityGetSessionId);
REX_EXPORT_STUB(__import__XamNuiIdentityIdentifyWithBiometric);
REX_EXPORT_STUB(__import__XamNuiIdentityUnenroll);
REX_EXPORT_STUB(__import__XamNuiIsChatMicEnabled);
REX_EXPORT_STUB(__import__XamNuiIsDeviceReady);
REX_EXPORT_STUB(__import__XamNuiNatalCameraUpdateComplete);
REX_EXPORT_STUB(__import__XamNuiNatalCameraUpdateStarting);
REX_EXPORT_STUB(__import__XamNuiPlayerEngagementUpdate);
REX_EXPORT_STUB(__import__XamNuiSetForceDeviceOff);
REX_EXPORT_STUB(__import__XamNuiSkeletonGetBestSkeletonIndex);
REX_EXPORT_STUB(__import__XamNuiSkeletonScoreUpdate);
REX_EXPORT_STUB(__import__XamNuiStoreDepthCalibration);
