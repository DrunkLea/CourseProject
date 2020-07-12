.global_start:

.data
dividend:
  .long 0
divisor:
  .long 0

# quo @eax | rem @edx | dd @ebx | i @cl

.text
_start:
  movl $0, %eax #quo = 0
  movl $0, %ebx #dd = 0

  movb $31, %cl #i = 31
  for_start:
    cmpb $0, %cl
    jl for_end #if i-0<0, break
    decb %cl #i--


    shll $1, %ebx # dd <<= 1
    shll $1, %eax # quo <<= 1

/* if ((dividend >> i)&1) { dd++;}
  use %edx as writable temp reg */
    if1_start:

      movl dividend, %edx # %edx = dividend
      shr %cl, %edx
      andl $1, %edx
      cmpl $0, %edx
      jz if1_end
      incl %ebx #d++
    if1_end:

    /*
    if (dd >= divisor){
        quo++;
        dd -= divisor;
    }else  continue;*/
    if2_start:
      cmpl divisor, %ebx #dd-divsor < 0, break
      jl if2_end
      incl %eax #quo++
      subl divisor, %ebx #dd -= divisor;
    if2_end:

    jmp for_start
  for_end:

  movl %ebx, %edx #rem = dd

done:
  nop
