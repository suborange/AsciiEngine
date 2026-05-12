#include <AsciiEngine.h>

using namespace AsciiEngine;

class CustomEngine : public Application
{
public:
	CustomEngine(const WindowProps& props)
		: Application(props)
	{
	}

	Vector2 playerPos = { 2, 2 };
	Input* key = new Input;

	virtual void OnUpdate() override
	{
		Renderer::DrawLine({ 0, 0 }, { 20, 0 }, '#');
		Renderer::DrawLine({ 20, 0 }, { 20, 10 }, '#');
		Renderer::DrawLine({ 20, 10 }, { 0, 10 }, '#');
		Renderer::DrawLine({ 0, 10 }, { 0, 0 }, '#');

		Renderer::Draw(playerPos, 'X');

		if ( playerPos.x < 18 && key->IsKeyPressed(KEY_RIGHT_ARROW))
			playerPos.x++;
		else if ( playerPos.y <= 8 && key->IsKeyPressed(KEY_DOWN_ARROW))
			playerPos.y++;
		else if (playerPos.x > 2 && key->IsKeyPressed(KEY_LEFT_ARROW))
			playerPos.x--;
		else if ( playerPos.y >= 2 && key->IsKeyPressed(KEY_UP_ARROW))
			playerPos.y--;
	}
};

int main()
{
	Application* app = new CustomEngine({ 22, 16 });
	app->Run();
	delete app;
}