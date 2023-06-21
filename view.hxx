#pragma once

#include "model.hxx"

class View
{
public:
    /// View dimensions will use `int` coordinates.
    using Dimensions = ge211::Dims<int>;

    /// View positions will use `int` coordinates.
    using Position = ge211::Posn<int>;

    /// View rectangles will use `int` coordinates.
    using Rectangle = ge211::Rect<int>;
    explicit View(Model const& model);
    void draw(ge211::Sprite_set& set);

    ge211::Posn<int>
    screen_to_board(ge211::Posn<int> screen_pos) const;

    ge211::Posn<int>
    board_to_screen(ge211::Posn<int> board_pos) const;

    void add_sprites(ge211::Sprite_set& set, int num, ge211::Posn<int>
            pos);
    Dimensions initial_window_dimensions() const;

private:
    Model const& model_;
    ge211::Rectangle_sprite const board_sprite;
    ge211::Rectangle_sprite const sprite_2;
    ge211::Rectangle_sprite const sprite_4;
    ge211::Rectangle_sprite const sprite_8;
    ge211::Rectangle_sprite const sprite_16;
    ge211::Rectangle_sprite const sprite_32;
    ge211::Rectangle_sprite const sprite_64;
    ge211::Rectangle_sprite const sprite_128;
    ge211::Rectangle_sprite const sprite_256;
    ge211::Rectangle_sprite const sprite_512;
    ge211::Rectangle_sprite const sprite_1024;
    ge211::Rectangle_sprite const sprite_2048;
    ge211::Font sans15{"sans.ttf", 30};
    ge211::Font sans16{"sans.ttf", 16};
    ge211::Text_sprite text_sprite[12];
    ge211::Text_sprite score_sprite;
    ge211::Text_sprite q_sprite;
    ge211::Text_sprite r_sprite;
    ge211::Text_sprite win_sprite;
};
