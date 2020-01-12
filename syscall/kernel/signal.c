//
// Only for lab 06: syscall
// sys_sigalarm() and sys_sigreturn() are implemented here

#include "types.h"
#include "riscv.h"
#include "defs.h"
#include "param.h"
#include "spinlock.h"
#include "proc.h"
#include "signal.h"

uint64 sys_sigalarm(void) {
    struct proc *p = myproc();
    int interval; uint64 handler_addr;
    if(argint(0, &interval) < 0 || argaddr(1, &handler_addr) < 0)
        return -1;
    
    p->alarm_interval = interval;
    p->alarm_handler = handler_addr;
    p->alarm_last_tick = ticks;

    return 0;
}

uint64 sys_sigreturn(void) {
    struct proc *p = myproc();
    p->alarm_state = 0;
    memmove(p->tf, &p->alarm_tf, sizeof(struct trapframe));
    return 0;
}
