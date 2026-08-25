# ALBAZ Crescent TDD Status

## Task 2 — Scientific Types

### RED — observed and confirmed

The isolated Qt6 PR workflow recorded the expected failing state before the Task 2 production headers existed.

- Workflow run: `32838031264`
- Job: `ALBAZ Qt6 scientific tests`
- Result: `FAILURE`
- Confirmed compiler failure: `../core/AstroVector.hpp: No such file or directory`
- Interpretation: the test failed for the intended TDD reason — the Task 2 scientific production types had not yet been implemented.

### GREEN — observed and confirmed

Production headers are present:

- `core/AstroVector.hpp`
- `core/Provenance.hpp`
- `core/ScientificStatus.hpp`

The isolated Qt6 scientific gate passed on the production head.

- Workflow run: `32841424360`
- Job: `ALBAZ Qt6 scientific tests`
- Result: `SUCCESS`
- Build step: `Build ALBAZ scientific types test` — success
- Test step: `Run ALBAZ scientific types test` — success

Task 2 is closed GREEN.

## Task 3 — Time, calendar, and angle primitives

### RED — requested, verification pending

Tests are committed before production code for:

- robust angle normalization across 0°/360° and ±180°
- explicit astronomical time-scale tagging (`UTC`, `TAI`, `TT`, `UT1`, `TDB`)
- Julian versus proleptic-Gregorian leap rules
- Gregorian reform JD continuity
- historical regression: `19-07-622 Julian = JD 1948442.5 = 22-07-622 proleptic Gregorian`
- J2000 reference JD
- calendar round-trip by requested convention

Expected RED cause: Task 3 production headers do not yet exist:

- `core/AstroAngle.hpp`
- `core/AstroTime.hpp`
- `core/CalendarConversion.hpp`

No Task 3 production implementation may be added until the Qt6 gate records this RED state and the failure is confirmed to originate from these missing scientific primitives.
