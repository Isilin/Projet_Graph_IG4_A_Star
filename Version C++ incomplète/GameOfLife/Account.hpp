#pragma once

#include "Communicable.hpp"

namespace core
{
	namespace com
	{
		class Account : public Communicable
		{
		public:
			Account(const app::def::AccountID idAccountIn);
			~Account();

			void receiveMessage();
			const app::def::AccountID getId() const;

			void processMessages();

		protected:
			virtual void process(std::shared_ptr<AbstractMessage> messageIn) = 0;

		private:
			app::def::AccountID idAccount;
			std::queue<std::shared_ptr<AbstractMessage>> waitingMessages;
		};
	}
}