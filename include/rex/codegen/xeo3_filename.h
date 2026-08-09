/**
 * @file        rex/codegen/xeo3_filename.h
 * @brief       XEO3 filename generator
 *
 * @copyright   Copyright (c) 2026 Timo654
 *              All rights reserved.
 *
 * @license     BSD 3-Clause License
 *              See LICENSE file in the project root for full license text.
 */

#pragma once

#include <cstdint>
#include <string>

#include <fmt/format.h>

namespace rex::codegen {
inline std::string MakeXeo3Filename(const char* header_digest) {
  auto d = reinterpret_cast<const uint32_t*>(header_digest);
  return fmt::format("xeo3_{:08x}_{:08x}_{:08x}_{:08x}_{:08x}", d[0], d[1], d[2], d[3], d[4]);
}

}  // namespace rex::codegen
