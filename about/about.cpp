#include "about/about.hpp"
#include "app.hpp"

GolfScoreAbout::GolfScoreAbout(ViewDispatcher **viewDispatcher) : widget(nullptr), viewDispatcherRef(viewDispatcher)
{
    static constexpr const char AboutText[] =
        "Golf Scorecard " VERSION "\n"
        "Created by thodges.\n"
        "\n"
        "Round Setup:\n"
        "- Pick 1-4 players and 9/18 holes.\n"
        "- Edit pars or load/save course presets.\n"
        "- Save Round appends the current results to history.\n"
        "\n"
        "Scorecard:\n"
        "- Up/Down adjust strokes; Left/Right change holes.\n"
        "- OK cycles players; hold OK to clear the hole.\n"
        "- Back after every hole is filled shows the summary.\n";

    easy_flipper_set_widget(
        &widget, GolfScoreViewAbout, AboutText, callbackToSubmenu, viewDispatcherRef);
}

GolfScoreAbout::~GolfScoreAbout()
{
    if (widget && viewDispatcherRef && *viewDispatcherRef)
    {
        view_dispatcher_remove_view(*viewDispatcherRef, GolfScoreViewAbout);
        widget_free(widget);
        widget = nullptr;
    }
}

uint32_t GolfScoreAbout::callbackToSubmenu(void *context)
{
    UNUSED(context);
    return GolfScoreViewSubmenu;
}
