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
#include <rex/system/xthread.h>
#include <rex/system/xtypes.h>

namespace rex::kernel::xboxkrnl {

void KeEnableFpuExceptions_entry(u32 enabled) {
  // TODO(benvanik): can we do anything about exceptions?
}

}  // namespace rex::kernel::xboxkrnl

REX_EXPORT(__import__KeEnableFpuExceptions, rex::kernel::xboxkrnl::KeEnableFpuExceptions_entry)

REX_EXPORT_STUB(__import__ExSetBetaFeaturesEnabled);
REX_EXPORT_STUB(__import__ExIsBetaFeatureEnabled);
REX_EXPORT_STUB(__import__AniBlockOnAnimation);
REX_EXPORT_STUB(__import__AniTerminateAnimation);
REX_EXPORT_STUB(__import__AniSetLogo);
REX_EXPORT_STUB(__import__AniStartBootAnimation);
REX_EXPORT_STUB(__import__EtxConsumerDisableEventType);
REX_EXPORT_STUB(__import__EtxConsumerEnableEventType);
REX_EXPORT_STUB(__import__EtxConsumerProcessLogs);
REX_EXPORT_STUB(__import__EtxConsumerRegister);
REX_EXPORT_STUB(__import__EtxConsumerUnregister);
REX_EXPORT_STUB(__import__EtxProducerLog);
REX_EXPORT_STUB(__import__EtxProducerLogV);
REX_EXPORT_STUB(__import__EtxProducerRegister);
REX_EXPORT_STUB(__import__EtxProducerUnregister);
REX_EXPORT_STUB(__import__EtxConsumerFlushBuffers);
REX_EXPORT_STUB(__import__EtxProducerLogXwpp);
REX_EXPORT_STUB(__import__EtxProducerLogXwppV);
REX_EXPORT_STUB(__import__EtxBufferRegister);
REX_EXPORT_STUB(__import__EtxBufferUnregister);
REX_EXPORT_STUB(__import__KeEnablePPUPerformanceMonitor);
REX_EXPORT_STUB(__import__KeEnterUserMode);
REX_EXPORT_STUB(__import__KeLeaveUserMode);
REX_EXPORT_STUB(__import__KeCreateUserMode);
REX_EXPORT_STUB(__import__KeDeleteUserMode);
REX_EXPORT_STUB(__import__KeEnablePFMInterrupt);
REX_EXPORT_STUB(__import__KeDisablePFMInterrupt);
REX_EXPORT_STUB(__import__KeSetProfilerISR);
REX_EXPORT_STUB(__import__KeGetVidInfo);
REX_EXPORT_STUB(__import__KeExecuteOnProtectedStack);
REX_EXPORT_STUB(__import__EmaExecute);
REX_EXPORT_STUB(__import__ExRegisterThreadNotification);
REX_EXPORT_STUB(__import__ExTerminateTitleProcess);
REX_EXPORT_STUB(__import__ExFreeDebugPool);
REX_EXPORT_STUB(__import__ExReadModifyWriteXConfigSettingUlong);
REX_EXPORT_STUB(__import__ExRegisterXConfigNotification);
REX_EXPORT_STUB(__import__ExCancelAlarm);
REX_EXPORT_STUB(__import__ExInitializeAlarm);
REX_EXPORT_STUB(__import__ExSetAlarm);
REX_EXPORT_STUB(__import__KeBlowFuses);
REX_EXPORT_STUB(__import__KeGetPMWRegister);
REX_EXPORT_STUB(__import__KeGetPRVRegister);
REX_EXPORT_STUB(__import__KeGetSocRegister);
REX_EXPORT_STUB(__import__KeGetSpecialPurposeRegister);
REX_EXPORT_STUB(__import__KeSetPMWRegister);
REX_EXPORT_STUB(__import__KeSetPowerMode);
REX_EXPORT_STUB(__import__KeSetPRVRegister);
REX_EXPORT_STUB(__import__KeSetSocRegister);
REX_EXPORT_STUB(__import__KeSetSpecialPurposeRegister);
REX_EXPORT_STUB(__import__KeCallAndBlockOnDpcRoutine);
REX_EXPORT_STUB(__import__KeCallAndWaitForDpcRoutine);
REX_EXPORT_STUB(__import__KeSetPageRelocationCallback);
REX_EXPORT_STUB(__import__KeRegisterSwapNotification);

REX_EXPORT_STUB(__import__DetroitDeviceRequest);
REX_EXPORT_STUB(__import__IptvGetAesCtrTransform);
REX_EXPORT_STUB(__import__IptvGetSessionKeyHash);
REX_EXPORT_STUB(__import__IptvSetBoundaryKey);
REX_EXPORT_STUB(__import__IptvSetSessionKey);
REX_EXPORT_STUB(__import__IptvVerifyOmac1Signature);
REX_EXPORT_STUB(__import__McaDeviceRequest);
REX_EXPORT_STUB(__import__MicDeviceRequest);
REX_EXPORT_STUB(__import__MtpdBeginTransaction);
REX_EXPORT_STUB(__import__MtpdCancelTransaction);
REX_EXPORT_STUB(__import__MtpdEndTransaction);
REX_EXPORT_STUB(__import__MtpdGetCurrentDevices);
REX_EXPORT_STUB(__import__MtpdReadData);
REX_EXPORT_STUB(__import__MtpdReadEvent);
REX_EXPORT_STUB(__import__MtpdResetDevice);
REX_EXPORT_STUB(__import__MtpdSendData);
REX_EXPORT_STUB(__import__MtpdVerifyProximity);
REX_EXPORT_STUB(__import__NicAttach);
REX_EXPORT_STUB(__import__NicDetach);
REX_EXPORT_STUB(__import__NicFlushXmitQueue);
REX_EXPORT_STUB(__import__NicGetLinkState);
REX_EXPORT_STUB(__import__NicGetOpt);
REX_EXPORT_STUB(__import__NicGetStats);
REX_EXPORT_STUB(__import__NicRegisterDevice);
REX_EXPORT_STUB(__import__NicSetOpt);
REX_EXPORT_STUB(__import__NicSetUnicastAddress);
REX_EXPORT_STUB(__import__NicShutdown);
REX_EXPORT_STUB(__import__NicUnregisterDevice);
REX_EXPORT_STUB(__import__NicUpdateMcastMembership);
REX_EXPORT_STUB(__import__NicXmit);
REX_EXPORT_STUB(__import__NomnilGetExtension);
REX_EXPORT_STUB(__import__NomnilSetLed);
REX_EXPORT_STUB(__import__NomnilStartCloseDevice);
REX_EXPORT_STUB(__import__NullCableRequest);
REX_EXPORT_STUB(__import__PsCamDeviceRequest);
REX_EXPORT_STUB(__import__RmcDeviceRequest);
REX_EXPORT_STUB(__import__TidDeviceRequest);
REX_EXPORT_STUB(__import__TitleDeviceAuthRequest);
REX_EXPORT_STUB(__import__UsbdAddDeviceComplete);
REX_EXPORT_STUB(__import__UsbdCallAndBlockOnDpcRoutine);
REX_EXPORT_STUB(__import__UsbdCancelAsyncTransfer);
REX_EXPORT_STUB(__import__UsbdCancelTimer);
REX_EXPORT_STUB(__import__UsbdEnableDisableRootHubPort);
REX_EXPORT_STUB(__import__UsbdGetDeviceDescriptor);
REX_EXPORT_STUB(__import__UsbdGetDeviceRootPortType);
REX_EXPORT_STUB(__import__UsbdGetDeviceSpeed);
REX_EXPORT_STUB(__import__UsbdGetDeviceTopology);
REX_EXPORT_STUB(__import__UsbdGetEndpointDescriptor);
REX_EXPORT_STUB(__import__UsbdGetNatalHardwareVersion);
REX_EXPORT_STUB(__import__UsbdGetNatalHub);
REX_EXPORT_STUB(__import__UsbdGetPortDeviceNode);
REX_EXPORT_STUB(__import__UsbdGetRequiredDrivers);
REX_EXPORT_STUB(__import__UsbdGetRootHubDeviceNode);
REX_EXPORT_STUB(__import__UsbdIsDeviceAuthenticated);
REX_EXPORT_STUB(__import__UsbdNatalHubRegisterNotificationCallback);
REX_EXPORT_STUB(__import__UsbdOpenDefaultEndpoint);
REX_EXPORT_STUB(__import__UsbdOpenEndpoint);
REX_EXPORT_STUB(__import__UsbdQueueAsyncTransfer);
REX_EXPORT_STUB(__import__UsbdQueueCloseDefaultEndpoint);
REX_EXPORT_STUB(__import__UsbdQueueCloseEndpoint);
REX_EXPORT_STUB(__import__UsbdQueueIsochTransfer);
REX_EXPORT_STUB(__import__UsbdRegisterDriverObject);
REX_EXPORT_STUB(__import__UsbdRemoveDeviceComplete);
REX_EXPORT_STUB(__import__UsbdResetDevice);
REX_EXPORT_STUB(__import__UsbdResetEndpoint);
REX_EXPORT_STUB(__import__UsbdSetTimer);
REX_EXPORT_STUB(__import__UsbdTitleDriverResetAllUnrecognizedPorts);
REX_EXPORT_STUB(__import__UsbdTitleDriverSetUnrecognizedPort);
REX_EXPORT_STUB(__import__UsbdUnregisterDriverObject);
REX_EXPORT_STUB(__import__VeSetHandlers);
REX_EXPORT_STUB(__import__VgcHandler_SetHandlers);
REX_EXPORT_STUB(__import__VvcHandlerCancelTransfers);
REX_EXPORT_STUB(__import__VvcHandlerRetrieveVoiceExtension);
REX_EXPORT_STUB(__import__WifiBeginAuthentication);
REX_EXPORT_STUB(__import__WifiCalculateRegulatoryDomain);
REX_EXPORT_STUB(__import__WifiChannelToFrequency);
REX_EXPORT_STUB(__import__WifiCheckCounterMeasures);
REX_EXPORT_STUB(__import__WifiChooseAuthenCipherSetFromBSSID);
REX_EXPORT_STUB(__import__WifiCompleteAuthentication);
REX_EXPORT_STUB(__import__WifiDeduceNetworkType);
REX_EXPORT_STUB(__import__WifiGetAssociationIE);
REX_EXPORT_STUB(__import__WifiOnMICError);
REX_EXPORT_STUB(__import__WifiPrepareAuthenticationContext);
REX_EXPORT_STUB(__import__WifiRecvEAPOLPacket);
REX_EXPORT_STUB(__import__WifiSelectAdHocChannel);
REX_EXPORT_STUB(__import__XVoicedActivate);
REX_EXPORT_STUB(__import__XVoicedClose);
REX_EXPORT_STUB(__import__XVoicedGetBatteryStatus);
REX_EXPORT_STUB(__import__XVoicedGetDirectionalData);
REX_EXPORT_STUB(__import__XVoicedHeadsetPresent);
REX_EXPORT_STUB(__import__XVoicedIsActiveProcess);
REX_EXPORT_STUB(__import__XVoicedSendVPort);
REX_EXPORT_STUB(__import__XVoicedSubmitPacket);
