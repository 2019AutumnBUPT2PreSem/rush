# source files
(multitype)arraysupport\
((multitype)arraysupport, displaysupport, utilsupport, dbstruct)dboperation\
(((multitype)arraysupport, displaysupport, utilsupport, dbstruct)dboperation)dbio\
(((multitype)arraysupport, displaysupport, utilsupport, dbstruct)dboperation)service\
((((multitype)arraysupport, displaysupport, utilsupport, dbstruct)dboperation)service)interface\

where:
```
multitype -> arraysupport -|
           displaysupport -|->dboperation |-> dbio
              utilsupport -|              L-> service -> interface
```
# functions in those source files
## multitype
## arraysupport
## displaysupport
## utilsupport
## dboperation
## dbio
## service
## interface

