/*
 * ALBAZ Crescent for Stellarium
 */

#include "ALBAZCrescent.hpp"

#include <QDebug>

StelModule* ALBAZCrescentStelPluginInterface::getStelModule() const
{
	return new ALBAZCrescent();
}

StelPluginInfo ALBAZCrescentStelPluginInterface::getPluginInfo() const
{
	StelPluginInfo info;
	info.id = "ALBAZCrescent";
	info.displayedName = "ALBAZ Crescent";
	info.authors = "Omar Albaz";
	info.contact = "";
	info.description = "Scientific lunar crescent visibility and Hijri analysis.";
	return info;
}

ALBAZCrescent::ALBAZCrescent()
{
	setObjectName("ALBAZCrescent");
}

ALBAZCrescent::~ALBAZCrescent() = default;

void ALBAZCrescent::init()
{
	qInfo() << "ALBAZ Crescent plugin initialized";
}

void ALBAZCrescent::draw(StelCore*)
{
}

double ALBAZCrescent::getCallOrder(StelModuleActionName) const
{
	return 0.0;
}
