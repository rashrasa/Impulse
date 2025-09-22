#pragma once

#define IM_ASSERT(exp) if(!exp)throw std::runtime_error("Assertion Failed: " #exp)