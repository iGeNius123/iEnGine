#include<stdio.h>
#include "../Interface/IApplication.hpp"

using namespace IENGINE;
namespace IENGINE {
    extern IApplication* g_pApp;
}

int main(){
    int ret;

    if((ret=g_pApp->Initialize())!=0){
        printf("App Initialize failed, exit now.\n");
        return ret;
    }
    while(!g_pApp->IsQuit()){
        g_pApp->Tick();
    }

    g_pApp->Finalize();

    return 0;
}