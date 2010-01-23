; prints recursive list structure

;(let (seen-list)
(setf seenlist nil)
  (defun seenp (l) (member l seenlist :test 'eq))
  (defun make-seen (l) (setf seenlist (cons l seenlist)))
  (defun printrec (l) (printrec-any l) (setf seenlist nil))
  (defun printrec-any (l)
    (cond ((atom l) (prin1 l) (princ " "))
          ((seenp l) (princ "<...> "))
          (t
           (make-seen l)
           (princ "(")
           (printrec-list l)
           (princ ") ")))
     nil)
  (defun printrec-list (l)
    (printrec-any (car l))
    (cond ((cdr l)
           (cond ((seenp (cdr l))
                  (princ "<...> "))
                 ((atom (cdr l))
                  (princ ". ")
                  (prin1 (cdr l))
                  (princ " "))
                 (t
                  (make-seen (cdr l))
                  (printrec-list (cdr l))))))
    nil)
; )

; arch-tag: 3ebdbd65-06e3-4642-9b9e-8f796f177f0f

