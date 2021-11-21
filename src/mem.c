#include <Windows.h>

#include <COMiC/os.h>

void *COMiC_Alloc(COMiC_size size)
{
    COMiC_OS *os = COMiC_OS_GetCurrent();
    if (os == NULL)
    {
        return NULL;
    }
    return HeapAlloc(os->heap, 0, size);
}

void *COMiC_ReAlloc(void *p, COMiC_size size)
{
    COMiC_OS *os = COMiC_OS_GetCurrent();
    if (os == NULL)
    {
        return NULL;
    }
    return HeapReAlloc(os->heap, 0, p, size);
}

void COMiC_Free(void *p)
{
    COMiC_OS *os = COMiC_OS_GetCurrent();
    if (os == NULL)
    {
        return;
    }
    if (HeapFree(os->heap, 0, p) == 0)
    {
        COMiC_Error_Fatal("deallocation failed");
        return;
    }
}
