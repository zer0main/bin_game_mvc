/*
 * Copyright (C) 2014-2015 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

#include <stdlib.h>
#include <time.h>

#include "ConsoleView.hpp"

int main(int argc, char* argv[]) {
    srand(time(NULL));
    ConsoleView console_view;
    console_view.view();
    return 0;
}
