#include "testPluginSmoke.hpp"
#include "../ALBAZCrescent.hpp"

#include <QtTest>

QTEST_GUILESS_MAIN(TestPluginSmoke)

void TestPluginSmoke::pluginMetadataIsStable()
{
	ALBAZCrescentStelPluginInterface iface;
	const StelPluginInfo info = iface.getPluginInfo();

	QCOMPARE(info.id, QStringLiteral("ALBAZCrescent"));
	QCOMPARE(info.displayedName, QStringLiteral("ALBAZ Crescent"));
	QVERIFY(!info.description.isEmpty());
}
