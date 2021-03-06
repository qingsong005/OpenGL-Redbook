#include "RenderSystem.h"
#include <glm/glm.hpp>

namespace byhj
{


void RenderSystem::v_InitInfo()
{
	windowInfo.title += "ch01-01-Rectangle";
}

void RenderSystem::v_Init()
{
	m_Rectangle.Init();
}

void RenderSystem::v_Render()
{
	static const glm::vec4 bgColor(0.2f, 0.4f, 0.5f, 1.0f);
	glClearBufferfv(GL_COLOR, 0, &bgColor[0]);

	m_Rectangle.Render();
}

void RenderSystem::v_Shutdown()
{
	m_Rectangle.Shutdown();
}

void RenderSystem::v_KeyCallback(GLFWwindow* Triangle, int key, int scancode, int action, int mode)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(Triangle, GL_TRUE);
	if (key == GLFW_KEY_W && action == GLFW_PRESS)
		m_Rectangle.ChangeTexWrap();
}


}