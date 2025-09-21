# Egoboo – macOS Resurrection (WIP 🚧)

Bringing a classic open-source dungeon crawler back to life on modern macOS.  
This repo is my battlefield – every red error, every failed compile, every linker nightmare – is part of the fight.

---

## ⚔️ My Mission
I, **Luca Huci**, am working to revive Egoboo on Apple Silicon and Intel macOS.  
It’s raw. It’s broken. But every mistake is progress. This isn’t just about fixing a game – it’s about proving audacity, resilience, and the will to *finish what others abandoned*.

---

## 🛠 Current State
- CMake configured for macOS
- SDL2 dependencies linked (`/usr/local/opt/sdl2`, SDL2_image, SDL2_mixer, SDL2_ttf, SDL2_net)
- Engine builds partially, but errors remain (iterator issues, linker symbols, bundle identifiers)
- Progress documented in commits

<<<<<<< Updated upstream
#### Appveyor CI Build Status
- [master](https://github.com/egoboo/egoboo/tree/master) branch Windows 11:
[![Build status](https://ci.appveyor.com/api/projects/status/7sjmdgolmvmv3hc1/branch/master?svg=true)](https://ci.appveyor.com/project/michaelheilmann-com/egoboo-windows/branch/master)
=======
Right now, it **does not compile fully**. That’s intentional – this repo is a live journal of the process.

---

## 📖 The Journey
Every error fixed is logged in commits:
- Removed duplicate `set_project_default_properties`
- Battling `transform_iterator.hpp` template issues
- Linking SDL2_net (_SDL_GetError, _SDL_SetError, _SDL_vsnprintf)
- Wrestling with Xcode bundle identifiers

Follow along. Admire the chaos. Suggest fixes. Or just watch me struggle gloriously.

---

## 🚧 Roadmap
- [ ] Fix idlib `transform_iterator` template errors
- [ ] Resolve SDL2_net linking
- [ ] Clean up CMake configs for x64 vs arm64
- [ ] Make the code slightly launchable
- [ ] Launch Egoboo on macOS 🎉
---

## 💡 Why Share a Broken Repo?
Because perfection is boring.  
Because showing the *fight* is just as important as showing the result.  
Because **this is the resurrection of a legend**, and legends aren’t born clean.  

---

## 🧑‍💻 About Me
I’m **Luca Huci**, a Romanian born in Greece, with a love for tinkering, getting my hands on old code, and resurrecting forgotten tech.  
This is my audacity project – to stand with prodigies, to make something honorable, and to show the world that broken pieces can still shine.

---

## 🙏 Credits
- Original Egoboo developers
- Michael Heilmann for Idlib (2017–2018)
- SDL2 community
- Anyone crazy enough to watch me fight through this

---

## ⚠️ Disclaimer
This repo is unstable. Expect errors, chaos, and possibly broken dreams.  
But if you want to help, fork it, PR it, or just cheer me on.
>>>>>>> Stashed changes

- [master](https://github.com/egoboo/egoboo/tree/master) branch Linux (Ubuntu):
[![Build status](https://ci.appveyor.com/api/projects/status/8u6ubxw52foc2rat/branch/master?svg=true)](https://ci.appveyor.com/project/michaelheilmann-com/egoboo-linux/branch/master)
