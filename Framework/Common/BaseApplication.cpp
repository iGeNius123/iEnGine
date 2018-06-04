#include "BaseApplication.hpp"

//Prase command line, read configuration, initialize all sub modules
int IENGINE::BaseApplication::Initialize(){
    m_bQuit=false;
    return 0;
}

void IENGINE::BaseApplication::Finalize(){}

void IENGINE::BaseApplication::Tick(){}

bool IENGINE::BaseApplication::IsQuit(){
    return m_bQuit;

}