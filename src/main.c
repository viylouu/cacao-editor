#include <core/engine.h>
#include <core/renderer/renderer.h>

void init(void) {}
void update(void) {}

void render(void) {
    cc_rendererClear(.2,.3,.4,1);

    cc_rendererSetTint(1,0,0,1);
    cc_rendererDrawRect(0,0,64,64);
}

void clean(void) {}

int main(void) {
    return cc_engineMain(
        "MAIN",
        800, 600,
        init, update,
        render, clean
        );
}

