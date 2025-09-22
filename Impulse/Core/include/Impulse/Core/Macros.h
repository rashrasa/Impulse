#pragma once

#define IM_ASSERT(exp, msg) if(!exp)throw std::runtime_error(std::string("Assertion Failed: ") + std::string(#exp) + std::string("\nMessage: ") + std::string(msg))