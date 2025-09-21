#pragma once

#ifdef __cplusplus

namespace Ego {
namespace GUI {

struct DrawingContext {
    DrawingContext();
    DrawingContext(bool useDerived);
    ~DrawingContext();
    bool useDerived;
};

} // namespace GUI
} // namespace Ego

#endif
