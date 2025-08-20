#include <Saffran.h>


class Sandbox : public Saffran::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}
};


Saffran::Application* Saffran::CreateApplication()
{
	return new Sandbox();
}