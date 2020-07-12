package nfa

import "sync"

type state uint
type TransitionFunction func(st state, act rune) []state

func Reachable(trans TransitionFunction,
	start, final state,
	input []rune) bool {
	if input == nil { //special case
		if start == final {
			return true
		}
		return false
	}

	midPoint := trans(start, input[0])

	if midPoint == nil { //dead end
		return false
	}

	if len(input) == 1 { //base case
		var wg sync.WaitGroup
		ch := make(chan int, 1)
		tmp := false

		for i := 0; i < len(midPoint); i++ { //see if midPoints[] contains final
			if tmp {
				break
			}
			wg.Add(1)
			go func() {
				if midPoint[i] == final {
					tmp = true
				}
				ch <- i
				wg.Done()
			}()
			<-ch
		}
		wg.Wait()
		return tmp
	}
	//if not, loop next input
	subInput := make([]rune, len(input)-1)
	copy(subInput, input[1:])

	tmp2 := false
	var wg2 sync.WaitGroup
	ch2 := make(chan int, 1)
	for i := 0; i < len(midPoint); i++ {
		if tmp2 {
			break
		}
		wg2.Add(1)
		go func() {
			if Reachable(trans, midPoint[i], final,
				subInput) {
				tmp2 = true
			}
			ch2 <- i
			wg2.Done()
		}()
		<-ch2
	}
	wg2.Wait()

	return tmp2
}
