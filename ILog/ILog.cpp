#include <QFile>
#include <QTextStream>

#include "ILog.h"

QFile m_file;

int ILog::init(const char *fileName)
{
    if (!m_file.isOpen())
    {
        m_file.setFileName(QString(fileName));
        m_file.open(QIODevice::WriteOnly);
        if (!m_file.isOpen())
            return ERR_OPEN_ILogImpl;
    }
    return ERR_OK;
}

int ILog::report(const char *msg)
{
    if (m_file.isOpen())
    {
        QTextStream ts(&m_file);
        ts << QString(msg) << "\n";
    }
    QTextStream out(stdout);
    out << QString(msg) << "\n";
}

void ILog::destroy()
{
    m_file.close();
}
