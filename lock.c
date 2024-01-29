#include "types.h"
#include "user.h"
#include "mmu.h"
#include "lock.h"
#include "x86.h"
int lock_init(lock_t *lock)
{
    lock->flag = 0;
    return 0;
}

void lock_acquire(lock_t *lock)
{
    while(xchg(&lock->flag, 1) != 0);
}

void lock_release(lock_t *lock)
{
    xchg(&lock->flag, 0);
}