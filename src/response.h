#ifndef RESPONSE_H
#define RESPONSE_H
#include <qstring.h>
#include <qfile.h>
#include <qvector.h>
#include <qpoint.h>

class Response
{
private:
    QVector<QPointF> amplitude;
    QVector<QPointF> phase;
    void ParseFRD(QString in);

public:
    Response();
    QVector<QPointF> getAmplitude();
    QVector<QPointF> getPhase();
    void ImportFRD(QFile &file);
    void ExportFRD(QFile &file);
};

#endif