/**
 * @class	Renderer
 * @brief	Interface for software/hardware renderers
 *
 * @author	Roberto Sosa Cano
 */

#ifndef __RENDERER_HPP__
#define __RENDERER_HPP__

#include <string>
#include <glm/glm.hpp>
#include "Object3D.hpp"
#include "Shader.hpp"

class Renderer
{
	public:
		/**
		 * Singleton
		 */
		static Renderer *GetRenderer(void);

		/**
		 * Shader factory
		 */
		virtual Shader * getShader(void) = 0;

		/**
		 * Destructor
		 */
		virtual ~Renderer() {}

		/**
		 * Initializes the renderer
		 */
		virtual void init(void) = 0;

		/**
		 * Updates the display contents
		 *
		 * @param projection	Projection matrix
		 * @param view			View matrix
		 */
		virtual bool render(const glm::mat4 &projection, const glm::mat4 &view) = 0;

		/**
		 * Adjusts the renderer's display size
		 */
		virtual bool resize(uint16_t width, uint16_t height) = 0;

		/**
		 * Adds a new 3D object to be rendered
		 */
		virtual bool addObject(Object3D *object) = 0;

	private:
		/**
		 * Singleton instance
		 */
		static Renderer *_renderer;
};

#endif
