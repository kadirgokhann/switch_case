int main(int argc) 
{
    int res;
    switch (argc) 
    {
        case 0:  res = 123; break;
        case 1:  res = 457; break;
        case 2:  res = 780; break;
        default: res = 111;
    }
    return res;
}

/*
main:
        mov     eax, 111
        cmp     edi, 2
        ja      .L1
        mov     edi, edi
        mov     eax, DWORD PTR CSWTCH.1[0+rdi*4]
.L1:
        ret
CSWTCH.1:
        .long   123
        .long   457
        .long   780
  */
