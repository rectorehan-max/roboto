#pragma once

class Loadable {

protected:
    Loadable();

    bool requestLoad;
    bool loaded;

public:
    void requestToLoad();
    void finishedLoading();
    void resetLoadingState();

    bool hasRequestedToLoad();
    bool isLoaded();

    bool isValidLoad();

    virtual ~Loadable() = default;
};
