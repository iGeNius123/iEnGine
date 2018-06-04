#pragma once

#include "../Interface/IApplication.hpp"

namespace IENGINE {
    class BaseApplication : implements IApplication{
        public:
        virtual int Initialize();
        virtual void Finalize();
        //One cycle of main loop
        virtual void Tick();
        virtual bool IsQuit();

        protected:
        //Flag if need quit the main loop if application
        bool m_bQuit;

    };

}