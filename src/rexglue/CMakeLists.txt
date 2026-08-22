# ReXGlue 

add_executable(rexglue_xeo3
    main.cpp
    ui/ui.cpp
    ui/progress.cpp
    commands/codegen_command.cpp
    commands/init_command.cpp
    commands/test_recompiler.cpp
    commands/project_scan.cpp
)

rex_config_postfix(rexglue_xeo3)

target_include_directories(rexglue_xeo3
    PRIVATE
        ${REXGLUE_XEO3_ROOT}/src
        ${REXGLUE_XEO3_ROOT}/thirdparty/disasm
        ${REXGLUE_XEO3_ROOT}/thirdparty/cli11/include
)

target_link_libraries(rexglue_xeo3
    PRIVATE
        rexcodegen
)

rex_target_pch(rexglue_xeo3 <CLI/CLI.hpp>)

# Delay-load FidelityFX DLLs so rexglue can run in tool mode without them.
if(WIN32)
    if(TARGET amd_fidelityfx_vk)
        target_link_options(rexglue_xeo3 PRIVATE
            "LINKER:/DELAYLOAD:$<TARGET_FILE_NAME:amd_fidelityfx_vk>")
    endif()
    if(TARGET amd_fidelityfx_dx12)
        target_link_options(rexglue_xeo3 PRIVATE
            "LINKER:/DELAYLOAD:$<TARGET_FILE_NAME:amd_fidelityfx_dx12>")
    endif()
    if(TARGET amd_fidelityfx_vk OR TARGET amd_fidelityfx_dx12)
        target_link_libraries(rexglue_xeo3 PRIVATE delayimp)
    endif()
endif()

add_executable(rex::rexglue ALIAS rexglue_xeo3)
