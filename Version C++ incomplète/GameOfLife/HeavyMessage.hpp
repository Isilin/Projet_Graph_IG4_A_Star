#pragma once

#include "Message.hpp"

namespace core
{
	namespace com
	{
		template<typename T>
		class HeavyMessage : public Message
		{
		public:
			HeavyMessage(const app::def::MessageID messageIn, const T parameterIn);
			~HeavyMessage();

			const T getParameter() const;
		private:
			T parameter;
		};

		template<typename T>
		HeavyMessage<T>::HeavyMessage(const app::def::MessageID messageIn, const T parameterIn) : Message(messageIn), parameter(parameterIn)
		{
		}

		template<typename T>
		HeavyMessage<T>::~HeavyMessage()
		{
		}

		template<typename T>
		const T HeavyMessage<T>::getParameter() const
		{
			return this->parameter;
		}
	}
}
