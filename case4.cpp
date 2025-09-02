int main(int argc) 
{
    int res;
    switch (argc) 
    {
        case 0:     [[likely]] res = 123; break;
        case 100:    res = 456; break;
        case 2240:   res = 789; break;
        default: res = 111;
    }
    return res;
}

/*
main:
        mov     eax, 123
        test    edi, edi
        jne     .L10
.L1:
        ret
.L10:
        js      .L4
        mov     eax, 456
        cmp     edi, 100
        je      .L1
        cmp     edi, 2240
        mov     edx, 789
        mov     eax, 111
        cmove   eax, edx
        ret
.L4:
        mov     eax, 111
        ret
*/
