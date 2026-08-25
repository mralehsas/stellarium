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

Task 2 is closed GREEN.

## Task 3 — Time, calendar, and angle primitives

### RED — observed and confirmed

- Workflow run: `32842240120`
- Job: `ALBAZ Qt6 scientific tests`
- Task 2 regression: `5 passed / 0 failed`
- Task 3 build result: `FAILURE`
- Confirmed compiler failure: `../core/AstroAngle.hpp: No such file or directory`

### GREEN — observed and confirmed

Production headers are present:

- `core/AstroAngle.hpp`
- `core/AstroTime.hpp`
- `core/CalendarConversion.hpp`

- Workflow run: `32842698970`
- Job: `ALBAZ Qt6 scientific tests`
- Task 2 build/test: success
- Task 3 build/test: success
- Result: `SUCCESS`

Task 3 is closed GREEN.

## Task 1 integration closure — Qt static plugin registration

### RED — requested, verification pending

The smoke test now checks runtime registration through `QPluginLoader::staticInstances()` and the public `StelPluginInterface` contract. It no longer constructs `ALBAZCrescentStelPluginInterface` manually.

Expected RED behavior before production registration wiring exists:

- `testALBAZPluginSmoke` builds successfully.
- Runtime lookup does not find plugin id `ALBAZCrescent` in Qt static plugin instances.
- The test fails with the message that ALBAZ must be registered through Qt static plugin import inside Stellarium.

No static-import production wiring may be added until this RED state is observed and confirmed by the Stellarium integration gate.
