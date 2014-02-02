/*
** $Id: ldumpinfo.c,v 1.83.1.1 2013/04/12 18:48:47 NaughtyCode $
** Standard dumpinfoematical library
** See Copyright Notice in lua.h
*/

#include <stdlib.h>
#include <math.h>

#define ldumpinfolib_c
#define LUA_LIB

#include "lua.h"
#include "lauxlib.h"
#include "lualib.h"
#include "lstate.h"

static int ThreadStateCallInfo(lua_State *L) {
  CallInfo* cur;
  int size = sizeof(CallInfo);
  int length=0;
  int mem=0;
  cur=L->ci;
  while(cur!=0){
    length+=1;
    mem+=size;
    cur=cur->next;
  }
  cur=L->ci;
  while(cur!=0){
    length+=1;
    mem+=size;
    cur=cur->previous;
  }
  cur=&L->base_ci;
  while(cur!=0){
    length+=1;
    mem+=size;
    cur=cur->next;
  }
  cur=&L->base_ci;
  while(cur!=0){
    length+=1;
    mem+=size;
    cur=cur->previous;
  }
  lua_pushnumber(L,length);
  lua_pushnumber(L,mem);
  return 2;
}

static int ThreadStateOpneUpValuesInfo(lua_State *L) {
  UpVal* cur;
  int size = sizeof(UpVal);
  int length=0;
  int mem=0;
  cur=&L->openupval->uv;
  while(cur!=0){
    length+=1;
    mem+=size;
    cur = cur->u.l.next;
  }
  cur=&L->openupval->uv;
  while (cur != 0){
    length += 1;
    mem += size;
    cur = cur->u.l.prev;
  }
  lua_pushnumber(L,length);
  lua_pushnumber(L,mem);
  return 2;
}

static int ThreadStateGCObjectInfo(lua_State *L) {
  GCObject* cur;
  int size = sizeof(GCObject);
  int length=0;
  int mem=0;
  cur=L->gclist;
  while(cur!=0){
    length+=1;
    mem+=size;
	cur = cur->gch.next;
  }
  lua_pushnumber(L,length);
  lua_pushnumber(L,mem);
  return 2;
}

static int GlobalStateStringTableInfo(lua_State *L) {
  global_State* g=G(L);
  int mem=0;
  int idx;
  idx=g->strt.nuse-1;
  GCObject* strobj;
  while(idx>-1){
    strobj = g->strt.hash[idx];
    if(strobj!=0){
      mem += strobj->ts.tsv.len;
    }
    --idx;
  }
  lua_pushnumber(L,mem);
  return 1;
}

static const luaL_Reg dumpinfolib[] = {
  {"ThreadStateCallInfo",         ThreadStateCallInfo},
  {"ThreadStateOpneUpValuesInfo", ThreadStateOpneUpValuesInfo},
  {"ThreadStateGCObjectInfo",     ThreadStateGCObjectInfo},
  {"GlobalStateStringTableInfo",  GlobalStateStringTableInfo},
  {NULL, NULL}
};

/*
** Open dumpinfo library
*/
LUAMOD_API int luaopen_dumpinfo (lua_State *L) {
  luaL_newlib(L, dumpinfolib);
  return 1;
}
