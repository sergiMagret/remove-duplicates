removeDuplicatesCheck: removeDuplicatesCheck.o funcions.o
	g++ removeDuplicatesCheck.o funcions.o -o removeDuplicatesCheck
	
removeDuplicatesComplexity: removeDuplicatesComplexity.o funcions.o
	g++ removeDuplicatesComplexity.o funcions.o -o removeDuplicatesComplexity

removeDuplicatesComplexity.o: removeDuplicatesComplexity.cpp
	g++ -c removeDuplicatesComplexity.cpp
	
removeDuplicatesCheck.o: removeDuplicatesCheck.cpp
	g++ -c removeDuplicatesCheck.cpp
	
funcions.o: funcions.cpp
	g++ -c funcions.cpp