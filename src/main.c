#include <core/engine.h>
#include <core/renderer/renderer.h>
#include <core/macros/macros.h>
#include <core/types/text.h>


struct {
    struct {
        f32 base[4];
        f32 text[4];
        f32 highlight[4];
    } theme;
} intf;

#define SET_THEME(type, r,g,b,a) \
    intf.theme.type[0] = r / 255.f; \
    intf.theme.type[1] = g / 255.f; \
    intf.theme.type[2] = b / 255.f; \
    intf.theme.type[3] = a / 255.f

#define GET_THEME(type) \
    intf.theme.type[0], intf.theme.type[1], intf.theme.type[2], intf.theme.type[3]

CCfont* font;


void init(void) {
    font = cc_textLoadFont("data/eng/font.png");

    // load default palette
    SET_THEME(base, 32, 46, 55, 255);
    SET_THEME(text, 235, 237, 233, 255);
    SET_THEME(highlight, 57, 74, 80, 255);
}

void update(void) {}

void render(void) {
    cc_rendererClear(.2,.3,.4,1);

    //cc_rendererSetTint(1,0,0,1);
    //cc_rendererDrawRect(0,0,64,64);

    cc_rendererSetTint(GET_THEME(base));
    cc_rendererDrawRect(0,0,1440,20);
    cc_rendererDrawRect(0,0, 256,2560);

    cc_rendererSetTint(GET_THEME(highlight));
    cc_rendererDrawRect(0,20,1440,2);

    cc_rendererSetTint(GET_THEME(text));
    cc_textDrawText(font, "cacao-editor INDEV", 2, 2,2);
}

void clean(void) {
    cc_textUnloadFont(font);
}

int main(void) {
    return cc_engineMain(
        "MAIN",
        800, 600,
        init, update,
        render, clean
        );
}

