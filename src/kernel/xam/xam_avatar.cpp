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

#include <rex/kernel/xam/private.h>
#include <rex/logging.h>
#include <rex/hook.h>
#include <rex/types.h>
#include <rex/system/kernel_state.h>
#include <rex/system/xtypes.h>

namespace rex {
namespace kernel {
namespace xam {

u32 XamAvatarInitialize_entry(u32 unk1,                  // 1, 4, etc
                              u32 unk2,                  // 0 or 1
                              u32 processor_number,      // for thread creation?
                              mapped_u32 function_ptrs,  // 20b, 5 pointers
                              mapped_void unk5,          // ptr in data segment
                              u32 unk6                   // flags - 0x00300000, 0x30, etc
) {
  // Negative to fail. Game should immediately call XamAvatarShutdown.
  return ~0u;
}

void XamAvatarShutdown_entry() {
  // No-op.
}

}  // namespace xam
}  // namespace kernel
}  // namespace rex

REX_EXPORT(__import__XamAvatarInitialize, rex::kernel::xam::XamAvatarInitialize_entry)
REX_EXPORT(__import__XamAvatarShutdown, rex::kernel::xam::XamAvatarShutdown_entry)

REX_EXPORT_STUB(__import__XamAvatarBeginEnumAssets);
REX_EXPORT_STUB(__import__XamAvatarEndEnumAssets);
REX_EXPORT_STUB(__import__XamAvatarEnumAssets);
REX_EXPORT_STUB(__import__XamAvatarGenerateMipMaps);
REX_EXPORT_STUB(__import__XamAvatarGetAssetBinary);
REX_EXPORT_STUB(__import__XamAvatarGetAssetIcon);
REX_EXPORT_STUB(__import__XamAvatarGetAssets);
REX_EXPORT_STUB(__import__XamAvatarGetAssetsResultSize);
REX_EXPORT_STUB(__import__XamAvatarGetInstalledAssetPackageDescription);
REX_EXPORT_STUB(__import__XamAvatarGetInstrumentation);
REX_EXPORT_STUB(__import__XamAvatarGetManifestLocalUser);
REX_EXPORT_STUB(__import__XamAvatarGetManifestsByXuid);
REX_EXPORT_STUB(__import__XamAvatarGetMetadataRandom);
REX_EXPORT_STUB(__import__XamAvatarGetMetadataSignedOutProfile);
REX_EXPORT_STUB(__import__XamAvatarGetMetadataSignedOutProfileCount);
REX_EXPORT_STUB(__import__XamAvatarLoadAnimation);
REX_EXPORT_STUB(__import__XamAvatarManifestGetBodyType);
REX_EXPORT_STUB(__import__XamAvatarReinstallAwardedAsset);
REX_EXPORT_STUB(__import__XamAvatarSetCustomAsset);
REX_EXPORT_STUB(__import__XamAvatarSetManifest);
REX_EXPORT_STUB(__import__XamAvatarSetMocks);
REX_EXPORT_STUB(__import__XamAvatarWearNow);
