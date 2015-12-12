#!/usr/local/bin/clisp

;;; Jonathan Buch, CS 210 HW#2, September 15th, 2015
;; Card Attributes ( cost, spellp, name, attack, health, special )

(load "game.l")

;(defun gamestate()
;	(setq PlayerHealth 30)
;	(setq AIHealth 30)
;	(setq Hand '(
;		(1 nil "C slug" 1 1 2)
;		(1 nil "int" 1 1 1)
;		(1 t   "++" 0 1 1)
;		(1 t   "^=" 4 0 1)
;		(2 nil "for (;;)" 2 2 1)
;		(3 nil "switch" 3 3 2)
;		(4 nil "array a[100]" 4 4 1)
;		(4 t   "Bus Error Fireball" 6 0 1)
;	))
;	(setq AIHand '(
;		(1 nil "Atom" 1 1 1)
;		(1 t   "Car" 0 2 1)
;		(1 t   "Cdr" 2 0 1)
;		(1 nil "Parenthesis" 1 1 1)
;		(2 nil "Cons Cell" 2 1 1)
;		(3 nil "defun" 3 2 1)
;		(4 t   "Mapcar" 4 0 1)
;		(4 nil "Lisp Monster" 2 6 1)
;	))
;)

(setq *random-state* (make-random-state t))
(setq MinIndx 0)
(setq MonIndx 0)
(setq Minions '())
(setq Monsters '())
(setq RandomStart (1+ (random 2)))
(setq PlayerHealth Health)
(setq turn 1)

(defun addSpec1()
	(setf Hand (loop for x in Hand
		do (progn
			(setq x (append x '(1)))	
		   )
		collect x
	))
)

(defun addSpec2()
	(setf AIHand (loop for x in AIHand
		do (progn
			(setq x (append  x '(1)))	
		   )
		collect x
	))
)


(defun gloop()
	(addSpec1)
	(addSpec2)
	(format t "WELCOME TO LISPSTONE!!!~%~%" nil)
	(format t "Rules:~%Elements mean (in order): Cost, Type of Card(Spell - t), Name, Attack Power, Health, and Attacked Status(0 - Can Attack, 1 - Can't Attack, 2 - Has Charge, Can attack the turn it's played)~%" nil)
	(format t "When selecting cards, minions or monsters, be sure to type \"\" around the name~%" nil)
	(loop
		(progn
			(setq energy turn)
			(if (= RandomStart 1)
				(progn	
					(format t "---------------------~%" nil)
					(format t "     Player Turn     ~%" nil)					
					(format t "---------------------~%" nil)
					(prntst)
					(PlayerTurn)
					(ResetAttackedStatus Minions)
					(if (<= AIHealth 0)
						(PrintDeath 0))
					(setq energy turn)
					(setq RandomStart 2)
					(format t "---------------------~%" nil)
					(format t " Player Turn Results ~%" nil)
					(format t "---------------------~%" nil)
					(prntst)
					(setq turn (+ .5 turn))
				)
			)
			(if (= RandomStart 2)
				(progn
					(format t "---------------------~%" nil)
					(format t "       AI Turn       ~%" nil)					
					(format t "---------------------~%" nil)
					(prntst)
					(AITurn)
					(ResetAttackedStatus Monsters)
					(if (<= PlayerHealth 0)
						(PrintDeath 1))
					(setq energy turn)
					(setq RandomStart 1) 
					(format t "---------------------~%" nil)
					(format t "   AI Turn Results   ~%" nil)					
					(format t "---------------------~%" nil)
					(prntst)
					(setq turn (+ .5 turn))
				)
			)
		)
	)
)

;; PlayCard - Checks if the string of the name of the card of you want to play
;; is in your hand, then checks if you have enough energy to play it, and then
;; finally "plays" the card. This function subtracts energy, removes a card from
;; the hand, and updates the board.

(defun promptedread(s) (format t "~a: " s) (read))

(defun PlayCard()
	(progn
		(setq CardName (promptedread "Enter the name of the card you want to play"))
		(if (returnCard Hand CardName)
			(progn
;				(format t "Checking Energy...~%" nil)
				(if (chkEnergy (nth 0 (returnCard Hand CardName)) energy)
					(progn
;						(format t "You have enough energy!~%" nil)
						(if (IsMonster (returnCard Hand CardName))
							(progn
;								(format t "Playing a minion...~%" nil)
								(AddMin (returnCard Hand CardName) Minions)
;								(format t "Added to minions~%" nil)
								(setq energy (- energy (returnCost (returnCard Hand CardName))))
;								(format t "Setting your energy lower~%" nil)
								(setq Hand (RmvHnd Hand (returnCard Hand CardName)))
;								(format t "Removed used card from hand~%" nil)
							)
							(progn
								(setq TargetName (promptedread "Enter the name of the card you want to target"))
								(if (IsInMonsters (returnCard Monsters TargetName) Monsters)
									(progn
										(if (> (returnAttk (returnCard Hand CardName)) 0)
											(ChangeHealth Monsters (returnCard Monsters TargetName) (- 0 (returnAttk (returnCard Hand CardName))))
											(setq AIHealth (- AIHealth (returnAttk (returnCard Hand CardName))))
										)
										(if (> (returnHealth (returnCard Hand CardName)) 0)
											(ChangeHealth Minions (returnCard Minions TargetName) (returnHealth (returnCard Hand CardName)))
											(setq PlayerHealth (+ PlayerHealth (returnHealth (returnCard Hand CardName))))
										)
										(setq energy (- energy (returnCost (returnCard Hand CardName))))
;										(format t "Setting your energy lower~%" nil)
										(setq Hand (RmvHnd Hand (returnCard Hand CardName)))
;										(format t "Removing used card from hand~%" nil)
										(UpdtMonStatus (returnCard Monsters TargetName))
									)
									(progn
										(if (> (returnAttk (returnCard Hand CardName)) 0)
											(setq AIHealth (- AIHealth (returnAttk (returnCard Hand CardName))))
										)
										(if (> (returnHealth (returnCard Hand CardName)) 0)
											(setq PlayerHealth (+ PlayerHealth (returnHealth (returnCard Hand CardName))))
										)
									)
								)
							)
						)
					)
					(format t "Not Enough Energy~%" nil)
				)
			)
			(format t "Not a Valid Card~%" nil)
		)
	)
)

; Checks if the supplied card name is in the player's hand (Returns t if exists)

(defun returnCard(LoL CardName)
	(if (null LoL) nil
		(if (equalp (nth 2 (car LoL)) CardName)
			(progn
;				(format t "Found Card~%~a~%" (car LoL))
				(car LoL)
			)
			(returnCard (cdr LoL) CardName)
		)
	)
)

; Checks if "ELEMENT 2" is nil or t	(Returns t if exists)

(defun RandomSel(LoL)
	(if (null LoL) nil
		(if (= (nth 5 (car LoL)) 0)
			(car LoL)
			(RandomSel (cdr LoL))
		)
	)
)

(defun RandomTar(LoL)
	(if (null LoL) nil
		(progn
			(car LoL)
		)
	)
)

(defun IsMonster(CardL)
	(progn
;		(format t "Is it a Spell?~%~a~%" (nth 1 CardL))
		(if (equalp (nth 1 CardL) nil) t
			nil
		)
	)
)

; Checks Energy of the player or AI based on their current energy

(defun chkEnergy(cost x)
	(progn
		(if (<= cost x) 
			(progn
;				(format t "You have enough energy!!!~%" nil)
				(return-from chkEnergy t)
			)
			nil
		)
	)
)

(defun remEnergy(cost energy)
	(- energy cost)
)

; Returns the cost of a card

(defun returnCost(CardL)
	(progn
;		(format t "In Cost~%~a~%" (car CardL))
		(car CardL)
	)
)

; Returns the Health Value of a Card

(defun returnHealth(CardL)
	(progn
;		(format t "In Health~%~a~%" (nth 4 CardL))
		(nth 4 CardL)
	)
)

; Returns Attack Value of a Card

(defun returnAttk(CardL)
	(progn
;		(format t "In Attk~%~a~%" (nth 3 CardL))
		(nth 3 CardL)
	)
)

; Remove a card from either Hand, AIHand, Minions, or Monsters

(defun RmvHnd(LoL CardL)
	(if (null LoL) nil
		(remove CardL LoL))
)

; Adds a card to either the minions or monster lists

(defun AddMin(CardL LoL)
	(progn
;		(format t "~a~%~a~%" LoL CardL)
		(+ 1 MinIndx)
		(setq Minions (cons CardL (nthcdr MinIndx LoL)))
	)
)

(defun AddMon(CardL LoL)
	(progn
;		(format t "Adding from:~a~% Adding monster:~a~%" LoL CardL)
		(+ 1 MonIndx)
		(setq Monsters (cons CardL (nthcdr MonIndx LoL)))
	)
)

; Checks both minions and monsters lists in an attempt to find the card

(defun IsInMinions(CardL MinionsL)
	(progn
;		(format t "Checking Minions List for ~a... " CardL) 
		(if (null MinionsL) nil
			(if (equalp (nth 2 CardL) (nth 2 (car MinionsL))) t
				(IsInMinions CardL (cdr MinionsL))
			)
		)
	)
)

(defun IsInMonsters(CardL MonstersL)
	(progn
;		(format t "Checking Monsters List for ~a... " CardL)
		(if (null MonstersL) nil
			(if (equalp (nth 2 CardL) (nth 2 (car MonstersL))) t
				(IsInMonsters CardL (cdr MonstersL))
			)
		)
	)
)
; Replaces a value, "ELEMENT 5" based on attack of Monster or Damage/Healing from a spell

(defun ChangeHealth(LoL CardL Change)
	(progn
		(format t "Changing health of ~a by ~a!~%" (nth 2 CardL) change)
		(setf (nth 4 CardL) (+ (nth 4 CardL) Change))
	)
)  

(defun ResetAttackedStatus(LoL)
	(if (null LoL) nil
		(progn
			(setf (nth 5 (car LoL)) 0)
			(ResetAttackedStatus (cdr LoL))
		)
	)
)

(defun CheckAttackedStatus(CardL)
	(if (= (nth 5 CardL) 2)
		(progn
			(format t "~a has CHARGE! ~a attacked!~%" (nth 2 CardL) (nth 2 CardL))
			(setf (nth 5 CardL) 1)
			(return-from CheckAttackedStatus t)
		)
		(if (= (nth 5 CardL) 0)
			(progn
				(format t "~a attacked!~%" (nth 2 CardL))
				(setf (nth 5 CardL) 1)
				(return-from CheckAttackedStatus t)
			)
			(progn
				(format t "~a attacked already!~%" (nth 2 CardL))
			)
		)
	)
)


;; PlayAICard - Differences between this and PlayCard: Find highest playable energy
;; card in AIHand, plays the card once found, and loops until no more cards are
;; playable.

(defun PlayAICard()
	(if (null AIHand) nil
		(progn
			(setq AICard (RandomTar AIHand))
			(if (listp AICard)
				(progn
					(format t "Checking Energy...~%" nil)
					(if (chkEnergy (nth 0 (returnCard AIHand (nth 2 AICard))) energy)
						(progn
							(format t "AI has enough energy!~%" nil)
							(if (IsMonster AICard)
								(progn
									(format t "Playing a monster...~%" nil)
									(AddMon AICard Monsters)
									(format t "Added to monsters~%" nil)
									(setq energy (- energy (returnCost AICard)))
									(format t "Setting AI's energy lower~%" nil)
									(setq AIHand (RmvHnd AIHand AICard))
									(format t "Removed used card from AIHand~%" nil)
								)
								(progn
									(setq AITarget (RandomTar Minions))
									(if (> (returnAttk AICard) 0)
										(progn
											(if (IsInMinions AITarget Minions)
												(ChangeHealth Minions AITarget (- 0 (returnAttk AICard)))
												(setq PlayerHealth (- PlayerHealth (returnAttk AICard)))
											)
											(setq energy (- energy (returnCost AICard)))
											(setq AIHand (RmvHnd AIHand AICard))
											(UpdtMinStatus AITarget)
										)
										(progn
											(setq AITarget (RandomTar Monsters))
											(if (> (returnHealth AICard) 0)
												(progn
													(if (IsInMonsters AITarget Monsters)
														(ChangeHealth Monsters AITarget (returnHealth AICard))
														(setq AIHealth (+ AIHealth (returnHealth AICard)))
													)
													(setq energy (- energy (returnCost AICard)))
													(setq AIHand (RmvHnd AIHand AICard))
												)
											)
										)
									)
								)
							)
						)
						(format t "Not Enough Energy~%" nil)
					)
				)
				(format t "Not a Valid Card~%" nil)
			)
		)
	)
)



;; Attack - This function takes a string of a minion that is currently on the board
;; as well as a string of the monster or AI that the player commands it to attack. 
;; This function should, upon minion attack, to update the health of any damaged minions.

(defun Attack()
	(if (null Minions) (format t "No Minions to attack with ~%" nil)
		(progn
			(setq Attacker (promptedread "Choose minion you want to attack with "))
;			(format t "Attacking Minion: ~a~%" Attacker)
			(if (IsInMinions (returnCard Minions Attacker) Minions)
				(if (CheckAttackedStatus (returnCard Minions Attacker))
					(if (null Monsters) (setq AIHealth (- AIHealth (returnAttk (returnCard Minions Attacker)))) 
						(progn
							(setq Defender (promptedread "Choose a minion or the AI valid to attack "))
;							(format t "Defending Monster: ~a~%" Defender)
							(if (IsInMonsters (returnCard Monsters Defender) Monsters)
								(progn
;									(format t "Defender: ~a~%" Defender)
									(ChangeHealth Monsters (returnCard Monsters Defender) (- 0 (returnAttk (returnCard Minions Attacker))))
;									(format t "Changing health of ~a by -~a~%" Defender (returnAttk (returnCard Minions Attacker)))
									(ChangeHealth Minions (returnCard Minions Attacker) (- 0 (returnAttk (returnCard Monsters Defender))))
;									(format t "Changing health of ~a by -~a~%" Attacker (returnAttk (returnCard Monsters Defender)))
									(UpdtMinStatus (returnCard Minions Attacker))
									(UpdtMonStatus (returnCard Monsters Defender))
								)
								(if (equalp Defender "AI")
									(progn
										(setq AIHealth (- AIHealth (returnAttk (returnCard Minions Attacker))))
										(format t "~a attacked AI for ~a damage!~%" Attacker (returnAttk (returnCard Minions Attacker)))
									)
								)
							)
						)
					)
				)
				(format t "Didn't find minion to attack with" nil)
			)
		)
	)
)


;; AIAttack - Differences between this and Attack: AI attacks with all ready monsters
;; at any valid target chosen randomly.  

(defun AIAttack()
	(if (null Monsters) nil
		(progn
			(setq AttackerAI (RandomSel Monsters))
			(if (IsInMonsters AttackerAI Monsters)
				(if (CheckAttackedStatus AttackerAI) 
					(if (null Minions) (setq PlayerHealth (- PlayerHealth (returnAttk AttackerAI))) 
						(progn
							(setq DefenderAI (RandomTar Minions))
							(if (IsInMinions DefenderAI Minions)
								(progn
									(ChangeHealth Minions DefenderAI (- 0 (returnAttk AttackerAI)))
;									(format t "Changing health of ~a by -~a~%" DefenderAI (returnAttk AttackerAI))
									(ChangeHealth Monsters AttackerAI (- 0 (returnAttk DefenderAI)))
;									(format t "Changing health of ~a by -~a~%" AttackerAI (returnAttk DefenderAI))
									(UpdtMinStatus DefenderAI)
									(UpdtMonStatus AttackerAI)
								)
								(progn
									(setq PlayerHealth (- PlayerHealth (returnAttk AttackerAI)))
;									(format t "~a attacked Player for ~a damage!~%" AttackerAI (returnAttk AttackerAI))
								)
							)
						)
					)
				)
			)
		)
	)
)

(defun UpdtMinStatus(CardL)
	(progn
;		(format t "~a" CardL)
		(if (<= (nth 4 CardL) 0)
			(setq Minions (RmvHnd Minions CardL))
		)
	)
)

(defun UpdtMonStatus(CardL)
	(if (<= (nth 4 CardL) 0)
		(setq Monsters (RmvHnd Monsters CardL))
	)
)

; Prints state of the game
(defun prntst()
	(progn
		(format t "PlayerHealth = ~a~%" PlayerHealth)
		(format t "AIHealth = ~a~%" AIHealth)
		(format t "Turn =  ~a~%" (floor turn))
		(format t "Energy = ~a~%" (floor energy))
		(format t "Hand = ~a~%" Hand)
		(format t "AIHand = ~a~%" AIHand)
		(format t "Minions = ~a~%" Minions)
		(format t "Monsters = ~a~%" Monsters)
		(format t "~%~%" nil)
	)
)

(defun printDeath(x)
	(if (eq x 1)
		(progn
			(print "The Player died. AI is victorious" *standard-output*)
			(exit)
		)
	)
	(if (eq x 0)
		(progn
			(print "The AI died. Player is victorious" *standard-output*)
			(exit)
		)
	)
)

; Player Turn

(defun PlayerTurn()
	(setq Choice (promptedread "Enter (1)Quit (2)Attack (3)Play Card (4)End Turn"))
	(cond
		((= Choice 1)(exit))
		((= Choice 2)(Attack))
		((= Choice 3)(PlayCard))
		((= Choice 4)(return-from PlayerTurn nil))
	)
	(format t "---------------------~%" nil)
	(format t "  Player Turn Update ~%" nil)					
	(format t "---------------------~%~%" nil)
	(prntst)
	(PlayerTurn)
)

; AI Turn

(defun AITurn()
	(PlayAICard)
	(AIAttack)
	(return-from AITurn nil)
	(AITurn)
)

(gloop)
