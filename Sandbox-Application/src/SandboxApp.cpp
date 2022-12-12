#include <Gravity.h>

class Sandbox : public Gravity::Application 
{
	public:
		Sandbox() 
		{

		}

		~Sandbox() 
		{
	
		}
};

Gravity::Application* Gravity::CreateApplication()
{
	return new Sandbox();
}