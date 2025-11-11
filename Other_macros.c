// Implement container_of, size_of, and offset_of

#include <stdio.h>
#include <stddef.h> /* offsetof */

/* ---- Minimal, portable macros ---- */
#define offset_of(TYPE, MEMBER) offsetof(TYPE, MEMBER)
/* Single evaluation of PTR; uses plain pointer arithmetic, no GNU extensions */
#define container_of(PTR, TYPE, MEMBER) ((TYPE*)(((char*)(PTR)) - offset_of(TYPE, MEMBER)))
#define size_of(X) ((size_t)sizeof(X))

/* ---- Tiny demo ---- */
typedef struct {
    int  id;
    char name[16];
} Widget;

typedef struct {
    unsigned magic;
    Widget   inner;   /* we'll recover the owner via &inner */
    double   payload;
} Envelope;

int main(void){
    _Static_assert(size_of(int) >= 2, "Unexpected int size");

    printf("offset_of(Envelope, inner) = %zu bytes\n",
           (size_t)offset_of(Envelope, inner));
    printf("size_of(Widget) = %zu bytes\n", size_of(Widget));

    Envelope env = {.magic=0xABCD1234, .inner={.id=7, .name="thing"}, .payload=3.14};
    Widget *p = &env.inner;

    Envelope *owner = container_of(p, Envelope, inner);
    printf("container_of(&inner) -> %p ; env at %p ; magic=0x%X\n",
           (void*)owner, (void*)&env, owner->magic);

    return 0;
}
