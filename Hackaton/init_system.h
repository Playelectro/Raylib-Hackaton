#pragma once
#include "system.h"
#include "menu_button.h"
#include "position_component.h"
#include "system_manager.h"

#include "button_menu_system.h"

class InitSystem :public System
{
	void doLogic() override;
};

