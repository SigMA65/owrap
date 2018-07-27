defineTest(copyHeaders2OutInclude) {
#�������� ��������� �� ������� include

    out_include_dir = $$OUTINCLUDE/$$RELEASE_TARGET
    !exists($$out_include_dir){
        system(mkdir \"$$out_include_dir\")
    }

    for(header, HEADERS) {
      dir_name=$$dirname(header)
      file_name=$$basename(header)

      #����� ����������� ����� ����������� ��������, ������ ���
      #�� ���������� ���������� ����� �������� system ��������� ���������
      #������. $$escape_expand(\n\t) ������-�� �� �������.
      #����� ������ �����������, �� ����������� ������ ������ �������.
      #��������� ������������
      COPY_CMD = $$quote(cd $$dir_name)
      system(echo $$COPY_CMD > tmp.bat)
      COPY_CMD = $$quote(copy /y $$file_name \"$$out_include_dir\")
      system(echo $$COPY_CMD >> tmp.bat)
      system(tmp.bat)
      system(del tmp.bat)
    }
return(true)


}
