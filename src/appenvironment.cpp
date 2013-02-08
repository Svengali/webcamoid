/* Webcamod, webcam capture plasmoid.
 * Copyright (C) 2011-2012  Gonzalo Exequiel Pedone
 *
 * Webcamod is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Webcamod is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Webcamod. If not, see <http://www.gnu.org/licenses/>.
 *
 * Email     : hipersayan DOT x AT gmail DOT com
 * Web-Site 1: http://github.com/hipersayanX/Webcamoid
 * Web-Site 2: http://kde-apps.org/content/show.php/Webcamoid?content=144796
 */

#include "appenvironment.h"

AppEnvironment::AppEnvironment(QObject *parent): QObject(parent)
{
    QCoreApplication::setApplicationName(COMMONS_APPNAME);
    QCoreApplication::setApplicationVersion(COMMONS_VERSION);
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));

    QString trPath = QString("%1/%2.qm").arg("share/ts")
                                        .arg(QLocale::system().name());

    if (!QFileInfo(trPath).exists())
        trPath = QString("%1/%2.qm").arg(COMMONS_APP_TR_INSTALL_PATH)
                                    .arg(QLocale::system().name());

    this->m_translator.load(trPath);

    QCoreApplication::installTranslator(&this->m_translator);
}

QString AppEnvironment::configFileName()
{
    return QString("%1rc").arg(QCoreApplication::applicationName().toLower());
}