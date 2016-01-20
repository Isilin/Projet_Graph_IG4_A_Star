#pragma once

#include <map>
#include <queue>
#include <memory>

#include "AbstractMessage.hpp"
#include "OfficeAccount.inl"

namespace core
{
	namespace com
	{
		class Office
		{
		public:
			Office();
			~Office();

			void registerAccount(const app::def::AccountID accountIn);
			void distributeMessage(std::shared_ptr<AbstractMessage> messageIn, const app::def::AccountID recipientIn);
			void broadcastMessage(std::shared_ptr<AbstractMessage> messageIn);
			bool isNewMessages(const app::def::AccountID accountIn);
			std::shared_ptr<AbstractMessage> withdrawMessage(const app::def::AccountID accountIn);

		private:
			std::map<app::def::AccountID, std::queue<std::shared_ptr<AbstractMessage>>> mailbox;
		};
	}
}
