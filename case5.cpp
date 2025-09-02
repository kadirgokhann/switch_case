int main(int argc) 
{
    int res;
    switch (argc) 
    {
        case 0:     [[unlikely]] res = -3; break;
        case 100:    res = 457; break;
        case 2240:   res = 780; break;
        default: res = 111;
    }
    return res;
}

/*
main:
        mov     eax, 457
        cmp     edi, 100
        je      .L1
        mov     eax, 780
        cmp     edi, 2240
        je      .L1
        cmp     edi, 1
        sbb     eax, eax
        and     eax, -114
        add     eax, 111
.L1:
        ret
*/
