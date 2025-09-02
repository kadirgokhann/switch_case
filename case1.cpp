int main(int argc) 
{
    int res;
    switch (argc) 
    {
        case 0:  res = 123; break;
        case 1:  res = 456; break;
        case 2:  res = 789; break;
        default: res = 111;
    }
    return res;
}


/*
main:
        imul    edx, edi, 333
        mov     eax, 111
        add     edx, 123
        cmp     edi, 2
        cmovbe  eax, edx
        ret
*/
