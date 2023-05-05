# drogondbtest
Demo project to reproduce issue described in https://github.com/drogonframework/drogon/discussions/1586
**OS**
Windows 11

**DB**
psql (15.2)

                                      List of relations
 Schema |   Name    | Type  |  Owner   | Persistence | Access method |  Size   | Description
--------+-----------+-------+----------+-------------+---------------+---------+-------------
 public | knowledge | table | postgres | permanent   | heap          | 7608 kB |
(1 row)

                      Table "public.knowledge"
  Column   |          Type          | Collation | Nullable | Default
-----------+------------------------+-----------+----------+---------
 userid    | character varying(255) |           | not null |
 knowledge | text                   |           |          |

**Compiler**
Visual Studio 2019
