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
    return typeError_impl();
}

void IoView::setDesk(const GameDesk* desk) {
    return setDesk_impl(desk);
}

void IoView::output() {
    return output_impl();
}

void IoView::indexError() {
    return indexError_impl();
}

void IoView::finish(bool check_fail, long long int score) {
    return finish_impl(check_fail, score);
}

void IoView::sendHelpMessage() {
    return sendHelpMessage_impl();
}
