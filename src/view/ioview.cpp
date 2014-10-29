#include "ioview.hpp"

IoView::IoView() {
}

IoView::~IoView() {
}

int IoView::getDeskSize() const {
    return getDeskSize_impl();
}

int IoView::getWinNumber() const {
    return getWinNumber_impl();
}

int IoView::getTimeNumber() const {
    return getTimeNumber_impl();
}

const GameDesk* IoView::getDesk() const {
    return desk_;
}

Points IoView::getIndex() const {
    return getIndex_impl();
}

void IoView::typeError() const {
    typeError_impl();
}

void IoView::setDesk(const GameDesk* desk) {
    desk_ = desk;
}

void IoView::output() const {
    output_impl();
}

void IoView::indexError() const {
    indexError_impl();
}

void IoView::finish(bool check_fail, int score, int steps_number) const {
    finish_impl(check_fail, score, steps_number);
}

void IoView::sendHelpMessage() const {
    sendHelpMessage_impl();
}

