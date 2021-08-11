#ifndef _JKDEBUG_H_
#define _JKDEBUG_H_

typedef struct {
    uint64_t        timestamp;
    uintptr_t       arg1;
    uintptr_t       arg2;
    uintptr_t       arg3;
    uintptr_t       arg4;
    uintptr_t       arg5;
    uint32_t        debugid;
#if defined(__LP64__)
    uint32_t        cpuid;
    uintptr_t       unused;
#endif
} kd_buf;
#endif

#define KDBG_TIMESTAMP_MASK             0x00ffffffffffffffULL
#define KDBG_CPU_MASK                   0xff00000000000000ULL
#define KDBG_CPU_SHIFT                  56

#pragma pack(1)
typedef struct 
{
    uint8_t	qualifier:2;
    uint16_t	code:14;
    uint8_t	subclass;
    uint8_t	class;

} kdebugCode;
#pragma pack()

typedef struct {
    unsigned int    type;
    unsigned int    value1;
    unsigned int    value2;
    unsigned int    value3;
    unsigned int    value4;

} kd_regtype;


#define KDBG_RANGETYPE          0x40000
#define KDBG_TYPENONE           0x80000

typedef struct
{
        int             nkdbufs;
        int             nolog;
        int             flags;
        int             nkdthreads;
        int             bufid;
} kbufinfo_t;

typedef struct {
        uintptr_t       thread;
        int             valid;
        char            command[20];

} kd_threadmap;

typedef struct {
        uint32_t        version_no;
        uint32_t        cpu_count;
} kd_cpumap_header;


#define KDBG_NOWRAP     0x002
#define KDBG_FREERUN    0x004
#define KDBG_WRAPPED    0x008
#define KDBG_USERFLAGS  (KDBG_FREERUN|KDBG_NOWRAP|KDBG_INIT)
#define KDBG_PIDCHECK   0x010
#define KDBG_MAPINIT    0x020
#define KDBG_PIDEXCLUDE 0x040
#define KDBG_LOCKINIT   0x080
#define KDBG_LP64       0x100




