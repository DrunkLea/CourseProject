
(defun matrix-add (m1 m2)
    (if (null m1) nil
        (cons (row-add (car m1) (car m2));;first row add result()
        (matrix-add (cdr m1) (cdr m2))
        )
    )
)
(defun row-add(ar br)
    (if (null ar) nil
        (cons (+ (car ar) (car br)) ;;C(i,j)=A(i,j)+B(i,j)
            (row-add (cdr ar) (cdr br))
        )
    )
)

(defun matrix-transpose (m)
   (if (null (cdr m)) (row-col (car m))
        (mapcar #'append (row-col (car m))
                (matrix-transpose (cdr m))
        ) 
    )
)
(defun row-col(row)
    (if (null row) nil
     (cons (cons (car row) nil)
            (row-col(cdr row))       
        )    
    )    
)

(defun matrix-multiply (a b)
    (if (null a) nil
        (cons (get-new-row (car a) (matrix-transpose b))
            (matrix-multiply (cdr a) b)
        )
    )
)
(defun get-new-row (ar bm) ;;fixed row, changing col of b, b transposed
    (if (null bm) nil
        (cons (row-dot-col ar (car bm))
            (get-new-row ar (cdr bm))
        )
    )
)
(defun row-dot-col (r c);; args both in simple list
    (if (null r) '0
        (+ (* (car r) (car c))
            (row-dot-col (cdr r) (cdr c))
        )
    )
)