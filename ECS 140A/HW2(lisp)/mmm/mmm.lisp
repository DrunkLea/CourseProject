(defun get_min (m l)
  (cond ((null l) m);;base case: empty lst
        ((< (car l) m) (get_min (car l) (cdr l)));;m=(car l)
        (t (get_min m  (cdr l))))
)

(defun get_max (m l)
  (cond ((null l) m);;base case: empty lst
        ((> (car l) m) (get_max (car l) (cdr l)));;m=(car l)
        (t (get_max m  (cdr l))))
)
(defun sum (l)
        (if (null l) 0 
        (+ (car l) (sum (cdr l)))))
(defun length (l)
        (if (null l) 0 
        (+ 1 (length (cdr l)))))
(defun mean(l)
    (/ (sum l) (length l))
)
    

(defun min-mean-max (xs)
    (list 
        (get_min (car xs) xs)
        (mean xs)
        (get_max(car xs) xs)
    )  
   
)