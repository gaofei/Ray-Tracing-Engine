// File: space.hh
// Date: Sun Apr 07 16:55:08 2013 +0800
// Author: Yuxin Wu <ppwwyyxxc@gmail.com>

#pragma once

#include <vector>
#include <memory>

#include "renderable/light.hh"
class Space {
	private:
		std::vector<std::shared_ptr<Light>>  lights;
		std::vector<std::shared_ptr<RenderAble>> objs;

		int max_depth = MAX_RECURSIVE_DEPTH;
		int now_ray_count;
		Color ambient;		// ambient in this space

	public:
		Space(){ }

		~Space(){}

		void add_light(const Light& light)
		{ lights.push_back(std::make_shared<Light>(light)); }

		void add_obj(const std::shared_ptr<RenderAble>& objptr)
		{ objs.push_back(objptr); }

		void init();

		Color trace(const Ray& ray, real_t dist = 0, int depth = 0);

		real_t weight_threshold = DEFAULT_TRACING_WEIGHT_THRESHOLD;

	protected:
		std::shared_ptr<Trace> find_first(const Ray& ray) const;

		bool find_any(const Ray& ray, real_t dist) const; // is there any obj on the ray within the dist?
};

