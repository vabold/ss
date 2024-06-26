#ifndef NW4R_SND_SEQ_SOUND_HANDLE_H
#define NW4R_SND_SEQ_SOUND_HANDLE_H
#include "common.h"
#include "snd_SoundHandle.h"

namespace nw4r {
namespace snd {
using namespace detail;

struct SeqSoundHandle {
    detail::SeqSound *mSound; // at 0x0

    SeqSoundHandle(SoundHandle *);
    void DetachSound();
};
} // namespace snd
} // namespace nw4r

#endif
