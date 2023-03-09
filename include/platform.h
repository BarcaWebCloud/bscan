#pragma once

#if defined(unix) || defined(__unix) || defined(__unix__)
#define BSCAN_UNIX
#endif
#if defined(__APPLE__)
#define BSCAN_APPLE
#endif
#if defined(_WIN32) || defined(_WIN64) || defined(__CYGWIN__)
#define BSCAN_WINDOWS
#endif

#if defined(__x86_64__) || defined(__x86_64) || defined(__amd64__) || defined(_M_X64)
#define BSCAN_X86_64
#elif defined(__i386__) || defined(_M_IX86)
#define BSCAN_X86_32
#endif
#if defined(BSCAN_X86_64) || defined(BSCAN_X86_32)
#define BSCAN_X86
#endif
