#pragma once

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <vector>
#include "Utilities.h"

struct Model {
	glm::mat4 model;
	bool hasTexture;
};

class Mesh
{
public:
	Mesh();
	Mesh(VkPhysicalDevice newPhysicalDevice, 
		VkDevice newDevice, 
		VkQueue transferQueue, 
		VkCommandPool transferCommandPool,
		std::vector<uint32_t> * indices, 
		std::vector<Vertex> * vertices,
		int newTexId);

	Mesh(VkPhysicalDevice newPhysicalDevice,
		VkDevice newDevice,
		VkQueue transferQueue,
		VkCommandPool transferCommandPool,
		std::vector<uint32_t>* indices,
		std::vector<Vertex>* vertices);
	
	int getTexId();

	int getVertexCount();
	VkBuffer getVertexBuffer();

	int getIndexCount();
	VkBuffer getIndexBuffer();

	void destroyBuffers();

	void setModel(glm::mat4 newModel);
	Model getModel();

	~Mesh();
private:
	Model model;
	int texId;

	int vertexCount;
	VkBuffer vertexBuffer;
	VkDeviceMemory vertexBufferMemory;

	int indexCount;
	VkBuffer indexBuffer;
	VkDeviceMemory indexBufferMemory;

	VkPhysicalDevice physicalDevice;
	VkDevice device;

	void createVertexBuffer(VkQueue transferQueue, VkCommandPool transferCommandPool, std::vector<Vertex>* vertices);
	void createIndexBuffer(VkQueue transferQueue, VkCommandPool transferCommandPool, std::vector<uint32_t>* indices);
};

