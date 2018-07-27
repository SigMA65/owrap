#include <string>
#include <windows.h>

#include <boost/property_tree/ini_parser.hpp>


#include "property.h"
#include "constants.h"
#include "message\message.h"

Property::Property() {
    message("Разбор конфигурационного файла");

    boost::property_tree::ptree pt;
    boost::property_tree::ini_parser::read_ini(fileConfName, pt);
    _wrapPath = pt.get<std::string>("Wrap.wrapPath");
    _wrapCmd = _wrapPath+" iname="+fileTmpSqlName+" oname="+fileTmpPlbName;

    int l = MultiByteToWideChar(CP_ACP, MB_ERR_INVALID_CHARS, _wrapCmd.c_str(), -1, NULL, 0);
    _wrapCmd_w = new wchar_t[l];
    MultiByteToWideChar(CP_ACP, MB_ERR_INVALID_CHARS, _wrapCmd.c_str(), -1, _wrapCmd_w, l);
}

std::string Property::getWrapPath() {
    return _wrapPath;
}

std::string Property::getwrapCmd()
{
    return _wrapCmd;
}

wchar_t* Property::getwrapCmd_w()
{
    return _wrapCmd_w;
}



void Property::setSrcFileName(const std::string fileName) {
    _srcFileName = fileName;
}

std::string Property::getSrcFileName()
{
    return _srcFileName;
}

