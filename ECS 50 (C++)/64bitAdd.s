.global_start:

#upper 32 sum @EDX; lower 32 sum @EAX
.data
num1:
  .space 8
num2:
  .space 8

.text
_start:
  movl num1+4, %eax #num1 lower
  addl num2+4, %eax #num2 lower
  movl num1, %edx
  addl num2, %edx

  #if (eax<num1lower | eax< num2 lower)
  #eax-num1+4<0

  if_start:
    cmpl num1+4, %eax
    jg if_end
    incl %edx
  if_end:
done:
  nop
