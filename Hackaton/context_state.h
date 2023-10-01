#pragma once
#include "app_state.h"
#include "concrete_state1.h"
#include "concrete_state2.h"
#include "context_state.h"

/// aici alege pe care crd
class ContextState{
private: 
	AppState* currentstate;

public:
	ContextState() { currentstate = new ConcreteState1(); }

	void setstate(AppState* state1)
	{
		currentstate = state1;

	}
	void state() { currentstate->state(); }
};

