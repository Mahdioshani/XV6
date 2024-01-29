typedef struct __lock_t{
    uint flag;
}lock_t;

int lock_init(lock_t *lk);
void lock_acquire(lock_t *lk);
void lock_release(lock_t *lk);
