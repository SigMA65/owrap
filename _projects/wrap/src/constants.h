#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <string>

const std::string fileTmpSqlName = "tmp.sql";
const std::string fileTmpPlbName = "tmp.plb";
/** ��� ������������ ������� � �� */
const std::string fileCntrlTuSqlName = "cntrlTu.sql";
/** ��� ������������ ������� ��� �� */
const std::string fileCntrlSqlName = "cntrl.sql";
/** ��� ���������� ������� � �� */
const std::string filePlbTuName = "cntrlTu.plb";
/** ��� ���������� ������� ��� �� */
const std::string filePlbName = "cntrl.plb";
/** ���������������� ���� */
const std::string fileConfName = "config.cnf";

// ������� ��� ���������� ���������
/** ������ ��� ������ ������ �������  */
const std::string ptrnCreateOrRepl("^Create\\sor\\sReplace\\s.*");
/** ������ ��� ������ ����� ������� �������� ������� */
const std::string ptrnEnd("^--<<<END>>>");
/** ������ ��� ������ ������ �� */
const std::string ptrnTuPkg(".*package\\sbody\\stu\\s*.*");
/** ������ ��� ����� ��������� �� */
const std::string ptrnTuFlag(".*\\s*tu_flag\\s:=\\s1;\\s*.*");


#endif // CONSTANTS_H
