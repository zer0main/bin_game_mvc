/*
 * Copyright (C) 2014-2016 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

#include <stdlib.h>
#include <time.h>

#include "BotView.hpp"

int main(int argc, char* argv[]) {
    srand(time(NULL));
    BotView bot_view;
    bot_view.view();
    return 0;
}
