#ifndef BSD_SYS_KDEBUG_H
#define BSD_SYS_KDEBUG_H

#include <sys/appleapiopts.h>
#include <sys/cdefs.h>
__BEGIN_DECLS

#ifdef __APPLE_API_UNSTABLE

#include <mach/clock_types.h>
#include <stdint.h>
#include <Availability.h>

#define KDBG_CLASS_MASK   (0xff000000)
#define KDBG_CLASS_OFFSET (24)
#define KDBG_CLASS_MAX    (0xff)
#define KDBG_SUBCLASS_MASK   (0x00ff0000)
#define KDBG_SUBCLASS_OFFSET (16)
#define KDBG_SUBCLASS_MAX    (0xff)
#define KDBG_CSC_MASK   (0xffff0000)
#define KDBG_CSC_OFFSET (KDBG_SUBCLASS_OFFSET)
#define KDBG_CSC_MAX    (0xffff)
#define KDBG_CODE_MASK   (0x0000fffc)
#define KDBG_CODE_OFFSET (2)
#define KDBG_CODE_MAX    (0x3fff)
#define KDBG_EVENTID_MASK (0xfffffffc)
#define KDBG_FUNC_MASK    (0x00000003)

#define KDBG_EVENTID(Class, SubClass, Code)                \
        ((((Class)    &   0xff) << KDBG_CLASS_OFFSET)    | \
         (((SubClass) &   0xff) << KDBG_SUBCLASS_OFFSET) | \
         (((Code)     & 0x3fff) << KDBG_CODE_OFFSET))
#define KDBG_CODE(Class, SubClass, Code) \
        KDBG_EVENTID(Class, SubClass, Code)

#define KDBG_EXTRACT_CLASS(Debugid) \
        ((uint8_t)(((Debugid) & KDBG_CLASS_MASK) >> KDBG_CLASS_OFFSET))
#define KDBG_EXTRACT_SUBCLASS(Debugid) \
        ((uint8_t)(((Debugid) & KDBG_SUBCLASS_MASK) >> KDBG_SUBCLASS_OFFSET))
#define KDBG_EXTRACT_CSC(Debugid) \
        ((uint16_t)(((Debugid) & KDBG_CSC_MASK) >> KDBG_CSC_OFFSET))
#define KDBG_EXTRACT_CODE(Debugid) \
        ((uint16_t)(((Debugid) & KDBG_CODE_MASK) >> KDBG_CODE_OFFSET))

#define DBG_FUNC_START 1
#define DBG_FUNC_END   2
#define DBG_FUNC_NONE  0

#define DBG_MACH        1
#define DBG_NETWORK     2
#define DBG_FSYSTEM     3
#define DBG_BSD         4
#define DBG_IOKIT       5
#define DBG_DRIVERS     6
#define DBG_TRACE       7
#define DBG_DLIL        8
#define DBG_WORKQUEUE   9
#define DBG_CORESTORAGE 10
#define DBG_CG          11
#define DBG_MISC        20
#define DBG_SECURITY    30
#define DBG_DYLD        31
#define DBG_QT          32
#define DBG_APPS        33
#define DBG_LAUNCHD     34
#define DBG_PERF        37
#define DBG_IMPORTANCE  38
#define DBG_BANK        40
#define DBG_XPC         41
#define DBG_ATM         42
#define DBG_ARIADNE     43
#define DBG_DAEMON      44
#define DBG_ENERGYTRACE 45
#define DBG_DISPATCH    46
#define DBG_IMG         49
#define DBG_UMALLOC     51

#define DBG_MIG         255

#define MACH_STACK_DETACH       0x5

#define MACH_MULTIQ_BOUND     1
#define MACH_MULTIQ_GROUP     2
#define MACH_MULTIQ_GLOBAL    3

#define DBG_ZERO_FILL_FAULT   1
#define DBG_PAGEIN_FAULT      2
#define DBG_COW_FAULT         3
#define DBG_CACHE_HIT_FAULT   4
#define DBG_NZF_PAGE_FAULT    5
#define DBG_GUARD_FAULT	      6
#define DBG_PAGEINV_FAULT     7
#define DBG_PAGEIND_FAULT     8
#define DBG_COMPRESSOR_FAULT  9
#define DBG_COMPRESSOR_SWAPIN_FAULT  10

#define MACH_THREAD_SET_VOUCHER 		0x2

#define PMAP__CREATE		0x0
#define PMAP__DESTROY		0x1
#define PMAP__PROTECT		0x2
#define PMAP__PAGE_PROTECT	0x3
#define PMAP__ENTER		0x4
#define PMAP__REMOVE		0x5
#define PMAP__NEST		0x6
#define PMAP__UNNEST		0x7
#define PMAP__FLUSH_TLBS	0x8
#define PMAP__UPDATE_INTERRUPT	0x9
#define PMAP__ATTRIBUTE_CLEAR	0xa
#define PMAP__REUSABLE		0xb
#define PMAP__QUERY_RESIDENT	0xc
#define PMAP__FLUSH_KERN_TLBS	0xd
#define PMAP__FLUSH_DELAYED_TLBS	0xe
#define PMAP__FLUSH_TLBS_TO	0xf
#define PMAP__FLUSH_EPT 	0x10

#define MICROSTACKSHOT_RECORD	0x0
#define MICROSTACKSHOT_GATHER	0x1

#define SYSDIAGNOSE_NOTIFY_USER	0x0

#define SFI_SET_WINDOW			0x0
#define SFI_CANCEL_WINDOW		0x1
#define SFI_SET_CLASS_OFFTIME		0x2
#define SFI_CANCEL_CLASS_OFFTIME	0x3
#define SFI_THREAD_DEFER		0x4
#define SFI_OFF_TIMER			0x5
#define SFI_ON_TIMER			0x6
#define SFI_WAIT_CANCELED		0x7
#define SFI_PID_SET_MANAGED		0x8
#define SFI_PID_CLEAR_MANAGED		0x9
#define SFI_GLOBAL_DEFER		0xa

#define ZALLOC_ZCRAM 			0x0

#define RMON_ENABLE_CPUUSAGE_MONITOR    0x001
#define RMON_CPUUSAGE_VIOLATED          0x002
#define RMON_CPUUSAGE_SUSPENDED         0x003
#define RMON_CPUUSAGE_VIOLATED_K32A     0x004
#define RMON_CPUUSAGE_VIOLATED_K32B     0x005
#define RMON_CPUUSAGE_RESUMED           0x006
#define RMON_DISABLE_CPUUSAGE_MONITOR   0x00f

#define RMON_ENABLE_CPUWAKES_MONITOR    0x011
#define RMON_CPUWAKES_VIOLATED          0x012
#define RMON_CPUWAKES_VIOLATED_K32A     0x014
#define RMON_CPUWAKES_VIOLATED_K32B     0x015
#define RMON_DISABLE_CPUWAKES_MONITOR   0x01f

#define RMON_ENABLE_IO_MONITOR          0x021
#define RMON_LOGWRITES_VIOLATED         0x022
#define RMON_PHYSWRITES_VIOLATED        0x023
#define RMON_LOGWRITES_VIOLATED_K32A    0x024
#define RMON_LOGWRITES_VIOLATED_K32B    0x025
#define RMON_DISABLE_IO_MONITOR         0x02f

#define DBG_HFS_UPDATE_ACCTIME   0x01
#define DBG_HFS_UPDATE_MODTIME	 0x02
#define DBG_HFS_UPDATE_CHGTIME	 0x04
#define DBG_HFS_UPDATE_MODIFIED	 0x08
#define DBG_HFS_UPDATE_FORCE     0x10
#define DBG_HFS_UPDATE_DATEADDED 0x20
#define DBG_HFS_UPDATE_MINOR     0x40
#define DBG_HFS_UPDATE_SKIPPED	 0x80

#define DBG_TRACE_DATA      0
#define DBG_TRACE_STRING    1
#define	DBG_TRACE_INFO	    2

#define	TRACE_DATA_NEWTHREAD		(TRACEDBG_CODE(DBG_TRACE_DATA, 1))
#define	TRACE_DATA_EXEC			(TRACEDBG_CODE(DBG_TRACE_DATA, 2))
#define	TRACE_DATA_THREAD_TERMINATE	(TRACEDBG_CODE(DBG_TRACE_DATA, 3))
#define TRACE_DATA_THREAD_TERMINATE_PID	(TRACEDBG_CODE(DBG_TRACE_DATA, 4))
#define TRACE_STRING_GLOBAL		(TRACEDBG_CODE(DBG_TRACE_STRING, 0))
#define	TRACE_STRING_NEWTHREAD		(TRACEDBG_CODE(DBG_TRACE_STRING, 1))
#define	TRACE_STRING_EXEC		(TRACEDBG_CODE(DBG_TRACE_STRING, 2))
#define TRACE_STRING_PROC_EXIT		(TRACEDBG_CODE(DBG_TRACE_STRING, 3))
#define TRACE_STRING_THREADNAME		(TRACEDBG_CODE(DBG_TRACE_STRING, 4))
#define TRACE_STRING_THREADNAME_PREV	(TRACEDBG_CODE(DBG_TRACE_STRING, 5))
#define	TRACE_PANIC			(TRACEDBG_CODE(DBG_TRACE_INFO, 0))
#define	TRACE_TIMESTAMPS		(TRACEDBG_CODE(DBG_TRACE_INFO, 1))
#define	TRACE_LOST_EVENTS		(TRACEDBG_CODE(DBG_TRACE_INFO, 2))
#define	TRACE_WRITING_EVENTS		(TRACEDBG_CODE(DBG_TRACE_INFO, 3))
#define	TRACE_INFO_STRING		(TRACEDBG_CODE(DBG_TRACE_INFO, 4))

#define DBG_CS_IO	0

#define DBG_EVENT	0x10
#define	DBG_BUFFER	0x20

#define DBG_DYLD_UUID (5)

#define DBG_DYLD_UUID_MAP_A             (0)
#define DBG_DYLD_UUID_MAP_B             (1)
#define DBG_DYLD_UUID_MAP_32_A          (2)
#define DBG_DYLD_UUID_MAP_32_B          (3)
#define DBG_DYLD_UUID_MAP_32_C          (4)
#define DBG_DYLD_UUID_UNMAP_A           (5)
#define DBG_DYLD_UUID_UNMAP_B           (6)
#define DBG_DYLD_UUID_UNMAP_32_A        (7)
#define DBG_DYLD_UUID_UNMAP_32_B        (8)
#define DBG_DYLD_UUID_UNMAP_32_C        (9)
#define DBG_DYLD_UUID_SHARED_CACHE_A    (10)
#define DBG_DYLD_UUID_SHARED_CACHE_B    (11)
#define DBG_DYLD_UUID_SHARED_CACHE_32_A (12)
#define DBG_DYLD_UUID_SHARED_CACHE_32_B (13)
#define DBG_DYLD_UUID_SHARED_CACHE_32_C (14)

#define DKIO_DONE 	0x01
#define DKIO_READ	0x02
#define DKIO_ASYNC	0x04
#define DKIO_META	0x08
#define DKIO_PAGING	0x10
#define DKIO_PASSIVE	0x40
#define DKIO_NOCACHE	0x80
#define DKIO_TIER_MASK	0xF00
#define DKIO_TIER_SHIFT	8

#define DBG_APP_LOGINWINDOW     0x03
#define DBG_APP_AUDIO           0x04
#define DBG_APP_SIGNPOST        0x0A
#define DBG_APP_APPKIT          0x0C
#define DBG_APP_DFR             0x0E
#define DBG_APP_SAMBA           0x80

#define OPEN_THROTTLE_WINDOW	0x1
#define PROCESS_THROTTLED	0x2
#define IO_THROTTLE_DISABLE	0x3

#define IMP_BOOSTED             0x1

#define IMP_UPDATE_TASK_CREATE  0x1

#define IMP_DONOR_UPDATE_LIVE_DONOR_STATE	0x0
#define IMP_DONOR_INIT_DONOR_STATE		0x1

#define ATM_SUBAID_INFO			0x10
#define ATM_GETVALUE_INFO		0x20
#define ATM_UNREGISTER_INFO		0x30

#define ATM_MIN_CALLED				0x1
#define ATM_LINK_LIST_TRIM			0x2

#define ATM_VALUE_REPLACED			0x1
#define ATM_VALUE_ADDED 			0x2

#define ATM_VALUE_UNREGISTERED			0x1
#define ATM_VALUE_DIFF_MAILBOX			0x2

#define DBG_DAEMON_COREDUET			0x1

#define DBG_UMALLOC_EXTERNAL			0x1
#define DBG_UMALLOC_INTERNAL			0x2

#define KDBG_MIGCODE(msgid) ((DBG_MIG << KDBG_CLASS_OFFSET) | \
                             (((msgid) & 0x3fffff) << KDBG_CODE_OFFSET))

#define MACHDBG_CODE(SubClass, code) KDBG_CODE(DBG_MACH, SubClass, code)
#define NETDBG_CODE(SubClass, code) KDBG_CODE(DBG_NETWORK, SubClass, code)
#define FSDBG_CODE(SubClass, code) KDBG_CODE(DBG_FSYSTEM, SubClass, code)
#define BSDDBG_CODE(SubClass, code) KDBG_CODE(DBG_BSD, SubClass, code)
#define IOKDBG_CODE(SubClass, code) KDBG_CODE(DBG_IOKIT, SubClass, code)
#define DRVDBG_CODE(SubClass, code) KDBG_CODE(DBG_DRIVERS, SubClass, code)
#define TRACEDBG_CODE(SubClass,code) KDBG_CODE(DBG_TRACE, SubClass, code)
#define MISCDBG_CODE(SubClass,code) KDBG_CODE(DBG_MISC, SubClass, code)
#define DLILDBG_CODE(SubClass,code) KDBG_CODE(DBG_DLIL, SubClass, code)
#define SECURITYDBG_CODE(SubClass,code) KDBG_CODE(DBG_SECURITY, SubClass, code)
#define DYLDDBG_CODE(SubClass,code) KDBG_CODE(DBG_DYLD, SubClass, code)
#define QTDBG_CODE(SubClass,code) KDBG_CODE(DBG_QT, SubClass, code)
#define APPSDBG_CODE(SubClass,code) KDBG_CODE(DBG_APPS, SubClass, code)
#define ARIADNEDBG_CODE(SubClass, code) KDBG_CODE(DBG_ARIADNE, SubClass, code)
#define DAEMONDBG_CODE(SubClass, code) KDBG_CODE(DBG_DAEMON, SubClass, code)
#define CPUPM_CODE(code) IOKDBG_CODE(DBG_IOCPUPM, code)

#define KMEM_ALLOC_CODE MACHDBG_CODE(DBG_MACH_LEAKS, 0)
#define KMEM_ALLOC_CODE_2 MACHDBG_CODE(DBG_MACH_LEAKS, 1)
#define KMEM_FREE_CODE MACHDBG_CODE(DBG_MACH_LEAKS, 2)
#define KMEM_FREE_CODE_2 MACHDBG_CODE(DBG_MACH_LEAKS, 3)
#define ZALLOC_CODE MACHDBG_CODE(DBG_MACH_LEAKS, 4)
#define ZALLOC_CODE_2 MACHDBG_CODE(DBG_MACH_LEAKS, 5)
#define ZFREE_CODE MACHDBG_CODE(DBG_MACH_LEAKS, 6)
#define ZFREE_CODE_2 MACHDBG_CODE(DBG_MACH_LEAKS, 7)

#define PMAP_CODE(code) MACHDBG_CODE(DBG_MACH_PMAP, code)

#define IMPORTANCE_CODE(SubClass, code) KDBG_CODE(DBG_IMPORTANCE, (SubClass), (code))
#define BANK_CODE(SubClass, code) KDBG_CODE(DBG_BANK, (SubClass), (code))
#define ATM_CODE(SubClass, code) KDBG_CODE(DBG_ATM, (SubClass), (code))

#define COREDUETDBG_CODE(code) DAEMONDBG_CODE(DBG_DAEMON_COREDUET, code)

extern unsigned int kdebug_enable;

#define KDEBUG_ENABLE_TRACE   (1U << 0)
#define KDEBUG_ENABLE_PPT     (1U << 3)
#define KDEBUG_ENABLE_SERIAL  (1U << 4)

#define KDEBUG_TRACE (KDEBUG_ENABLE_TRACE)

#define KDEBUG_PPT    (KDEBUG_ENABLE_PPT)
#define KDEBUG_COMMON (KDEBUG_ENABLE_TRACE | KDEBUG_ENABLE_PPT)

#define KDEBUG_LEVEL_NONE     0
#define KDEBUG_LEVEL_IST      1
#define KDEBUG_LEVEL_STANDARD 2
#define KDEBUG_LEVEL_FULL     3

#if NO_KDEBUG
#define KDEBUG_LEVEL KDEBUG_LEVEL_NONE
#elif IST_KDEBUG
#define KDEBUG_LEVEL KDEBUG_LEVEL_IST

#elif KDEBUG
#define KDEBUG_LEVEL KDEBUG_LEVEL_FULL
#else
#define KDEBUG_LEVEL KDEBUG_LEVEL_STANDARD
#endif

#define KDBG_IMPROBABLE

#if (KDEBUG_LEVEL >= KDEBUG_LEVEL_STANDARD)
#define KERNEL_DEBUG_CONSTANT_FILTERED(x, a, b, c, d, ...)             \
	do {                                                               \
		if (KDBG_IMPROBABLE(kdebug_enable & ~KDEBUG_ENABLE_PPT)) {     \
			kernel_debug_filtered((x), (uintptr_t)(a), (uintptr_t)(b), \
				(uintptr_t)(c), (uintptr_t)(d));                       \
		}                                                              \
	} while (0)
#else /* (KDEBUG_LEVEL >= KDEBUG_LEVEL_STANDARD) */
#define KERNEL_DEBUG_CONSTANT_FILTERED(type, x, a, b, c, d, ...) do {} while (0)
#endif /* (KDEBUG_LEVEL >= KDEBUG_LEVEL_STANDARD) */

#if (KDEBUG_LEVEL >= KDEBUG_LEVEL_STANDARD)
#define KERNEL_DEBUG_CONSTANT(x, a, b, c, d, e)                               \
	do {                                                                      \
		if (KDBG_IMPROBABLE(kdebug_enable & ~KDEBUG_ENABLE_PPT)) {            \
			kernel_debug((x), (uintptr_t)(a), (uintptr_t)(b), (uintptr_t)(c), \
				(uintptr_t)(d),(uintptr_t)(e));                               \
		}                                                                     \
	} while (0)

#define KERNEL_DEBUG_CONSTANT1(x, a, b, c, d, e)                               \
	do {                                                                       \
		if (KDBG_IMPROBABLE(kdebug_enable & ~KDEBUG_ENABLE_PPT)) {             \
			kernel_debug1((x), (uintptr_t)(a), (uintptr_t)(b), (uintptr_t)(c), \
			(uintptr_t)(d), (uintptr_t)(e));                                   \
		}                                                                      \
	} while (0)

#define KERNEL_DEBUG_EARLY(x, a, b, c, d)                                 \
	do {                                                                  \
		kernel_debug_early((uint32_t)(x), (uintptr_t)(a), (uintptr_t)(b), \
			(uintptr_t)(c), (uintptr_t)(d));                              \
	} while (0)
#else /* (KDEBUG_LEVEL >= KDEBUG_LEVEL_STANDARD) */
#define KERNEL_DEBUG_CONSTANT(x, a, b, c, d, e) do {} while (0)
#define KERNEL_DEBUG_CONSTANT1(x, a, b, c, d, e) do {} while (0)
#define KERNEL_DEBUG_EARLY(x, a, b, c, d) do {} while (0)
#endif /* (KDEBUG_LEVEL >= KDEBUG_LEVEL_STANDARD) */

#define KERNEL_DEBUG_CONSTANT_RELEASE(x, a, b, c, d, e) \
	KERNEL_DEBUG_CONSTANT_IST(~KDEBUG_ENABLE_PPT, x, a, b, c, d, 0)

#if (KDEBUG_LEVEL >= KDEBUG_LEVEL_IST)
#define KERNEL_DEBUG_CONSTANT_IST(type, x, a, b, c, d, e)                     \
	do {                                                                      \
		if (KDBG_IMPROBABLE(kdebug_enable & (type))) {                        \
			kernel_debug((x), (uintptr_t)(a), (uintptr_t)(b), (uintptr_t)(c), \
				(uintptr_t)(d), (uintptr_t)(e));                              \
		}                                                                     \
	} while (0)
#else /* (KDEBUG_LEVEL >= KDEBUG_LEVEL_IST) */
#define KERNEL_DEBUG_CONSTANT_IST(type, x, a, b, c, d, e) do {} while (0)
#endif /* (KDEBUG_LEVEL >= KDEBUG_LEVEL_IST) */

#if NO_KDEBUG
#define __kdebug_constant_only __unused
#endif

#define KERNEL_DEBUG_CONSTANT_DEBUG(x, a, b, c, d, e) \
	KERNEL_DEBUG(x, a, b, c, d, e)

#if (KDEBUG_LEVEL >= KDEBUG_LEVEL_FULL)
#define __kdebug_only

#define KERNEL_DEBUG(x, a, b, c, d, e)                                  \
	do {                                                                \
		if (KDBG_IMPROBABLE(kdebug_enable & ~KDEBUG_ENABLE_PPT)) {      \
			kernel_debug((uint32_t)(x), (uintptr_t)(a), (uintptr_t)(b), \
				(uintptr_t)(c), (uintptr_t)(d), (uintptr_t)(e));        \
		}                                                               \
	} while (0)

#define KERNEL_DEBUG1(x, a, b, c, d, e)                                  \
	do {                                                                 \
		if (KDBG_IMPROBABLE(kdebug_enable & ~KDEBUG_ENABLE_PPT)) {       \
			kernel_debug1((uint32_t)(x), (uintptr_t)(a), (uintptr_t)(b), \
				(uintptr_t)(c), (uintptr_t)(d), (uintptr_t)(e));         \
		}                                                                \
	} while (0)

#else /* (KDEBUG_LEVEL >= KDEBUG_LEVEL_FULL) */
#define __kdebug_only __unused

#define KERNEL_DEBUG(x,a,b,c,d,e) do {} while (0)
#define KERNEL_DEBUG1(x,a,b,c,d,e) do {} while (0)
#endif /* (KDEBUG_LEVEL >= KDEBUG_LEVEL_FULL) */

extern void kernel_debug(
		uint32_t  debugid,
		uintptr_t arg1,
		uintptr_t arg2,
		uintptr_t arg3,
		uintptr_t arg4,
		uintptr_t arg5);

extern void kernel_debug1(
		uint32_t  debugid,
		uintptr_t arg1,
		uintptr_t arg2,
		uintptr_t arg3,
		uintptr_t arg4,
		uintptr_t arg5);

extern void kernel_debug_filtered(
		uint32_t  debugid,
		uintptr_t arg1,
		uintptr_t arg2,
		uintptr_t arg3,
		uintptr_t arg4);

extern void kernel_debug_early(
		uint32_t  debugid,
		uintptr_t arg1,
		uintptr_t arg2,
		uintptr_t arg3,
		uintptr_t arg4);


#if (KDEBUG_LEVEL >= KDEBUG_LEVEL_IST)
#define ENTR_SHOULDTRACE kdebug_enable
#define ENTR_KDTRACE(component, opcode, lifespan, id, quality, value) 	\
do {									\
    uint32_t kdcode__;							\
    uintptr_t highval__, lowval__, mask__ = 0xffffffff;			\
    kdcode__ = KDBG_CODE(DBG_ENERGYTRACE,component,opcode)|(lifespan); 	\
    highval__ = ((value) >> 32) & mask__;				\
    lowval__ = (value) & mask__;					\
    ENTR_KDTRACEFUNC(kdcode__, id, quality, highval__, lowval__);	\
} while(0)

#define kEnTrModAssociate (1 << 28)
#define ENTR_KDASSOCIATE(par_comp, par_opcode, par_act_id,		\
                         sub_comp, sub_opcode, sub_act_id)              \
do {									\
    unsigned sub_compcode = ((unsigned)sub_comp << 16) | sub_opcode;	\
    ENTR_KDTRACEFUNC(KDBG_CODE(DBG_ENERGYTRACE,par_comp,par_opcode),	\
		     par_act_id, kEnTrModAssociate, sub_compcode,	\
		     sub_act_id);					\
} while(0)

#else /* (KDEBUG_LEVEL >= KDEBUG_LEVEL_IST) */

#define ENTR_SHOULDTRACE FALSE
#define ENTR_KDTRACE(component, opcode, lifespan, id, quality, value)     \
                    do {} while (0)
#define ENTR_KDASSOCIATE(par_comp, par_opcode, par_act_id,        \
                sub_comp, sub_opcode, sub_act_id)        \
                    do {} while (0)

#endif /* (KDEBUG_LEVEL >= KDEBUG_LEVEL_IST) */

#define KDEBUG_COMMPAGE_ENABLE_TRACE      0x1

#define kEnTrCompKernel	    2

#define kEnTrActKernSocket	1
#define kEnTrActKernSockRead	2
#define kEnTrActKernSockWrite	3

#define kEnTrActKernPoll	10
#define kEnTrActKernSelect	11
#define kEnTrActKernKQWait	12

#define kEnTrEvUnblocked	256

#define kEnTrFlagNonBlocking	1 << 0
#define kEnTrFlagNoWork		1 << 1

#endif /* __APPLE_API_UNSTABLE */
__END_DECLS


#endif /* !BSD_SYS_KDEBUG_H */


