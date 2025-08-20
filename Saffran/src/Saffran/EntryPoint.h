#pragma once


#ifdef SF_PLATFORM_WINDOWS

extern Saffran::Application* Saffran::CreateApplication();

int main(int argc, char** argv)
{
	Saffran::Log::Init();
	SF_CORE_WARN("Initialized Core Logger!");

	int a = 5;
	SF_INFO("Hello! Var={0}", a);

	auto app = Saffran::CreateApplication();
	app->Run();

	delete app;
}

#endif // SF_PLATFORM_WINDOWS
