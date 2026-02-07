#include "tool/loadable.h"

Loadable::Loadable() {
    loaded = false;
    requestLoad = false;
}

void Loadable::requestToLoad() {
    if (loaded) return;
    requestLoad = true;
}

void Loadable::finishedLoading() {
    loaded = true;
}

void Loadable::resetLoadingState() {
    loaded = false;
    requestLoad = false;
}

bool Loadable::hasRequestedToLoad() {
    return requestLoad;
}

bool Loadable::isLoaded() {
    return loaded;
}

bool Loadable::isValidLoad() {
    return requestLoad && !loaded;
}
