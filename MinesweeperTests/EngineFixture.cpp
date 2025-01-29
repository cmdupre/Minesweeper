#include "pch.h"
#include "../Minesweeper/Engine.h"

// https://github.com/google/googletest/blob/main/docs/primer.md

namespace MinesweeperTests
{
	class EngineFixture : public testing::Test
	{
	protected:
		void SetUp() override;
		void TearDown() override;
	};

	void EngineFixture::SetUp()
	{
	}

	void EngineFixture::TearDown()
	{
	}

	TEST_F(EngineFixture, GetIndexTest)
	{
		auto index = Engine::GetIndex(wxPoint(0, 0), 0);

		EXPECT_EQ(index, 0);
	}
}
