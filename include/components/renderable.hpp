#include <memory>
#include <set>
#include <map>

#include "../proto/components.pb.h"

namespace tec {
	class Shader;
	class MeshFile;
	class VertexBufferObject;
	struct VertexGroup;
	struct ReflectionComponent;

	struct Renderable {
		Renderable(std::shared_ptr<VertexBufferObject> buf,
			std::shared_ptr<Shader> shader = nullptr);
		Renderable() {

		}

		static ReflectionComponent Reflection(Renderable* val);

		void Out(proto::Component* target);
		void In(const proto::Component& source);

		std::set<VertexGroup*> vertex_groups;
		std::shared_ptr<VertexBufferObject> buffer;
		std::string mesh_name;
		std::shared_ptr<MeshFile> mesh;
		std::string shader_name;
		std::shared_ptr<Shader> shader;
		bool hidden = false;
	};
}
