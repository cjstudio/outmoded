
CREATE  TABLESPACE SPUSER 
  DATAFILE '/oracle/app/oracle/oradata/opencs/spUser' 
--DATAFILE 'D:/oracle/oradata/opencs/spUser' 
      SIZE 100M  REUSE AUTOEXTEND ON NEXT 10M MAXSIZE 500M 
  LOGGING 
  EXTENT MANAGEMENT LOCAL 
  SEGMENT SPACE MANAGEMENT AUTO
 ;
/

CREATE  TABLESPACE SPUSER_INDEX
  DATAFILE '/opt/app/oracle/oradata/opencs/spUser_index' 
--DATAFILE 'E:/oracle/index/opencs/spUser_index' 
      SIZE 50M  REUSE AUTOEXTEND ON NEXT 10M MAXSIZE 200M 
  LOGGING 
  EXTENT MANAGEMENT LOCAL 
  SEGMENT SPACE MANAGEMENT AUTO
 ;
/

CREATE TEMPORARY TABLESPACE temp_cs1
  TEMPFILE '/oracle/app/oracle/oradata/opencs/tmp_cs1' 
--TEMPFILE '/oracle/app/oracle/oradata/opencs/tmp_cs1' 
       SIZE 100M  REUSE 
 UNIFORM SIZE 128K
;
/

CREATE ROLE rlOpDBA
 IDENTIFIED BY manager
;
/

GRANT CREATE SESSION TO rlOpDBA;
GRANT CREATE TABLE TO rlOpDBA;
GRANT CREATE VIEW TO rlOpDBA;
GRANT CREATE TYPE TO rlOpDBA;
GRANT CREATE ANY INDEX TO rlOpDBA;
GRANT CREATE TRIGGER TO rlOpDBA;
GRANT CREATE SEQUENCE TO rlOpDBA;
GRANT CREATE CLUSTER TO rlOpDBA;

--GRANT CREATE SESSION TO admin;
--GRANT CREATE TABLE TO admin;
--GRANT CREATE VIEW TO admin;
--GRANT CREATE TYPE TO admin;
--GRANT CREATE ANY INDEX TO admin;
--GRANT CREATE TRIGGER TO admin;
--GRANT CREATE SEQUENCE TO admin;
--GRANT CREATE CLUSTER TO admin;

CREATE USER admin
    IDENTIFIED BY manager
    PROFILE "DEFAULT"
    DEFAULT TABLESPACE SPUSER
;
/

ALTER USER admin QUOTA  50M ON SPUSER;
/

GRANT rlOpDBA to admin;
/

CREATE USER opencsDBA
    IDENTIFIED BY manager
    PROFILE "DEFAULT"
    DEFAULT TABLESPACE SPUSER
;
/

grant DBA to opencsDBA ;
/
