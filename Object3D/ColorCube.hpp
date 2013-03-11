/**
 * @class	ColorCube
 * @brief	Demo color cube
 *
 * @author	Roberto Sosa Cano
 */
#ifndef __COLORCUBE_HPP__
#define __COLORCUBE_HPP__

#include "Object3D.hpp"
#include "OpenGLShader.hpp"

class ColorCube : public Object3D
{
	public:
		/**
		 * Initialises the 3D object
		 *
		 * @returns	true if the object was initialised or false otherwise
		 */
		bool init();

		/**
		 * Renders the object by using graphic API commands
		 *
		 * @param projection	Projection matrix
		 * @param view			View matrix
		 *
		 * @returns	true if the object was rendered or false otherwise
		 */
		bool render(const glm::mat4 &projection, const glm::mat4 &view);

		/**
		 * Destroys the object by deinitilising it
		 *
		 * @returns	true if the object was destroyed or false otherwise
		 */
		bool destroy();

	private:
		/**
		 * Shader
		 */
		Shader *_shader;

		/**
		 * Vertex array object ID
		 */
		uint32_t _gVAO;

		/**
		 * Vertex buffer object for vertices
		 */
		uint32_t _verticesVBO;

		/**
		 * Vertex buffer object for colors
		 */
		uint32_t _colorsVBO;

		/**
		 * Vertex buffer object for indices
		 */
		uint32_t _indicesVBO;
};
#endif
