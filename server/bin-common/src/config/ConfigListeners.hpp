/*
 * This file is part of the IAN project - https://github.com/Meoo/IAN
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#pragma once

#include <bin-common/config/ConfigListener.hpp>

#include <mutex>
#include <set>


namespace config
{
namespace impl
{

std::mutex & get_mutex();
std::set<ConfigListener *> & get_listeners();

void invoke_config_listeners();

} // namespace impl
} // namespace config
