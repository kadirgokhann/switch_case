int main(int argc) 
{
    int res;
    switch (argc) 
    {
        case 0:  res = 123; break;
        case 100:  res = 456; break;
        case 2240:  res = 789; break;
        default: res = 111;
    }
    return res;
}

/*
main:
        mov     eax, 456
        cmp     edi, 100
        je      .L1
        mov     eax, 789
        cmp     edi, 2240
        je      .L1
        cmp     edi, 1
        sbb     eax, eax
        and     eax, 12
        add     eax, 111
.L1:
        ret
*/
