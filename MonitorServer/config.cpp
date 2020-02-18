#include "config.h"
#include <QtCore/QtCore>
#include <QDebug>

// 构造函数,需要文件名
Config::Config(QString qstrfilename)
{
    if (qstrfilename.isEmpty())
    {
        m_qstrFileName = QCoreApplication::applicationDirPath() + "/Config.ini";
    }
    else
    {
        m_qstrFileName = qstrfilename;
    }

    m_psetting = new QSettings(m_qstrFileName, QSettings::IniFormat);
    qDebug() << m_qstrFileName;
}

// 析构函数
Config::~Config()
{
    delete m_psetting;
    m_psetting = 0;
}

// 设置参数,三个参数:节点,key,value
void Config::Set(QString qstrnodename,QString qstrkeyname,QVariant qvarvalue)
{
    m_psetting->setValue(QString("/%1/%2").arg(qstrnodename).arg(qstrkeyname), qvarvalue);
}

// 读取参数,两个参数:节点,key
QVariant Config::Get(QString qstrnodename,QString qstrkeyname)
{
    QVariant qvar = m_psetting->value(QString("/%1/%2").arg(qstrnodename).arg(qstrkeyname));
    return qvar;
}
