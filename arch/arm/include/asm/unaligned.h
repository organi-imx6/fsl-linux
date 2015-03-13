#ifndef _ASM_ARM_UNALIGNED_H
#define _ASM_ARM_UNALIGNED_H

/*
 * The armv6 can do unaligned accesses itself.
 */
#ifdef CONFIG_HAVE_EFFICIENT_UNALIGNED_ACCESS
#include <linux/unaligned/access_ok.h>
#include <linux/unaligned/generic.h>

#define get_unaligned __get_unaligned_le
#define put_unaligned __put_unaligned_le
#else
#include <asm-generic/unaligned.h>
#endif

#endif /* _ASM_ARM_UNALIGNED_H */
