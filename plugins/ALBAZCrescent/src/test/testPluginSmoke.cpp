#include "testPluginSmoke.hpp"

#include "StelPluginInterface.hpp"

#include <QPluginLoader>
#include <QtTest>

QTEST_GUILESS_MAIN(TestPluginSmoke)

void TestPluginSmoke::pluginIsRegisteredStatically()
{
	StelPluginInterface* albaz = nullptr;

	const QObjectList instances = QPluginLoader::staticInstances();
	for (QObject* instance : instances)
	{
		auto* iface = qobject_cast<StelPluginInterface*>(instance);
		if (!iface)
			continue;

		const StelPluginInfo info = iface->getPluginInfo();
		if (info.id == QStringLiteral("ALBAZCrescent"))
		{
			albaz = iface;
			QCOMPARE(info.displayedName, QStringLiteral("ALBAZ Crescent"));
			QVERIFY(!info.description.isEmpty());
			break;
		}
	}

	QVERIFY2(albaz != nullptr,
	         "ALBAZCrescent must be registered through Qt static plugin import inside Stellarium");
}
