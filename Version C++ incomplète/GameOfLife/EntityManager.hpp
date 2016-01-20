#pragma once

#include <queue>
#include <vector>
#include <utility>
#include <algorithm>

#include "Account.hpp"

namespace core
{
	namespace ecs
	{
		class EntityManager : public core::com::Account
		{
		public:
			EntityManager();
			~EntityManager();

			int addEntity();
			void deleteEntity(const int idIn);
			void deleteEntities(const std::vector<int>& listIdIn);

		protected:
			virtual void process(std::shared_ptr<core::com::AbstractMessage> messageIn);

		private:
			std::queue<int> freeId;
			std::vector<int> entities;

			void broadcastDeletingEntity(const int idIn);
		};
	}
}