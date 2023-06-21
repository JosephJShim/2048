#include "model.hxx"

using namespace ge211;

Model::Model()
{
    //TODO: randomly generate 2 new blocks
    //blocks.push_back(generate_block());
    //blocks.push_back(generate_block());
    score = 0;
    generate_block();
    generate_block();
}

int
Model::move(int dir)
{
    bool valid = false;
    shift_blocks(dir, valid);
    combine_blocks(dir, valid);
    if (valid) {
        shift_blocks(dir, valid);
        generate_block();
    }
    if (!valid) {
        return 1;
    }
    return 0;
}

bool
Model::combine_blocks(int dir, bool& valid)
{
    if (dir == 0) {
        for (int j = 0; j < 4; j++) {
            for (int i = 0; i < 3; i++) {
                if ((blocks[i][j] != 0) && (blocks[i][j] == blocks[i+1][j])) {
                    valid = true;
                    blocks[i][j] *= 2;
                    blocks[i+1][j] = 0;
                    score += blocks[i][j];
                }
            }
        }
    }
    if (dir == 1) {
        for (int i = 0; i < 4; i++) {
            for (int j = 3; j >= 1; j--) {
                if ((blocks[i][j] != 0) && (blocks[i][j] == blocks[i][j-1])) {
                    valid = true;
                    blocks[i][j] *= 2;
                    blocks[i][j-1] = 0;
                    score += blocks[i][j];
                }
            }
        }
    }
    if (dir == 2) {
        for (int j = 0; j < 4; j++) {
            for (int i = 3; i >= 1; i--) {
                if ((blocks[i][j] != 0) && (blocks[i][j] == blocks[i-1][j])) {
                    valid = true;
                    blocks[i][j] *= 2;
                    blocks[i-1][j] = 0;
                    score += blocks[i][j];
                }
            }
        }
    }
    if (dir == 3) {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 3; j++) {
                if ((blocks[i][j] != 0) && (blocks[i][j] == blocks[i][j+1])) {
                    valid = true;
                    blocks[i][j] *= 2;
                    blocks[i][j+1] = 0;
                    score += blocks[i][j];
                }
            }
        }
    }
    return valid;
}

bool
Model::shift_blocks(int dir, bool& valid)
{
    if (dir == 0) {
        for (int j = 0; j < 4; j++) {
            for (int i = 0; i < 4; i++) {
                if (blocks[i][j] == 0) {
                    for (int k = i + 1; k < 4; k++) {
                        if (blocks[k][j] != 0) {
                            valid = true;
                            blocks[i][j] = blocks[k][j];
                            blocks[k][j] = 0;
                            break;
                        }
                    }
                }
            }
        }
    }
    if (dir == 1) {
        for (int i = 0; i < 4; i++) {
            for (int j = 3; j >= 0; j--) {
                if (blocks[i][j] == 0) {
                    for (int k = j - 1; k >= 0; k--) {
                        if (blocks[i][k] != 0) {
                            valid = true;
                            blocks[i][j] = blocks[i][k];
                            blocks[i][k] = 0;
                            break;
                        }
                    }
                }
            }
        }
    }
    if (dir == 2) {
        for (int j = 0; j < 4; j++) {
            for (int i = 3; i >= 0; i--) {
                if (blocks[i][j] == 0) {
                    for (int k = i - 1; k >= 0; k--) {
                        if (blocks[k][j] != 0) {
                            valid = true;
                            blocks[i][j] = blocks[k][j];
                            blocks[k][j] = 0;
                            break;
                        }
                    }
                }
            }
        }
    }
    if (dir == 3) {
        for (int j = 0; j < 4; j++) {
            for (int i = 0; i < 4; i++) {
                if (blocks[i][j] == 0) {
                    for (int k = j + 1; k < 4; k++) {
                        if (blocks[i][k] != 0) {
                            valid = true;
                            blocks[i][j] = blocks[i][k];
                            blocks[i][k] = 0;
                            break;
                        }
                    }
                }
            }
        }
    }
    return valid;
}

void
Model::generate_block()
{
    //TODO
    int newval;
    if (rand() % 2 == 0) {
        newval = 2;
    }
    else {
        newval = 4;
    }
    std::vector<Posn<int>> empty_pos;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (blocks[i][j] == 0) {
                empty_pos.push_back({i,j});
            }
        }
    }

    int randInd = rand() % empty_pos.size();
    blocks[empty_pos[randInd].x][empty_pos[randInd].y] = newval;
}

int
Model::game_over() const
{
    //TODO
    bool val = false;
    int count = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (blocks[i][j] == 2048) {
                //win
                return 2;
            }
        }
    }
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (j != 0) {
                if (blocks[i][j-1] == blocks[i][j]) {
                    val = true;
                }
            }
            if (j != 3) {
                if (blocks[i][j+1] == blocks[i][j]) {
                    val = true;
                }
            }
            if (i != 0) {
                if (blocks[i-1][j] == blocks[i][j]) {
                    val = true;
                }
            }
            if (i != 3) {
                if (blocks[i+1][j] == blocks[i][j]) {
                    val = true;
                }
            }
            if (blocks[i][j] != 0) {
                count += 1;
            }
        }
    }
    if (!val && count == 16) {
        //lose
        return 1;
    }
    return 0;
}


void
Model::restart()
{
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            blocks[i][j] = 0;
        }
    }
    score = 0;
    generate_block();
    generate_block();
}

int
Model::get_score() const
{
    return score;
}

std::array<std::array<int, 4>, 4>
Model::get_blocks() const
{
    return blocks;
}

void
Model::opwingamelol()
{
    blocks[1][1] = 2048;
}

void
Model::set_block(int val, int x, int y)
{
    blocks[y][x] = val;
}

