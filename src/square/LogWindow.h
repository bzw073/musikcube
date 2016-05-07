#pragma once

#include <sigslot/sigslot.h>

#include <core/debug.h>
#include <boost/thread/mutex.hpp>
#include "BorderedWindow.h"

class LogWindow : public BorderedWindow, public sigslot::has_slots<> {
    public:
        LogWindow();
        ~LogWindow();

        void Update();

    private:
        void OnLogged(
            musik::debug::log_level level, 
            std::string tag, 
            std::string message);

        struct LogEntry {
            int level;
            std::string tag;
            std::string message;
        };

        boost::mutex pendingMutex;
        std::vector<LogEntry*> pending;
};