//
// This file is a part of UERANSIM open source project.
// Copyright (c) 2021 ALİ GÜNGÖR.
//
// The software and all associated files are licensed under GPL-3.0
// and subject to the terms and conditions defined in LICENSE file.
//

#pragma once

#include "sqn_mng.hpp"

#include <memory>
#include <optional>

#include <lib/nas/msg.hpp>
#include <ue/types.hpp>
#include <utils/common_types.hpp>
#include <utils/octet_string.hpp>

namespace nr::ue
{

class Usim
{
  private:
    bool m_isValid{};

  public:
    // Security related
    std::unique_ptr<NasSecurityContext> m_currentNsCtx{};
    std::unique_ptr<NasSecurityContext> m_nonCurrentNsCtx{};
    OctetString m_rand{};
    OctetString m_resStar{};
    std::unique_ptr<SqnManager> m_sqnMng{};

    // NSSAI related
    NetworkSlice m_defConfiguredNssai{};
    NetworkSlice m_configuredNssai{};
    NetworkSlice m_allowedNssai{};
    NetworkSlice m_rejectedNssaiInPlmn{};
    NetworkSlice m_rejectedNssaiInTa{};

    // NITZ related
    std::optional<nas::IENetworkName> m_networkFullName{};
    std::optional<nas::IENetworkName> m_networkShortName{};
    std::optional<nas::IETimeZone> m_localTimeZone{};
    std::optional<nas::IETimeZoneAndTime> m_universalTimeAndLocalTimeZone{};
    std::optional<nas::IEDaylightSavingTime> m_networkDaylightSavingTime{};

    // Others
    bool m_isECallOnly{}; // todo: configurable

  public:
    void initialize(bool hasSupi, const UeConfig::Initials &initials);

    bool isValid();
    void invalidate();
};

} // namespace nr::ue