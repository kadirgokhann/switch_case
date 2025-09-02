int main(int argc) 
{
    int res;
    switch (argc) 
    {
        case 0:     [[unlikely]] res = -3; break;
        case 100:    res = 457; break;
        case 2240:  [[likely]] res = 780; break;
        default: res = 111;
    }
    return res;
}

/*
main:
        mov     eax, 780
        cmp     edi, 2240
        jne     .L9
        ret
.L9:
        jg      .L4
        test    edi, edi
        je      .L5
        cmp     edi, 100
        mov     edx, 457
        mov     eax, 111
        cmove   eax, edx
        ret
.L4:
        mov     eax, 111
        ret
.L5:
        mov     eax, -3
        ret
  */
