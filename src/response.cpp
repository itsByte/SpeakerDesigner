#include "response.h"
#include <qstringlist.h>
#include <qdebug.h>

Response::Response() : amplitude(0),
                       phase(0)
{
}

void Response::ParseFRD(QString in)
{

    QStringList list = in.split("\t");
    switch (list.size())
    {
    default:
    {
        break;
    }
    case 2:
    {
        amplitude.append(QPointF(list[0].toDouble(), list[1].toDouble()));
        phase.append(QPointF(list[0].toDouble(), 0));
        break;
    }
    case 3:
    {
        amplitude.append(QPointF(list[0].toDouble(), list[1].toDouble()));
        phase.append(QPointF(list[0].toDouble(), list[2].toDouble()));
        break;
    }
    };
};

void Response::ImportFRD(QFile &file)
{
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    while (!file.atEnd())
    {
        Response::ParseFRD(file.readLine());
    }
};

QVector<QPointF> Response::getAmplitude()
{
    return amplitude;
};

QVector<QPointF> Response::getPhase()
{
    return phase;
};