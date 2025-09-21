#include "GraphicsSystemNew.hpp"
#include "Display.hpp"
#include "DisplayMode.hpp"
#include "SDL/GraphicsSystemNew.hpp"
#include <algorithm>

namespace Ego {

Ego::GraphicsSystemNew *GraphicsSystemNewNewFunctor::operator()() const
{ return new Ego::SDL::GraphicsSystemNew(); }

void GraphicsSystemNewDeleteFunctor::operator()(GraphicsSystemNew *p) const
{ delete p; }

GraphicsSystemNew::GraphicsSystemNew()
{}

GraphicsSystemNew::~GraphicsSystemNew()
{}

const std::vector<std::shared_ptr<Display>>& GraphicsSystemNew::getDisplays() const
{
    return displays;
}

const std::string& GraphicsSystemNew::getDriverName() const
{
    return driverName;
}

} // namespace Ego

Log::Entry& operator<<(Log::Entry& logEntry, const Ego::GraphicsSystemNew& graphicsSystem)
{
    logEntry << "SDL video driver = " << graphicsSystem.getDriverName() << Log::EndOfLine;
    const auto& displays = graphicsSystem.getDisplays();
    const auto displayIt = std::find_if(displays.cbegin(), displays.cend(), [](const auto& display)
    {
        return display->isPrimaryDisplay();
    });
    if (displayIt != displays.cend())
    {
        logEntry << "\t" << "available fullscreen video modes:" << Log::EndOfLine;
        const auto& displayModes = (*displayIt)->getDisplayModes();
        if (!displayModes.empty())
        {
            logEntry << "\t" << "none" << Log::EndOfEntry;
        }
        else
        {
            for (const auto& displayMode : displayModes)
            {
                logEntry << "\t" << (*displayMode) << Log::EndOfLine;
            }
        }
    }
    return logEntry;
}
