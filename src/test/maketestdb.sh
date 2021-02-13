#!/bin/bash

set -x

rm -f /tmp/db_test.sqlite3
sqlite3 /tmp/db_test.sqlite3 << EOF
create table tb_test(id integer, name text);
insert into tb_test(id, name) values(1, '{"name":"aaa"}');
create table arrayData(id integer, value text);
insert into arrayData(id, value) values(1, '{"name":"aaa", "array": [ { "name2":"bbb", "data2":123 }, { "name2":"ccc", "data2":456 } ]}');
.quit
EOF
