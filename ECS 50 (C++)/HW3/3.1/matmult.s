.global matMult
.equ ws,4
/*
int** matMult(int **a, int num_rows_a, int num_cols_a, int** b, int num_rows_b, int num_cols_b){
	int** c = (int**) malloc(num_rows_a*sizeof(int*));
	int i,j,k;
	for(int i = 0; i < num_rows_a; i++){
		int* c[i] = (int)malloc(num_cols_b*sizeof(int));
		for(j= 0; j < num_cols_b; j++){
			for(k= 0; k < num_rows_b; k++){
				c[i][j] += a[i][k]*b[k][j];
			}
		}
	}
	return c;
}
*/

.text

matMult:
	prologue:
		push %ebp
		movl %esp,%ebp

		#int **a
		#int aRow
		#int aCol
		#int **b
		#int bRow
		#int bCol
		#ret_addr
		#old_ebx
		#int **c

		.equ a,7*wx #(%ebp)
		.equ aRow,6*wx #(%ebp)
		.equ aCol,5*wx #(%ebp)
		.equ b,4*wx #(%ebp)
		.equ bRow,3*wx #(%ebp)
		.equ bCol,2*wx #(%ebp)
		.equ c,-1*wx #(%ebp)

#return value int** C will be in %eax
	epilogue:
