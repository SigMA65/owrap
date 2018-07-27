#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <string>

const std::string fileTmpSqlName = "tmp.sql";
const std::string fileTmpPlbName = "tmp.plb";
/** Имя контрольного скрипта с ТУ */
const std::string fileCntrlTuSqlName = "cntrlTu.sql";
/** Имя контрольного скрипта без ТУ */
const std::string fileCntrlSqlName = "cntrl.sql";
/** Имя репленного скрипта с ТУ */
const std::string filePlbTuName = "cntrlTu.plb";
/** Имя репленного скрипта без ТУ */
const std::string filePlbName = "cntrl.plb";
/** Конфигурационный файл */
const std::string fileConfName = "config.cnf";

// Шаблоны для регулярных выражений
/** Шаблон для поиска начала команды  */
const std::string ptrnCreateOrRepl("^Create\\sor\\sReplace\\s.*");
/** Шаблон для поиска конца команды создания объекта */
const std::string ptrnEnd("^--<<<END>>>");
/** Шаблон для поиска пакета ТУ */
const std::string ptrnTuPkg(".*package\\sbody\\stu\\s*.*");
/** Шаблон для флага включения ТУ */
const std::string ptrnTuFlag(".*\\s*tu_flag\\s:=\\s1;\\s*.*");


#endif // CONSTANTS_H
