/*
 * Copyright (C) 2014-2015 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

#ifndef GAME_MODES_HPP_
#define GAME_MODES_HPP_

#include "Exception.hpp"
#include "checker.hpp"
#include "points.hpp"
#include "game_desk.hpp"

class GameController {
public:
    /** Create new instance.
    \param desk Model that will be changeable by
    GameController
    */
    static GameController* make(GameDesk* desk);

    void setDesk(int desk_size);

    void replace(Points& points);

private:
    GameDesk* desk_;

    /* Set new random number (1 or 2) in cell with
    coordinates specified in point argument
    */
    void newRandomNumber(const Point& point);

    /* Move all the numbers from current column down
    using free space (merge space)
    */
    void gravity(Point& free_space);

    GameController();
};

#endif

