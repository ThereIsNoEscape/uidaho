;;; Jonathan Buch, CS 210 HW #1, Lisp Assignment

;; j - Denotes integer
;; L - Denotes list
;; LL - Denotes list of lists
;; str - Denotes string

;; foo(j) - If n is not an integer, foo(n) should return nil. 
;; If n <= 1, foo(n) should return 1. If n > 1, foo(n) should return foo(n-1) * (n/2)

(defun foo(j)
	(if (integerp j)
		(if (<= j 1) 1
			(* (foo (- j 1)) (/ j 2)
			)
		)
		nil
	)
)		

;; SignSum(L) - Counts all of the signs and returns the total

(defun signsum (L)
	(if (null L) 0
		(cond	
			((not(listp L)) nil)				; If not a list, returns nil
			((not(numberp (car L))) (+ 0 (signsum (cdr L)))); Adds zero if the atom isnt a number
			((> (car L) 0)  (+ 1 (signsum (cdr L))))	; Adds one if the number is positive
			((< (car L) 0)  (+ -1 (signsum (cdr L))))	; Subtracts one if the number is negative
			((= (car L) 0)  (+ 0 (signsum (cdr L))))	; Adds nothing if the number is 0
			(t nil))
	)
)

;; SquaredEvens(L) - Takes a list and squares all of its even numbers

(defun squaredevens(L)
	(if (null L) nil
		(cond
			((evenp (car L)) (cons (* (car L) (car L)) (squaredevens (cdr L))))
			((oddp (car L)) (cons (car L) (squaredevens (cdr L)))))
	)
)

(defun polyval(L x)
	(+
		(* (caar L)			; First Polynomial
			(expt x (cadar L)))
		(* (caadr L)			; Second Polynomial
			(expt x (cadadr L)))
	)
)

;; Hasp(LL n) - Takes a list and an atom and finds the atom in the list

(defun hasp(LL n)
	(if(null LL) nil
		(if(eq (car LL) n) T
			(cond
				((listp (car LL)) (hasp(car LL) n))
				((hasp (cdr LL) n)))
		)	
	)
)	

;; Ncons(LL) - Takes a list and figures out the amount of total concells

(defun ncons(LL)
	(if (null LL) 0
		(if (consp (car LL)) 
			(+ 1 (ncons (car LL)) (ncons (cdr LL))) ; Adds if it is a list concell
			(+ 1 (ncons (cdr LL)))			; as well as a ending concell 
		)
	)
)

;; nVowels(str) - Counts the number of vowels in a submitted string

(defun nvowels(str)
	(if (null str) 0
		(+ (count #\a str)		; Counts up all a's
		   (count #\e str)		; "	      " e's
		   (count #\i str)		; "	      " i's
		   (count #\o str)		; "           " o's
		   (count #\u str))             ; "           " u's
	)
)

;; Bit2List(str) - Converts a list of 1s and 0s to Ts and nils

(defun bit2list(str)
	(if (equal (length str) 0) nil
		(if (equal (char str 0) #\1)
			(cons T (bit2list (subseq str 1 (length str))))
			(cons nil (bit2list (subseq str 1 (length str))))
		)
	)
)
