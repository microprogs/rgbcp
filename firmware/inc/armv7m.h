#ifndef ARMV7M_H
#define ARMV7M_H

static __inline void no_operation(void) __attribute__((always_inline));
static __inline void wait_for_interrupt(void) __attribute__((always_inline));
static __inline void wait_for_event(void) __attribute__((always_inline));
static __inline void send_event(void) __attribute__((always_inline));
static __inline void enable_irq(void) __attribute__((always_inline));
static __inline void disable_irq(void) __attribute__((always_inline));
static __inline void enable_fault_irq(void) __attribute__((always_inline));
static __inline void disable_fault_irq(void) __attribute__((always_inline));

static __inline void no_operation(void)
{
	__asm __volatile ("nop");
} 

static __inline void wait_for_interrupt(void)
{
	__asm __volatile ("wfi");
}

static __inline void wait_for_event(void)
{
	__asm __volatile ("wfe");
}

static __inline void send_event(void)
{
	__asm __volatile ("sev");
}

static __inline void enable_irq(void)
{
	__asm __volatile ("cpsie i");
}

static __inline void disable_irq(void)
{
	__asm __volatile ("cpsid i");
}

static __inline void enable_fault_irq(void)
{
	__asm __volatile ("cpsie f");
}

static __inline void disable_fault_irq(void)
{
	__asm __volatile ("cpsid f");
}

#endif

