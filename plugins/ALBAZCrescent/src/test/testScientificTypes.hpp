#ifndef TESTALBAZSCIENTIFICTYPES_HPP
#define TESTALBAZSCIENTIFICTYPES_HPP

#include <QObject>

class TestScientificTypes : public QObject
{
	Q_OBJECT

private slots:
	void fatalStatusIsNotUsable();
	void provenanceFingerprintChangesWithKernel();
	void vectorArithmeticIsDoublePrecision();
};

#endif // TESTALBAZSCIENTIFICTYPES_HPP
