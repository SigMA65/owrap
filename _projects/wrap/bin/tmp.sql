Create or Replace procedure xV(val varchar2) as
begin

update t_start_setup s set s.value = val, typ = 1 where upper(s.name) = upper('CurrentStartRelizNumber');
if sql%rowcount = 0 then
 insert into t_start_setup(name, value, typ, comment_, dept_id_corp, dept_id_flat)
 values ('CurrentStartRelizNumber', val, 1, 'Текущий номер релиза АСР СТАРТ', null, null);
end if;
commit;

end xV;
/
--<<<END>>>
