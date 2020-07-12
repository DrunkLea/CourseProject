/*


unsigned int max(unsigned int a, unsigned int b){  return a > b ? a : b;}

unsigned int knapsack(int* weights, unsigned int* values, unsigned int num_items,
              int capacity, unsigned int cur_value){
  unsigned int i;
  unsigned int best_value = cur_value;
  for(i = 0; i < num_items; i++){
    if(capacity - weights[i] >= 0 ){
      best_value = max(best_value, knapsack(weights + i + 1, values + i + 1, num_items - i - 1,
                     capacity - weights[i], cur_value + values[i]));
    }
  }
  return best_value;
}
*/
.global knapsack

.equ ws, 4

.text
max:
  #prologue:
    push %ebp
    movl %esp, %ebp
    .equ b, 2*ws #(%ebp)
    .equ a, 3*ws #(%ebp)
    movl a(%ebp),%ecx
    movl b(%ebp),%edx
    #if (a>=b){return a;} else{return b}
    if: # a-b<0 go to else
      cmpl %edx,%ecx #a-b
      jb else
      movl %ecx,%eax #return a
    else:
      movl %edx,%eax #return b
  #epilogue:
    movl %ebp, %esp
    pop %ebp
    ret

knapsack:
	#prologue:
		push %ebp
		movl %esp, %ebp
		.equ cur_value, 2*ws #(%ebp)
		.equ capacity, 3*ws #(%ebp)
    .equ num_items, 4*ws #(%ebp)
    .equ values, 5*ws #(%ebp)
    .equ weights, 6*ws #(%ebp)

    subl $2*ws,%esp
    .equ best_value, -1*ws #(%ebp)
    .equ old_ebx, -2*ws #(%ebp)

    movl %ebx,old_ebx(%ebp)


    movl cur_value(%ebp),%eax
    movl %eax,best_value(%ebp)
    movl $0,%ebx #i=%ebx=0
for_start:
  cmpl num_items(%ebp), %ebx #neg:i-num_items>=0
  jae for_end

  if_start:
    #neg: capacity - w[i]<0
    movl weights(%ebp,%ebx,ws),%eax #eax=weights[i]
    cmpl %eax,capacity(%ebp)
    jl if_end

		recursive_case:
      movl values(%ebp,%ebx,ws),%eax
      addl cur_value(%ebp),%eax
      push %eax #values[i]+cur_value
      movl capacity(%ebp),%eax
      subl weights(%ebp,%ebx,ws),%eax
      push %eax  #capacity - weights[i]
      movl num_items(%ebp),%eax
      subl %ebx,%eax
      decl %eax
      push %eax #num_items - i - 1
      leal values+ws(%ebp,%ebx,ws),%eax
      push %eax #values + i + 1
      leal weights+ws(%ebp,%ebx,ws),%eax
      push %eax #weights + i + 1
      call knapsack
      addl $5*ws, %esp #clear args */

      push %eax
      push best_value(%ebp)
      call max
      addl $2*ws, %esp #clear args */
      movl %eax,best_value(%ebp)
  if_end:

      incl %ebx
for_end:

  movl best_value(%ebp),%eax

	#epilogue:
    movl old_ebx(%ebp),%ebx
    addl $2*ws,%esp
		movl %ebp, %esp
		pop %ebp
		ret
