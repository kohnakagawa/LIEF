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
#ifndef LIEF_PE_SIGNATURE_H_
#define LIEF_PE_SIGNATURE_H_

#include "LIEF/Object.hpp"
#include "LIEF/visibility.h"

#include "LIEF/PE/enums.hpp"

#include "LIEF/PE/signature/x509.hpp"
#include "LIEF/PE/signature/SignerInfo.hpp"
#include "LIEF/PE/signature/ContentInfo.hpp"

#include "LIEF/PE/signature/types.hpp"

namespace LIEF {
namespace PE {

class SignatureParser;

class LIEF_API Signature : public Object {

  friend class SignatureParser;
  friend class Parser;

  public:
  Signature(void);

  Signature(Signature&&);
  Signature& operator=(Signature&&);

  //! @brief Specifies the length of the attribute certificate entry.
  uint32_t length(void) const;

  //! @brief Contains the certificate version number.
  CERTIFICATE_REVISION revision(void) const;

  //! @brief Specifies the type of content in bCertificate.
  CERTIFICATE_TYPE     certificate_type(void) const;

  //! @brief Should be 1
  uint32_t version(void) const;

  //! @brief Return the algorithm (OID) used to
  //! sign the content of ContentInfo
  const oid_t& digest_algorithm(void) const;

  //! @brief Return the content_type (OID)
  const oid_t& content_type(void) const;

  //! @brief Return the ContentInfo
  const ContentInfo& content_info(void) const;

  //! @brief Return an iterator over x509 certificates
  it_const_crt certificates(void) const;

  //! @brief Return the SignerInfo object
  const SignerInfo& signer_info(void) const;

  //! @brief Return the raw original signature
  const std::vector<uint8_t>& original_signature(void) const;

  virtual void accept(Visitor& visitor) const override;

  virtual ~Signature(void);

  LIEF_API friend std::ostream& operator<<(std::ostream& os, const Signature& signature);

  private:

  uint32_t             length_;
  CERTIFICATE_REVISION revision_;
  CERTIFICATE_TYPE     certificate_type_;
  oid_t                content_type_;

  uint32_t          version_;
  oid_t             digest_algorithm_;
  std::unique_ptr<ContentInfo>      content_info_;
  std::vector<x509> certificates_;
  SignerInfo        signer_info_;

  std::vector<uint8_t> original_raw_signature_;



};

}
}


#endif

