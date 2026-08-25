#ifndef TESTALBAZPLUGINSMOKE_HPP
#define TESTALBAZPLUGINSMOKE_HPP

#include <QObject>

class TestPluginSmoke : public QObject
{
	Q_OBJECT

private slots:
	void pluginMetadataIsStable();
};

#endif // TESTALBAZPLUGINSMOKE_HPP
