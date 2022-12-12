#pragma once

#ifdef GVT_PLATFORM_WINDOWS

extern Gravity::Application* Gravity::CreateApplication();

int main()
{
	Gravity::Application* app = Gravity::CreateApplication();
	app->Run();
	delete app;
}

#endif