/*
 * ALBAZ Crescent for Stellarium
 * Scientific lunar crescent visibility and Hijri analysis.
 */

#ifndef ALBAZCRESCENT_HPP
#define ALBAZCRESCENT_HPP

#include "StelModule.hpp"

class ALBAZCrescent : public StelModule
{
public:
	ALBAZCrescent();
	~ALBAZCrescent() override;

	void init() override;
	void draw(StelCore* core) override;
	double getCallOrder(StelModuleActionName actionName) const override;
};

#include <QObject>
#include "StelPluginInterface.hpp"

class ALBAZCrescentStelPluginInterface final : public QObject, public StelPluginInterface
{
	Q_OBJECT
	Q_PLUGIN_METADATA(IID StelPluginInterface_iid)
	Q_INTERFACES(StelPluginInterface)

public:
	StelModule* getStelModule() const override;
	StelPluginInfo getPluginInfo() const override;
	QObjectList getExtensionList() const override { return QObjectList(); }
};

#endif // ALBAZCRESCENT_HPP
