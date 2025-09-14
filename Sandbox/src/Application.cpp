#include "lib.h"
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

int main()
{
	TestFunction();

	glfwInit();

	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

	auto window = glfwCreateWindow(1080, 720, "glfw window", nullptr, nullptr);
	glfwSetWindowPos(window, 100, 50);

	VkInstance instance;
	VkInstanceCreateInfo createInfo{};
	createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
	vkCreateInstance(&createInfo, nullptr, &instance);

	VkSurfaceKHR surface;
	auto res = glfwCreateWindowSurface(instance, window, nullptr, &surface);

	std::cout << "VkInstance: " << (uint64_t)instance << std::endl << "VkSurfaceKHR: " << (uint64_t)surface << std::endl;
	std::cout << "Create Surface res" << res << std::endl;
	
	while (!glfwWindowShouldClose(window))
	{
		glfwPollEvents();
	}

	vkDestroySurfaceKHR(instance, surface, nullptr);
	vkDestroyInstance(instance, nullptr);
	glfwDestroyWindow(window);	
	glfwTerminate();

	return 0;
}