#!/bin/bash

set -x

rm -f /tmp/db_test.sqlite3
sqlite3 /tmp/db_test.sqlite3 << EOF
create table tb_test(id integer,name text);
insert into tb_test(id,name) values(1,'{"name":"aaa"}');
.quit
EOF
