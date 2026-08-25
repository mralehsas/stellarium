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

### RED — observed and confirmed

The smoke test checks runtime registration through `QPluginLoader::staticInstances()` and the public `StelPluginInterface` contract. It does not construct `ALBAZCrescentStelPluginInterface` manually.

- Workflow run: `32843243543`
- Job: `ALBAZ Stellarium static plugin integration`
- Configure Stellarium integration build: success
- Build `testALBAZPluginSmoke`: success
- Runtime test: `FAILURE`
- Confirmed condition: `albaz != nullptr` returned false
- Confirmed message: `ALBAZCrescent must be registered through Qt static plugin import inside Stellarium`
- Test totals: `2 passed / 1 failed`

Interpretation: build and link were valid; ALBAZ was absent from Qt's static plugin instances at runtime. This is the intended RED state.

### GREEN — implementation present, verification pending

Production registration wiring is now present:

- `ALBAZCrescentStaticImport.cpp` imports `ALBAZCrescentStelPluginInterface` with `Q_IMPORT_PLUGIN`.
- The importer is compiled into `stelMain` so the registration reference is retained by the host.
- `stelMain` links `ALBAZCrescent-static` so the imported plugin metadata and factory resolve from the static archive.

GREEN must not be declared until the Stellarium integration gate builds and the runtime smoke test finds plugin id `ALBAZCrescent` in `QPluginLoader::staticInstances()` while the scientific regression job remains GREEN.
