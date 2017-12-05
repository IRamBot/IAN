/*
 * This file is part of the IAN project - https://github.com/Meoo/IAN
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#pragma once

#include <bin-common/config/ConfigListener.hpp>

#include <string>


class ConfigBoolValue : public ConfigListener
{
public:
  ConfigBoolValue(const std::string& key, bool default_val);

  const std::string& get_key() const { return key_; }
  bool get_value() const { return value_; }
  operator bool() const { return value_; }


protected:
  void on_update() override;


private:
  std::string key_;
  bool default_val_;
  bool value_;

};


class ConfigStringValue : public ConfigListener
{
public:
  explicit ConfigStringValue(const std::string& key, const std::string& default_val = std::string());

  const std::string& get_key() const { return key_; }
  const std::string& get_value() const { return value_; }
  operator const std::string&() const { return value_; }


protected:
  void on_update() override;


private:
  std::string key_;
  std::string default_val_;
  std::string value_;

};


class ConfigIntValue : public ConfigListener
{
public:
  explicit ConfigIntValue(const std::string& key, int default_val = 0);

  const std::string& get_key() const { return key_; }
  int get_value() const { return value_; }
  operator int() const { return value_; }


protected:
  void on_update() override;


private:
  std::string key_;
  int default_val_;
  int value_;

};