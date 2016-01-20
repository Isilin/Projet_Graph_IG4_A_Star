#pragma once

#include <memory>
#include <mutex>

#include "Office.hpp"
#include "AbstractMessage.hpp"
#include "Message.inl"

namespace core
{
	namespace com
	{
		class Communicable
		{
		public:
			Communicable();
			virtual ~Communicable();

			void sendMessage(const app::def::MessageID messageIn, const app::def::AccountID recipientIn);
			void sendMessage(const std::shared_ptr<AbstractMessage> messageIn, const app::def::AccountID recipientIn);
			template <class T> void sendMessage(const app::def::MessageID messageIn, T& valueIn, const app::def::AccountID recipientIn);
			void broadcast(const app::def::MessageID messageIn);
			void broadcast(const std::shared_ptr<AbstractMessage> messageIn);
			template <class T> void broadcast(const app::def::MessageID messageIn, T& valueIn);

			static void setOffice(std::weak_ptr<Office> officeIn, std::shared_ptr<std::mutex> lockOfficeIn);

		protected:
			static std::weak_ptr<Office> office;
			static std::shared_ptr<std::mutex> lockOffice;
		};
		template<class T>
		void Communicable::sendMessage(const app::def::MessageID messageIn, T & valueIn, const app::def::AccountID recipientIn)
		{
			this->sendMessage(std::shared_ptr<HeavyMessage<T>>(new HeavyMessage<T>(messageIn, valueIn)), recipientIn);
		}
		template<class T>
		void Communicable::broadcast(const app::def::MessageID messageIn, T & valueIn)
		{
			this->broadcast(std::shared_ptr<HeavyMessage<T>>(new HeavyMessage<T>(messageIn, valueIn)));
		}
	}
}