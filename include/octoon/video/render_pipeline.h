#ifndef OCTOON_RENDER_PIPELINE_H_
#define OCTOON_RENDER_PIPELINE_H_

#include <octoon/camera/camera.h>
#include <octoon/geometry/geometry.h>
#include <octoon/material/material.h>

#include <octoon/video/render_context.h>

namespace octoon::video
{
	class OCTOON_EXPORT RenderPipeline final
	{
	public:
		RenderPipeline() noexcept;
		RenderPipeline(const material::MaterialPtr& material, const RenderProfile& context) noexcept;
		virtual ~RenderPipeline() noexcept;

		void setMaterial(const material::MaterialPtr& material, const RenderProfile& context) noexcept;
		const material::MaterialPtr& getMaterial() const noexcept;

		const hal::GraphicsPipelinePtr& getPipeline() const noexcept;
		const hal::GraphicsDescriptorSetPtr& getDescriptorSet() const noexcept;

		void update(const camera::Camera& camera, const geometry::Geometry& geometry, const RenderProfile& context) noexcept;

	private:
		void updateParameters() noexcept;
		void updateMaterial(const material::MaterialPtr& material, const RenderProfile& context) noexcept(false);

		void setupProgram(const material::MaterialPtr& material, const RenderProfile& context);
		void setupRenderState(const material::MaterialPtr& material);

		void parseIncludes(std::string& shader);
		void replaceLightNums(std::string& shader, const LightModule& parameters);

	private:
		RenderPipeline(const RenderPipeline&) = delete;
		RenderPipeline& operator=(const RenderPipeline&) = delete;

	private:
		material::MaterialPtr material_;

		hal::GraphicsProgramPtr program_;
		hal::GraphicsPipelinePtr pipeline_;
		hal::GraphicsStatePtr renderState_;
		hal::GraphicsDescriptorSetPtr descriptorSet_;

		hal::GraphicsUniformSetPtr ambientLightColor_;
		hal::GraphicsUniformSetPtr directionalLights_;
		hal::GraphicsUniformSetPtr pointLights_;
		hal::GraphicsUniformSetPtr spotLights_;
		hal::GraphicsUniformSetPtr rectAreaLights_;
		hal::GraphicsUniformSetPtr hemisphereLights_;
		hal::GraphicsUniformSetPtr flipEnvMap_;
		hal::GraphicsUniformSetPtr envMap_;
		hal::GraphicsUniformSetPtr envMapIntensity_;

		hal::GraphicsUniformSetPtr viewMatrix_;
		hal::GraphicsUniformSetPtr viewProjMatrix_;
		hal::GraphicsUniformSetPtr normalMatrix_;
		hal::GraphicsUniformSetPtr modelMatrix_;
		hal::GraphicsUniformSetPtr modelViewMatrix_;
		hal::GraphicsUniformSetPtr projectionMatrix_;

		std::vector<hal::GraphicsUniformSetPtr> directionalShadowMaps_;
		std::vector<hal::GraphicsUniformSetPtr> directionalShadowMatrixs_;
	};
}

#endif