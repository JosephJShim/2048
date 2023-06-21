#include "controller.hxx"

Controller::Controller()
        : model_(),
          view_(model_)
{ }

void
Controller::draw(ge211::Sprite_set& set)
{
    view_.draw(set);
}

void
Controller::on_key(ge211::Key key)
{
    if (key == ge211::Key::up()) {
        model_.move(0);
    }
    else if (key == ge211::Key::right()) {
        model_.move(1);
    }
    else if (key == ge211::Key::down()) {
        model_.move(2);
    }
    else if (key == ge211::Key::left()) {
        model_.move(3);
    }
    else if (key == ge211::Key::code('r')) {
        model_.restart();
    }
    else if (key == ge211::Key::code('q')) {
        quit();
    }
    else if (key == ge211::Key::code('p')) {
        model_.opwingamelol();
    }
    else if (model_.game_over()) {
        quit();
    }
}
View::Dimensions
Controller::initial_window_dimensions() const
{
    return view_.initial_window_dimensions();
}