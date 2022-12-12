#pragma once
#include "Core.h"

namespace Gravity {
	
	class GVT_API Application
	{
	public :
		 Application();
		 virtual ~Application();

		 void Run();
	};

	Application* CreateApplication();
}

