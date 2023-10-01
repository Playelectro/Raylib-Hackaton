#pragma once
#include "app_state.h"
#include "system_manager.h"
/// aici alege pe care crd
class ContextState{
private: 
	AppState* currentstate;
    ContextState() {}
    static ContextState* instancePtr;

public:
    ContextState(const ContextState& obj) = delete;

    static ContextState* getInstance()
    {
        if (instancePtr == NULL)
        {
            instancePtr = new ContextState();
            return instancePtr;
        }
        else
        {
            return instancePtr;
        }
    }

	void SetState(AppState* state1)
	{
        delete currentstate;
		currentstate = state1;
	}
	void InitState(){ 
        SystemManager::getInstance()->CleanSystem();
    
        currentstate->InitState(); 
    }

};