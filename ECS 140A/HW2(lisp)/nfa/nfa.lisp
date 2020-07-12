(defun reachable (transition start final input)
    (cond
        ((atom start)
            (if (and (null input) (equal start final)) 
                t ;; special case
                (reachable transition (funcall transition start (car input))final (cdr input))
            )       
        )
        ((listp start)
            (cond
                ((null input) (checkstate start final));;base case
            ;; loop input[]
                (t 
                 (reachable transition (getlist transition start (car input)) final (cdr input))
                )
            )
        )        
        (t nil)
    )  
)   

;;for input[i],get all possible states from start[]
(defun getlist(transition startlst inchar) 
    (if (null startlst) nil
        (append (funcall transition (car startlst) inchar) 
              (getlist transition (cdr startlst) inchar)
        )
    )

)  

(defun checkstate (startlst final)
    (cond
    ((null startlst) nil)
    ((equal (car startlst) final) t)
    (t (checkstate (cdr startlst) final))
    )

)
