#pragma once

#include <array>
#include <cstddef>
#include <string_view>

namespace asynclog {

enum class LogLevel : int { trace = 0, debug, info, warn, error, fatal };

inline constexpr std::array<std::string_view, 6> kLevelNames{
    "TRACE", "DEBUG", "INFO", "WARN", "ERROR", "FATAL"};

inline std::string_view to_string(LogLevel level) noexcept {
    const auto idx = static_cast<std::size_t>(level);
    return idx < kLevelNames.size() ? kLevelNames[idx] : std::string_view{"UNKNOWN"};
}

inline bool from_string(std::string_view text, LogLevel& out) noexcept {
    for (std::size_t i = 0; i < kLevelNames.size(); ++i) {
        if (kLevelNames[i] == text) {
            out = static_cast<LogLevel>(i);
            return true;
        }
    }
    return false;
}

}  // namespace asynclog
