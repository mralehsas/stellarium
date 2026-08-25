# ALBAZ Crescent TDD Status

## Task 2 — Scientific Types

Current state: RED requested; PR #2 synchronized against the isolated Stellarium 26.2 CI base.

Expected failing reason before production headers exist:

- `core/AstroVector.hpp` missing
- `core/Provenance.hpp` missing
- `core/ScientificStatus.hpp` missing

The production implementation must not be added until the isolated Qt6 PR workflow records this RED state and the failure is confirmed to originate from the missing Task 2 production types.
