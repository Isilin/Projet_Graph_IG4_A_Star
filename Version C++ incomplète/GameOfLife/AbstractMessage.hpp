#pragma once

#include "Message.inl"

namespace core
{
	namespace com
	{
		class AbstractMessage
		{
		public:
			AbstractMessage(const app::def::MessageID messageIn);
			virtual ~AbstractMessage();

			const app::def::MessageID getMessage() const;

		protected:
			app::def::MessageID message;
		};
	}
}
