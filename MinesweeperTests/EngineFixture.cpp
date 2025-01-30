#include "pch.h"
#include "../Minesweeper/Engine.h"

// https://github.com/google/googletest/blob/main/docs/primer.md

class EngineFixture : public testing::Test
{
};

TEST_F(EngineFixture, GetIndex_ReturnsCorrectIndexForValidParameters)
{
	auto index = Engine::GetIndex(wxPoint(0, 0), 10, 10);

	EXPECT_EQ(index, 0);

	index = Engine::GetIndex(wxPoint(1, 1), 10, 10);

	EXPECT_EQ(index, 11);

	index = Engine::GetIndex(wxPoint(9, 9), 10, 10);

	EXPECT_EQ(index, 99);
}

TEST_F(EngineFixture, GetIndex_ReturnZeroForInvalidHorizontalMax)
{
	auto index = Engine::GetIndex(wxPoint(0, 0), 0, 10);

	EXPECT_EQ(index, 0);

	index = Engine::GetIndex(wxPoint(0, 0), 100000, 10);

	EXPECT_EQ(index, 0);
}

TEST_F(EngineFixture, GetIndex_ReturnZeroForInvalidPoint)
{
	auto index = Engine::GetIndex(wxPoint(-1, 1), 10, 10);

	EXPECT_EQ(index, 0);

	index = Engine::GetIndex(wxPoint(1, -1), 10, 10);

	EXPECT_EQ(index, 0);

	index = Engine::GetIndex(wxPoint(10, 1), 10, 10);

	EXPECT_EQ(index, 0);

	index = Engine::GetIndex(wxPoint(1, 10), 10, 10);

	EXPECT_EQ(index, 0);
}

TEST_F(EngineFixture, GetCell_ReturnsCorrectCellForValidIndex)
{
	auto cell = Engine::GetCell(0, 10, 10);

	EXPECT_EQ(cell, wxPoint(0, 0));

	cell = Engine::GetCell(11, 10, 10);

	EXPECT_EQ(cell, wxPoint(1, 1));

	cell = Engine::GetCell(99, 10, 10);

	EXPECT_EQ(cell, wxPoint(9, 9));
}

TEST_F(EngineFixture, GetCell_ReturnsZeroForInvalidIndex)
{
	auto cell = Engine::GetCell(-1, 10, 10);

	EXPECT_EQ(cell, wxPoint(0, 0));

	cell = Engine::GetCell(100, 10, 10);

	EXPECT_EQ(cell, wxPoint(0, 0));
}

TEST_F(EngineFixture, GetNeighbors_ReturnsCorrectValueForValidParameters)
{
	auto neighbors = Engine::GetNeighbors(wxPoint(0, 0), 10, 10);

	EXPECT_EQ(neighbors.size(), 3);
	EXPECT_EQ(neighbors.at(0), wxPoint(0, 1));
	EXPECT_EQ(neighbors.at(1), wxPoint(1, 0));
	EXPECT_EQ(neighbors.at(2), wxPoint(1, 1));

	neighbors = Engine::GetNeighbors(wxPoint(9, 9), 10, 10);

	EXPECT_EQ(neighbors.size(), 3);
	EXPECT_EQ(neighbors.at(0), wxPoint(8, 8));
	EXPECT_EQ(neighbors.at(1), wxPoint(8, 9));
	EXPECT_EQ(neighbors.at(2), wxPoint(9, 8));

	neighbors = Engine::GetNeighbors(wxPoint(4, 4), 10, 10);

	EXPECT_EQ(neighbors.size(), 8);
	EXPECT_EQ(neighbors.at(0), wxPoint(3, 3));
	EXPECT_EQ(neighbors.at(1), wxPoint(3, 4));
	EXPECT_EQ(neighbors.at(2), wxPoint(3, 5));
	EXPECT_EQ(neighbors.at(3), wxPoint(4, 3));
	EXPECT_EQ(neighbors.at(4), wxPoint(4, 5));
	EXPECT_EQ(neighbors.at(5), wxPoint(5, 3));
	EXPECT_EQ(neighbors.at(6), wxPoint(5, 4));
	EXPECT_EQ(neighbors.at(7), wxPoint(5, 5));
}

TEST_F(EngineFixture, GetNeighbors_ReturnsEmptyVectorForInvalidParameters)
{
}