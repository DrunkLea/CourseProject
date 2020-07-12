 (defun small (n xs)
    (cond
      ((null xs) nil)
      ((< (car xs) n) (cons (car xs) (small n (cdr xs))) );;if lesser than n, put into list
      (t(small n (cdr xs)));;ignore and continue
    )
  )
   (defun big (n xs)
    (cond
      ((null xs) nil)
      ((>= (car xs) n) (cons (car xs) (big n (cdr xs))) )
      (t(big n (cdr xs)))
    )
  )
(defun pivot (n xs)
  (list (small n xs) (big n xs))
)


(defun quicksort (xs)
  (if (null xs) nil
    (append
          (quicksort (small (car xs) (cdr xs)))
          (cons (car xs) nil) ;;pivot
          (quicksort (big (car xs) (cdr xs)))
    )
  )
    
  
)
