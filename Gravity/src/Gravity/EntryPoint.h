#pragma once

#ifdef GVT_PLATFORM_WINDOWS

extern Gravity::Application* Gravity::CreateApplication();

int main(int argc,char **argv)
{
	Gravity::Log::Init();

	GVT_CORE_ERROR("Engine Says Hello!");
	int arg = 2;
	GVT_TRACE("Sandbo Says Hello {0}", arg);

	Gravity::Application* app = Gravity::CreateApplication();
	app->Run();
	delete app;
}

#endif