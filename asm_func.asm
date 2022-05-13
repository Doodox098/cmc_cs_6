section .text

global func1
global func2
global func3
global der_func1
global der_func2
global der_func3

func1:
    finit
    fld1
    fld1
    fld1
    faddp
    faddp
    fld qword[esp + 4]
    fld1
    fsubp
    fld st0
    fmulp
    fld1
    faddp
    fdivp
    ret

func2:
    finit
    fldz
    fld1
    fsubp
    fld1
    fscale
    fld qword[esp + 4]
    faddp
    fsqrt
    ret
    
func3:
    finit
    fldl2e
    fld qword[esp + 4]
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
    
der_func1:
    finit
    fld qword[esp + 4]
    fld1
    fsubp
    fld st0
    fld st0
    fmulp
    fld1
    faddp
    fld st0
    fmulp
    fdivp
    fld1
    fld1
    fld1
    fld1
    fld1
    fld1
    faddp
    faddp
    faddp
    faddp
    faddp
    fmulp
    fchs
    ret

der_func2:
    finit
    fldz
    fld1
    fsubp
    fld1
    fscale
    fld qword[esp + 4]
    faddp
    fsqrt
    fld1
    fld1
    faddp
    fmulp
    fld1
    fld st1
    fdivp
    ret
    
der_func3:
    finit
    fldl2e
    fld qword[esp + 4]
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
    fchs
    ret
