#pragma once

namespace app
{
	namespace def
	{
		typedef unsigned short int AccountID;

		static const AccountID _EM_ =		0b000;
		static const AccountID _GRAPHIC_ =	0b001;
		static const AccountID _FSM_ =		0b010;
		static const AccountID _CM_ =		0b011;
		static const AccountID _LOGIC_ =	0b100;
	}
}