package nfa



// A state in the NFA is labeled by a single integer.
type state uint

// TransitionFunction tells us, given a current state and some symbol, which
// other states the NFA can move to.
//
// Deterministic automata have only one possible destination state,
// but we're working with non-deterministic automata.
type TransitionFunction func(st state, act rune) []state

func Reachable(
	// `transitions` tells us what our NFA looks like
	transitions TransitionFunction,
	// `start` and `final` tell us where to start, and where we want to end up
	start, final state,
	// `input` is a (possible empty) list of symbols to apply.
	input []rune,
) bool {
	if input == nil{
		if start == final{
			return true
		}
		return false
	}
	midPoint := transitions(start,input[0])

	if midPoint == nil { //dead end
		return false
	}


	if len(input) == 1{
		for i := 0; i < len(midPoint); i++ {//see if midPoints[] contains final
			if midPoint[i] == final{
				return true
			}
		}
			return false
	}
	//if not, loop next input
	subInput := make([]rune, len(input)-1)
	copy(subInput,input[1:])

	for i := 0; i < len(midPoint); i++ {
		if Reachable(transitions,midPoint[i],final,
			subInput){
			return true
		}
	}

	return false
	// TODO Write the Reachable function,
	// return true if the nfa accepts the input and can reach the final state with that input,
	// return false otherwise
	panic("TODO: implement this!")
}
