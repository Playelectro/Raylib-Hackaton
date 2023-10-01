#pragma once

#include "actor.h"
#include "system.h"
#include "init_system.h"

/// interfata crd

class AppState{
public:
		virtual void state() = 0;
};