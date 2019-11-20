/*
 SEQUENTIAL SEARCH

 Go through the array until find the elem

 Worst case: O(n)
 Best case:  O(1)

 Methods to optimize the algorithm:
	-Method move forward: after a successful search, move the element to the indice 0
	-Method transposition: after a successful search, move the element to the previous indice
	-Sequential search by ordered table: TABLE NEEDS TO BE ORDERED

	   		K_INDEX                  K_index/elem
			------                   -------
			|321 | -------           |240|7|
			------       |           |------
			|592 |       |           |300|4|
			------       |           -------
			|876 |       --------->  |321|2|
			------                   -------







*/
