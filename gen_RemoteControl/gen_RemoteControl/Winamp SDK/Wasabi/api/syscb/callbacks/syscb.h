// ----------------------------------------------------------------------------
// Generated by InterfaceFactory [Wed May 07 00:58:36 2003]
// 
// File        : syscb.h
// Class       : SysCallback
// class layer : Dispatchable Interface
// ----------------------------------------------------------------------------

#ifndef __SYSCALLBACK_H
#define __SYSCALLBACK_H

#include <bfc/dispatch.h>
#include <bfc/platform/types.h>
//#include <bfc/common.h>
#include <bfc/std_mkncc.h>
#include <stddef.h>

// ----------------------------------------------------------------------------

class SysCallback: public Dispatchable {
  protected:
    SysCallback() {}
    ~SysCallback() {}
  public:
    
public:
// -- begin generated - edit in syscbi.h
enum {	// event types
 NONE = 0,
 RUNLEVEL	= MK4CC('r','u','n','l'),	// system runlevel
 CONSOLE	= MK3CC('c','o','n'),	// debug messages
 SKINCB	= MK4CC('s','k','i','n'),	// skin unloading/loading
 DB		= MK2CC('d','b'),		// database change messages
 WINDOW	= MK3CC('w','n','d'),	// window events
 GC		= MK2CC('g','c'),		// garbage collection event
 POPUPEXIT	= MK4CC('p','o','p','x'), // popup exit 
 CMDLINE	= MK4CC('c','m','d','l'),	// command line sent (possibly from outside)
 SYSMEM	= MK4CC('s','y','s','m'),	// api->sysMalloc/sysFree
 SERVICE	= MK3CC('s','v','c'),
 BROWSER = MK3CC('u','r','l'), // browser open requests
 META = MK4CC('m','e','t','a'), // metadata changes
};
// -- end generated

  public:
    FOURCC getEventType();
    int notify(int msg, intptr_t param1 = 0, intptr_t param2 = 0);
  
  protected:
    enum {
      SYSCALLBACK_GETEVENTTYPE = 101,
      SYSCALLBACK_NOTIFY = 200,
    };
};

// ----------------------------------------------------------------------------

inline FOURCC SysCallback::getEventType() {
  FOURCC __retval = _call(SYSCALLBACK_GETEVENTTYPE, (FOURCC)NULL);
  return __retval;
}
#pragma warning(push)
#pragma warning(disable:4244)
inline int SysCallback::notify(int msg, intptr_t param1, intptr_t param2) {
  int __retval = _call(SYSCALLBACK_NOTIFY, (int)0, msg, param1, param2);
  return __retval;
}
#pragma warning(pop)

// ----------------------------------------------------------------------------

#endif // __SYSCALLBACK_H
