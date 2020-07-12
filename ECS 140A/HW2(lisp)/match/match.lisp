
(defun match (pattern assertion)
  (cond
   ;;base case
   ((and 
      (null pattern)
      (null assertion)) t) 

   ;;either of the args reaches the end
   ((null pattern)nil)
   ((null assertion)nil)

   ;;exam token

      ;;token match
      ((equal (car pattern) (car assertion))
         (match (cdr pattern) (cdr assertion))
      )

      ;;?
      ((equal (car pattern) '?)
         (match (cdr pattern) (cdr assertion))
      )
      
      ;;!
      ((equal (car pattern) '!)        
         (if (null (cadr pattern)) t 
           (match (cdr pattern) (exclamation (cadr pattern) (cdr assertion)) )           
         )
      )

   ;;default case
   (t nil)
  )
)
;; return assertion after token (included)
(defun exclamation(token lst)
   (cond
    ((null lst) nil)
    ((equal '? token)
      lst
    )
    ((equal (car lst) token);;find token in lst
      lst                   ;;return lst
    )
   
    (t 
      (exclamation token (cdr lst)))
    )
)

