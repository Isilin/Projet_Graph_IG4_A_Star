#pragma once

namespace app
{
	namespace def
	{
		typedef unsigned short int MessageID;

		const MessageID _DELETE_ENTITY_ =	0b0000;
		const MessageID _CREATE_CASE_ =		0b0001;
		const MessageID _LOAD_FILE_ =		0b0010;
		const MessageID _SAVE_FILE_ =		0b0011;
		const MessageID _CHANGE_FILE_ =		0b0100;
		const MessageID _CHANGE_RENDER_ =	0b0101;
		const MessageID _CHANGE_STATE_ =	0b0110;
	}
}