section .text

global _func1
global _func2
global _func3

_func1:
    finit
    fld1
    fld1
    fld1
    faddp
    faddp
    fld qword[esp + 8]
    fld1
    fsubp
    fld st0
    fmulp
    fld1
    faddp
    fdivp
    ret

_func2:
    finit
    fldz
    fld1
    fsubp
    fld1
    fscale
    fld qword[esp + 8]
    faddp
    fsqrt
    ret
    
_func3:
    finit
    fldl2e
    fld qword[esp + 8]
    fchs
    fmulp
    fld st0
    frndint
    fsub st1, st0
    fld1
    fscale
    fld st2
    f2xm1
    fld1
    faddp
    fmulp
    ret