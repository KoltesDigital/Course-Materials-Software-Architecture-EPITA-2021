#pragma once

namespace engine
{
	namespace backend
	{
		struct Position
		{
			int row;
			int column;

			Position()
				: row{ 0 }
				, column{ 0 }
			{}

			Position(int r, int c)
				: row{ r }
				, column{ c }
			{}

			bool operator ==(const Position& other) const
			{
				return row == other.row
					&& column == other.column;
			}
		};
	}
}
