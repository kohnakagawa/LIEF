/* Copyright 2017 R. Thomas
 * Copyright 2017 Quarkslab
 * Copyright 2020 K. Nakagawa
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#ifndef LIEF_PE_SIGNATURE_TYPES_H_
#define LIEF_PE_SIGNATURE_TYPES_H_

#include <string>
#include <cinttypes>
#include <vector>

#include "mapbox/variant.hpp"

#include "LIEF/iterators.hpp"

namespace LIEF {
namespace PE {
class x509;

using mapbox::util::variant;

using oid_t        = std::string;
using issuer_t     = std::pair<std::string, std::vector<uint8_t>>;
using it_const_crt = const_ref_iterator<const std::vector<x509>&>;
using spc_serialized_object_t = std::pair<std::vector<uint8_t>, std::vector<uint8_t>>;
using spc_link_t   =
        std::pair<std::string, variant<std::string, spc_serialized_object_t>>;
}
}

#endif
