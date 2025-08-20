#pragma once


#ifdef SF_PLATFORM_WINDOWS

extern Saffran::Application* Saffran::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Saffran::CreateApplication();
	app->Run();

	delete app;
}

#endif // SF_PLATFORM_WINDOWS
