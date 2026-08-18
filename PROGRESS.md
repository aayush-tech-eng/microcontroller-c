# Embedded Roadmap — Progress Tracker

**Start date:** ~July 31, 2026
**Target finish:** ~end of October 2026 (3 months)
**Board:** STM32F030R8 Nucleo (Cortex-M0) — ☑ In hand
  - ⚠️ Roadmap targets F407 (M4). F030 covers all fundamentals; use **RM0360** (not RM0090), different register addresses.
  - F407 Discovery (~$25) needed for advanced modules A6–A8 → order around month 2.
  - Hardware needed from "Register-level bit manipulation" onward (~2–3 weeks away).
**Last updated:** August 3, 2026 (Day 4)

---

## 📍 Current Status (read this first)

- **Phase:** C Phase 1 — Foundations
- **Current concept:** Functions, prototypes & return types (Day 4 — assigned, not yet graded)
- **Current project:** led_on/off + is_overtemp + Status_t init_sensor — in progress
- **Next up:** Arrays, strings & ring buffer
- **⏳ Pending decision:** Build content package #1 ("Why not `int`") — 4 ideas banked, 0 published

---

## ✅ Completed

### C Roadmap
| Concept | Project done | Can explain it back | Date |
|---|---|---|---|
| Fixed-width types | ☑ | ☑ (quiz 3.5/4) | Day 1 |
| Bitwise operators | ☑ | ☑ (quiz 4/4) | Day 2 |
| Control flow + state machines | ☑ | ☑ (quiz 4/4) | Day 3 |
| Functions & prototypes | ☐ in progress | ☐ | Day 4 |
| Arrays, strings, ring buffer | ☐ | ☐ | |
| Pointers | ☐ | ☐ | |
| Structs & unions | ☐ | ☐ | |
| Enums & typedef | ☐ | ☐ | |
| static / extern / volatile | ☐ | ☐ | |
| Memory model (stack/heap/sections) | ☐ | ☐ | |
| Preprocessor | ☐ | ☐ | |
| Multi-file projects | ☐ | ☐ | |
| Register-level bit manipulation | ☐ | ☐ | ← hardware starts here (F030!) |
| volatile + memory-mapped I/O | ☐ | ☐ | |
| Interrupts & ISRs | ☐ | ☐ | |
| DMA & function pointers | ☐ | ☐ | |
| Struct packing & endianness | ☐ | ☐ | |
| Critical sections & atomics | ☐ | ☐ | |
| Linker script & startup | ☐ | ☐ | |
| Debugging & HardFault | ☐ | ☐ | |
| Capstone A — UART Command Shell | ☐ | ☐ | |
| Capstone B — Sensor Logger | ☐ | ☐ | |

### STM32 Roadmap
| Phase | Done | Date |
|---|---|---|
| P1 — Know Your Board | ☐ | |
| P2 — Hardware Fundamentals | ☐ | |
| P3 — GPIO | ☐ | |
| P4 — Interrupts & NVIC | ☐ | |
| P5 — Timers | ☐ | |
| P6 — UART | ☐ | |
| P7 — SPI & I2C | ☐ | |
| P8 — ADC & DAC | ☐ | |
| P9 — Startup, Linker & Toolchain | ☐ | |
| A1–A8 — Advanced modules | ☐ | (A6–A8 need F407) |

---

## 🎬 Content Published

| Title | Platform(s) | Date | Views/Notes |
|---|---|---|---|
| — none yet | | | |

**Content ideas backlog:**
1. Why embedded engineers never use `int` (overflow demo 255→0) ← next to produce
2. The 3 lines of code that control every microchip (SET/CLEAR/TOGGLE)
3. Your washing machine runs the same design pattern as a rocket (state machines)
4. Why professional firmware never just *does* something — it reports (Status_t)

---

## ⚠️ Weak Spots / Review Queue

- Quiz Q4 Day 1: `<stdint.h>` guarantee (exact widths vs `int` minimum 16 bits) — was skipped, review once
- `-Wimplicit-fallthrough` — add to standard GCC flags
- To-do: download RM0360 from st.com and bookmark it

---

## 📓 Session Log (newest first)

**Day 4 — Aug 3**
Learned: functions, prototypes, Status_t pattern, void discipline | Built: (in progress) | Content: idea #4 banked | Next: finish project + quiz, then content package #1

**Day 3**
Learned: super loop, enum+switch state machines, default-case safety | Built: 3-state IDLE→RUNNING→ERROR machine | Quiz: 4/4 | Content: idea #3 banked

**Day 2**
Learned: bitwise ops, SET/CLEAR/TOGGLE, clear-then-set idiom, multi-bit fields | Built: simulated 16-pin ODR register with print_binary | Quiz: 4/4 | Content: idea #2 banked

**Day 1**
Learned: fixed-width types, overflow/wraparound, why not `int` | Built: sizeof demo + uint8_t overflow demo | Quiz: 3.5/4 | Content: idea #1 banked | Board: confirmed STM32F030R8 in hand
