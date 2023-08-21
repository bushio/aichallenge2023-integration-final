// Copyright 2022 Takagi, Isamu
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "types.hpp"
#include <memory>

namespace multi_data_monitor
{

CommonData::CommonData(const NodeClass & klass, const NodeLabel & label) : klass(klass), label(label)
{
  ++created;
}

CommonData::~CommonData()
{
  ++removed;
}

FilterLink ConfigData::create_filter(const NodeClass & klass, const NodeLabel & label, YAML::Node yaml)
{
  const auto data = std::make_shared<FilterData>(klass, label);
  data->yaml = yaml;
  return filters.emplace_back(data);
}

StreamLink ConfigData::create_stream(const NodeClass & klass, const NodeLabel & label, YAML::Node yaml)
{
  const auto data = std::make_shared<StreamData>(klass, label);
  data->yaml = yaml;
  return streams.emplace_back(data);
}

WidgetLink ConfigData::create_widget(const NodeClass & klass, const NodeLabel & label, YAML::Node yaml)
{
  const auto data = std::make_shared<WidgetData>(klass, label);
  data->yaml = yaml;
  return widgets.emplace_back(data);
}

}  // namespace multi_data_monitor
