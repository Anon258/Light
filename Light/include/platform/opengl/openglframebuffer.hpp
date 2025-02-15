#ifndef __OPENGLFRAMEBUFFER_H__
#define __OPENGLFRAMEBUFFER_H__

#include "core/base.hpp"
#include "rendering/framebuffer.hpp"

namespace Light
{
	class OpenGLFramebuffer : public Framebuffer
	{
	public:
		OpenGLFramebuffer(const FramebufferSpec& spec);
		~OpenGLFramebuffer();

		inline const FramebufferSpec& getSpec() const override { return spec; }

		void bind() override;
		void unbind() override;

		void invalidate();
		void resize(uint32_t width, uint32_t height) override;

		inline uint32_t getColorAttachmentRendererId() const override { return colorAttachment; }

	private:
		FramebufferSpec spec;

		uint32_t rendererId = 0;
		uint32_t colorAttachment;
		uint32_t depthAttachment;
	};

}

#endif // __OPENGLFRAMEBUFFER_H__