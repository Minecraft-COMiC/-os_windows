#include <COMiC/types.h>

#ifndef COMiC__OS_H
#define COMiC__OS_H

#include <Windows.h>

#if COMiC_LIMITED
# pragma pack(push, 1)
#endif
typedef struct _COMiC_OS_Instance _COMiC_OS_Instance;

typedef struct COMiC_OS_Thread
{
    struct COMiC_OS_Thread *_prev;
    struct COMiC_OS_Thread *_next;
    HANDLE thread_handler;
    _COMiC_OS_Instance *os_instance;
    COMiC_Error error;
} COMiC_OS_Thread;

struct _COMiC_OS_Instance
{
    struct _COMiC_OS_Instance *_prev;
    struct _COMiC_OS_Instance *_next;
    HANDLE heap;
    COMiC_usize heap_max_size;
    /* COMiC_OS_Thread root_thread; */
    /* todo make AVL three for threads list and make it static and common for all instances */
    COMiC_OS_Thread *thread_list;
};


typedef struct COMiC_Lock
{
    CRITICAL_SECTION cs_storage;
} COMiC_Lock;


typedef struct COMiC_CondVar
{
    CONDITION_VARIABLE cv_storage;
    COMiC_Lock *lock;
} COMiC_CondVar;


#if COMiC_LIMITED
# pragma pop()
#endif

#endif /* COMiC__OS_H */