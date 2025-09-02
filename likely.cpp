int main2(int argc) 
{
    int res;
    if(argc == 0) [[unlikely]]
        res = -3;  
    else if(argc == 100) [[unlikely]]
        res = 456;
    else if (argc == 2240) [[likely]]
        res = 780;
    else
        res = 111;
    return res;
}

int main3(int argc) 
{
    int res;
    if(argc == 0)
        res = -3;  
    else if(argc == 100)
        res = 456;
    else if (argc == 2240)
        res = 780;
    else
        res = 111;
    return res;
}


/*
_Z5main2i:
        test    edi, edi
        je      .L3
        cmp     edi, 100
        je      .L4
        cmp     edi, 2240
        mov     edx, 111
        mov     eax, 780
        cmovne  eax, edx
        ret
.L3:
        mov     eax, -3
        ret
.L4:
        mov     eax, 456
        ret
_Z5main3i:
        test    edi, edi
        je      .L9
        mov     eax, 456
        cmp     edi, 100
        je      .L7
        cmp     edi, 2240
        mov     edx, 780
        mov     eax, 111
        cmove   eax, edx
        ret
.L9:
        mov     eax, -3
.L7:
        ret
*/
