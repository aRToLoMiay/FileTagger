#pragma once

#include <QDomDocument>
#include <QDomElement>
#include <QString>

class IXmlReadable
{
public:
	virtual QDomElement createXmlEntity(QDomDocument*) = 0;
	static QString getTagName() {
		return "";
	};
	virtual void updateData(const QDomElement*) = 0;
};
