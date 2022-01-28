#include "systempokemonmini.h"


SystemPokemonMini::SystemPokemonMini(QSharedPointer<CIniFile> settings, QSharedPointer<CIniFile> proj) : SystemZ80(settings,proj)
{
    m_processor = S1C88;
    m_system = POKEMONMINI;

    m_startAddress = 0x4000;
    m_programStartAddress = 0x4000;
    m_supportsExomizer = true;


    m_systemColor = QColor(70,40,80);
    m_requireEmulatorWorkingDirectory = true;

}

void SystemPokemonMini::Assemble(QString &text, QString filename, QString currentDir, QSharedPointer<SymbolTable> symTab)
{
    QString output;
    int time = timer.elapsed();

    output+="<br>";

    PerformAssembling(filename,text,currentDir,symTab);

    if (!QFile::exists(filename+".bin")) {
        text  += "<br><font color=\"#FFFF00\">Error during assembly : please check source assembly for errors.</font>";
        text+=output;
        m_buildSuccess = false;
        return;
    }

    if (m_buildSuccess) {
        text +="<br>Assembled file size: <b>" + QString::number(QFileInfo(filename+".bin").size()) + "</b> bytes";
    }

    output+="<br>";

    time = timer.elapsed();


    text+=output;

}

void SystemPokemonMini::PostProcess(QString &text, QString file, QString currentDir)
{

}

void SystemPokemonMini::applyEmulatorParameters(QStringList &params, QString debugFile, QString filename, CIniFile *pini) {


}
