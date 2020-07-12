package depth

import "hw1/expr"
import "fmt"

// Depth returns the maximum number of AST nodes between the
// root of the tree and any leaf (literal or variable) in the tree.
func Depth(e expr.Expr) uint {
	var testParse expr.Expr
	var err error
	expr.Parse("(1 + 2) + (3 + X)")
	fmt.Println("testParse: ",testParse)
	fmt.Println("Eval: ",testParse.Eval)
		fmt.Println("testParse: ",testParse)
	fmt.Println("error msgz: ",err)
	// TODO: implement this function
	return 1234
}
