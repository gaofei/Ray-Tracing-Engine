// File: space.hh
// Date: Fri Jun 21 18:58:51 2013 +0800
// Author: Yuxin Wu <ppwwyyxxc@gmail.com>

#pragma once

#include <vector>
#include <memory>

#include "renderable/renderable.hh"
#include "kdtree.hh"
#include "common.hh"
using std::vector;
using std::shared_ptr;
using std::make_shared;

class Space {
	private:
		vector<shared_ptr<Light>>  lights;
		vector<rdptr> objs;

		int max_depth = MAX_RECURSIVE_DEPTH;
		int now_ray_count;
		Color ambient;		// ambient in this space

		Vec bound_min = Vec::max(), bound_max = -Vec::max();

	public:
		// config
		bool use_tree = true;
		bool use_soft_shadow = false;

		Space(){ }

		~Space(){}

		void add_light(const Light& light);

		void add_obj(const rdptr& objptr);

		void add_obj(Renderable* objptr) { add_obj(rdptr(objptr)); }

		// useful, keep lights
		void clear()
		{ objs.clear(); bound_min = Vec::max(), bound_max = -Vec::max(); }

		void finish();

		Color trace(const Ray& ray, real_t dist = 0, int depth = 0) const;

		real_t weight_threshold = DEFAULT_TRACING_WEIGHT_THRESHOLD;

	protected:
		shared_ptr<Trace> find_first(const Ray& ray) const;

		bool find_any(const Ray& ray, real_t dist) const; // is there any obj on the ray within the dist?
};

