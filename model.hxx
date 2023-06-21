#pragma once

#include <ge211.hxx>

#include <iostream>
#include <vector>
#include <array>


class Model
{
public:
    Model();
    /// Model dimensions will use `int` coordinates, as board dimensions do.
    //shift blocks (main thing, make helpers for this)
    //1. moves the blocks, combines if needed
    //2. generates a random block
    //void shift_all_blocks(int dir);
    //shifting only one
    //void shift_one_block(Block b, int dir);
    //randomly generate a block to place
    void generate_block();
    //combine block
    int move(int dir);
    bool combine_blocks(int dir, bool& valid);
    bool shift_blocks(int dir, bool& valid);
    //bool for ending game
    int game_over() const;
    //find positions that are empty
    //std::vector<Position> find_empty();
    void restart();
    //std::vector<Block> get_blocks() const;
    int get_score() const;
    std::array<std::array<int, 4>, 4> get_blocks() const;

    void opwingamelol();

    void set_block(int val, int x, int y);

private:
    //std::vector<Block> blocks;
    std::array<std::array<int, 4>, 4> blocks;
    int score;
};
