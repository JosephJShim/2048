#include "model.hxx"
#include <catch.hxx>

TEST_CASE("test win")
{
    Model m = Model();
    m.opwingamelol();
    CHECK(m.game_over() == 2);
}

TEST_CASE("test lose")
{
    Model m = Model();
    std::vector<int> vec;
    for (int i = 1; i < 17; i++) {
        vec.push_back(i);
    }
    int count = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            m.set_block(vec[count], i, j);
            count++;
        }
    }
    CHECK(m.game_over() == 1);
}

TEST_CASE("check score doubles")
{
    Model m = Model();
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            m.set_block(0, i, j);
        }
    }
    m.set_block(16, 0, 0);
    m.set_block(16, 0,1);
    m.move(0);

    CHECK(m.get_score() == 32);
}

TEST_CASE("shift a block up")
{
    Model m = Model();
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            m.set_block(0, i, j);
        }
    }
    m.set_block(16, 0, 3);
    m.move(0);
    CHECK(m.get_blocks()[0][0] == 16);
}

TEST_CASE("check only 2 or 4 generated")
{
    Model m = Model();
    m.restart();
    bool is2or4 = true;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if ((m.get_blocks()[i][j] != 2 && m.get_blocks()[i][j] != 4) && m
            .get_blocks()[i][j] != 0) {
                is2or4 = false;
            }
        }
    }
    CHECK(is2or4);

}

//
// TODO: Write preliminary model tests.
//
// These tests should demonstrate your functional requirements.
//