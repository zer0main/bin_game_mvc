#include "ioview.hpp"

int IoView::getDeskSize() {
    return getDeskSize_impl();
}

int IoView::getWinNumber() {
    return getWinNumber_impl();
}

int IoView::getTimeNumber() {
    return getTimeNumber_impl();
}

Points IoView::getIndex() {
    return getIndex_impl();
}

void IoView::typeError() {
    typeError_impl();
}

void IoView::setDesk(const GameDesk* desk) {
    desk_ = desk;
}

void IoView::output() {
    output_impl();
}

void IoView::indexError() {
    indexError_impl();
}

void IoView::finish(bool check_fail, long long int score) {
    finish_impl(check_fail, score);
}

void IoView::sendHelpMessage() {
    sendHelpMessage_impl();
}
