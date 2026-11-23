// SPDX-License-Identifier: GPL-3.0-only
#pragma once

// Only the caller's thread is changed, not the process priority class. This
// avoids passing a low process priority to Minecraft or other child processes.
#ifdef Q_OS_WIN
#ifndef NOMINMAX
#define NOMINMAX
#endif
#include <windows.h>
#endif

namespace LauncherThreadPriority {
#ifdef Q_OS_WIN
struct State {
    unsigned int users = 0;
    DWORD threadId = 0;
    int original = THREAD_PRIORITY_ERROR_RETURN;
};
inline State& state()
{
    static State value;
    return value;
}

// Called on the launcher's Qt thread. Shared across simultaneously running games.
inline bool acquire()
{
    auto& s = state();
    const DWORD threadId = GetCurrentThreadId();
    if (s.users != 0) {
        if (s.threadId != threadId)
            return false;
        ++s.users;
        return true;
    }
    const int original = GetThreadPriority(GetCurrentThread());
    // Do not override priorities set by the user or other software.
    if (original != THREAD_PRIORITY_NORMAL || !SetThreadPriority(GetCurrentThread(), THREAD_PRIORITY_BELOW_NORMAL))
        return false;
    s.threadId = threadId;
    s.original = original;
    s.users = 1;
    return true;
}

inline void release()
{
    auto& s = state();
    if (s.users == 0 || s.threadId != GetCurrentThreadId())
        return;
    if (--s.users != 0)
        return;
    // Do not overwrite a priority changed externally during the game.
    if (GetThreadPriority(GetCurrentThread()) == THREAD_PRIORITY_BELOW_NORMAL)
        SetThreadPriority(GetCurrentThread(), s.original);
    s = State{};
}
#else
inline bool acquire() { return false; }
inline void release() {}
#endif
}
