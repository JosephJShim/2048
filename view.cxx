#include "view.hxx"

using Color = ge211::Color;
using Sprite_set = ge211::Sprite_set;

static int const squareSize = 100;
static int const boardSize = 4 * squareSize;

ge211::Color const color_2 {238, 228, 218};
ge211::Color const color_4 {235, 214, 197};
ge211::Color const color_8 {225, 181, 134};
ge211::Color const color_16 {221, 162, 124};
ge211::Color const color_32 {216, 141, 105};
ge211::Color const color_64 {226, 115, 70};
ge211::Color const color_128 {230, 203, 131};
ge211::Color const color_256 {224, 195, 91};
ge211::Color const color_512 {235, 195, 71};
ge211::Color const color_1024 {225, 187, 60};
ge211::Color const color_2048 {223, 186, 45};

View::View(Model const& model)
        : model_(model),
          board_sprite{{boardSize, boardSize + squareSize}, Color::black()},
          sprite_2 {{squareSize, squareSize}, color_2},
          sprite_4 {{squareSize, squareSize}, color_4},
          sprite_8 {{squareSize, squareSize}, color_8},
          sprite_16 {{squareSize, squareSize}, color_16},
          sprite_32 {{squareSize, squareSize}, color_32},
          sprite_64 {{squareSize, squareSize}, color_64},
          sprite_128 {{squareSize, squareSize}, color_128},
          sprite_256 {{squareSize, squareSize}, color_256},
          sprite_512 {{squareSize, squareSize}, color_512},
          sprite_1024 {{squareSize, squareSize}, color_1024},
          sprite_2048 {{squareSize, squareSize}, color_2048}
{ }

void
View::draw(ge211::Sprite_set& set)
{
    // This needs to do something!
    set.add_sprite(board_sprite, {0,0}, 0);
    /*for (Block b : model_.get_blocks()) {
        add_number_sprite(set, b.get_value(), board_to_screen(b.get_pos()));
    }*/
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (model_.get_blocks()[i][j] != 0) {
                add_sprites(set, model_.get_blocks()[i][j], board_to_screen
                        ({j, i}));
            }
        }
    }
    ge211::Text_sprite::Builder q_builder(sans16);
    q_builder << "q to quit";
    q_sprite.reconfigure(q_builder);
    set.add_sprite(q_sprite, {boardSize/4, boardSize + squareSize/2}, 3);
    ge211::Text_sprite::Builder r_builder(sans16);
    r_builder << "r to restart";
    r_sprite.reconfigure(r_builder);
    set.add_sprite(r_sprite, {boardSize/100, boardSize + squareSize/2}, 3);
    ge211::Text_sprite::Builder p_builder(sans16);
    p_builder << "p to win";
    win_sprite.reconfigure(p_builder);
    set.add_sprite(win_sprite, {squareSize * 3, boardSize + squareSize/2},
                   3);
}

/// function that takes a number. with that number, it then adds to the
// sprite set a rectangle sprite and text that represents that nukmber
void
View::add_sprites(Sprite_set& set, int num, ge211::Posn<int> pos)
{
    // display block sprite
    if (num == 2) {
        set.add_sprite(sprite_2, pos, 1);
        ge211::Text_sprite::Builder num_builder(sans15);
        num_builder << num;
        text_sprite[0].reconfigure(num_builder);
        set.add_sprite(text_sprite[0], {pos.x + squareSize/2, pos.y +
        squareSize/2},
        2);
    }
    if (num == 4) {
        set.add_sprite(sprite_4, pos, 1);
        ge211::Text_sprite::Builder num_builder(sans15);
        num_builder << num;
        text_sprite[1].reconfigure(num_builder);
        set.add_sprite(text_sprite[1], {pos.x + squareSize/2, pos.y +
        squareSize/2}, 2);
    }
    if (num == 8) {
        set.add_sprite(sprite_8, pos, 1);
        ge211::Text_sprite::Builder num_builder(sans15);
        num_builder << num;
        text_sprite[2].reconfigure(num_builder);
        set.add_sprite(text_sprite[2], {pos.x + squareSize/2, pos.y +
                                                              squareSize/2}, 2);
    }
    if (num == 16) {
        set.add_sprite(sprite_16, pos, 1);
        ge211::Text_sprite::Builder num_builder(sans15);
        num_builder << num;
        text_sprite[3].reconfigure(num_builder);
        set.add_sprite(text_sprite[3], {pos.x + squareSize/2, pos.y +
                                                              squareSize/2}, 2);
    }
    if (num == 32) {
        set.add_sprite(sprite_32, pos, 1);
        ge211::Text_sprite::Builder num_builder(sans15);
        num_builder << num;
        text_sprite[4].reconfigure(num_builder);
        set.add_sprite(text_sprite[4], {pos.x + squareSize/2, pos.y +
                                                              squareSize/2}, 2);
    }
    if (num == 64) {
        set.add_sprite(sprite_64, pos, 1);
        ge211::Text_sprite::Builder num_builder(sans15);
        num_builder << num;
        text_sprite[5].reconfigure(num_builder);
        set.add_sprite(text_sprite[5], {pos.x + squareSize/2, pos.y +
                                                              squareSize/2}, 2);
    }
    if (num == 128) {
        set.add_sprite(sprite_128, pos, 1);
        ge211::Text_sprite::Builder num_builder(sans15);
        num_builder << num;
        text_sprite[6].reconfigure(num_builder);
        set.add_sprite(text_sprite[6], {pos.x + squareSize/2, pos.y +
                                                              squareSize/2}, 2);
    }
    if (num == 256) {
        set.add_sprite(sprite_256, pos, 1);
        ge211::Text_sprite::Builder num_builder(sans15);
        num_builder << num;
        text_sprite[7].reconfigure(num_builder);
        set.add_sprite(text_sprite[7], {pos.x + squareSize/2, pos.y +
                                                              squareSize/2}, 2);
    }
    if (num == 512) {
        set.add_sprite(sprite_512, pos, 1);
        ge211::Text_sprite::Builder num_builder(sans15);
        num_builder << num;
        text_sprite[8].reconfigure(num_builder);
        set.add_sprite(text_sprite[8], {pos.x + squareSize/2, pos.y +
                                                              squareSize/2}, 2);
    }
    if (num == 1024) {
        set.add_sprite(sprite_1024, pos, 1);
        ge211::Text_sprite::Builder num_builder(sans15);
        num_builder << num;
        text_sprite[9].reconfigure(num_builder);
        set.add_sprite(text_sprite[9], {pos.x + squareSize/2, pos.y +
                                                              squareSize/2}, 2);
    }
    if (num == 2048) {
        set.add_sprite(sprite_2048, pos, 1);
        ge211::Text_sprite::Builder num_builder(sans15);
        num_builder << num;
        text_sprite[10].reconfigure(num_builder);
        set.add_sprite(text_sprite[10], {pos.x + squareSize/2, pos.y +
                                                              squareSize/2}, 2);
    }
    // display text sprite
    if (model_.game_over() == 2) {
        ge211::Text_sprite::Builder score_builder(sans15);
        score_builder << "W";
        score_sprite.reconfigure(score_builder);
        set.add_sprite(score_sprite, {boardSize/2, boardSize + squareSize/2}, 3);
    }
    else if (model_.game_over() == 1) {
        ge211::Text_sprite::Builder score_builder(sans15);
        score_builder << "L";
        score_sprite.reconfigure(score_builder);
        set.add_sprite(score_sprite, {boardSize/2, boardSize + squareSize/2}, 3);
    }
    else {
        ge211::Text_sprite::Builder score_builder(sans15);
        score_builder << model_.get_score();
        score_sprite.reconfigure(score_builder);
        set.add_sprite(score_sprite, {boardSize/2, boardSize + squareSize/2}, 3);
    }
}

ge211::Posn<int>
View::screen_to_board(ge211::Posn<int> pos) const
{
    return {pos.x / boardSize, pos.y / boardSize};
}

ge211::Posn<int>
View::board_to_screen(ge211::Posn<int> pos) const
{
    return {squareSize * pos.x, squareSize * pos.y};
}

View::Dimensions
View::initial_window_dimensions() const
{
    Dimensions dims = {boardSize, boardSize + squareSize};
    return dims;
}
