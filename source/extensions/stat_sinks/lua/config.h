#pragma once

#include <string>

#include "envoy/server/factory_context.h"
#include "envoy/server/instance.h"

#include "source/common/config/datasource.h"
#include "source/server/configuration_impl.h"

namespace Envoy {
namespace Extensions {
namespace StatSinks {
namespace Lua {

// Lua sink
constexpr char LuaName[] = "envoy.stat_sinks.lua";

/**
 * Config registration for the Lua statsd sink. @see StatSinkFactory.
 */
class LuaSinkFactory : Logger::Loggable<Logger::Id::config>,
                        public Server::Configuration::StatsSinkFactory {
public:
  // StatsSinkFactory
  Stats::SinkPtr createStatsSink(const Protobuf::Message& config,
                                 Server::Configuration::ServerFactoryContext& context) override;

  ProtobufTypes::MessagePtr createEmptyConfigProto() override;

  std::string name() const override;

private:
  Config::DataSource::RemoteAsyncDataProviderPtr remote_data_provider_;
};

} // namespace Lua
} // namespace StatSinks
} // namespace Extensions
} // namespace Envoy
