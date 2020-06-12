## removeDuplicatesCheck
Program that removes the duplicates in an array, leaving the array in the same order but with only one
copy of each number, that means the result of both algorithms keeps only the first copy of each number.

The program takes as input the size of the array and a maximum value for the random numbers generated
(0..n-1).

Example: array of size 10 with 5 differents values.  
The array is filled and the result of filling the array for example is: [0, 2, 4, 2, 3, 4, 1, 4, 2, 3].  
Then the output of both alrothms is: [0, 2, 4, 3, 1].

## removeDuplicatesComplexity
Program that calls 10 times the algorithms shown in removeDuplicatesCheck doubling the size of 
the array on which to perfom the algorithms. This program shows the time that needs each algorithm
in each iteration, to show the difference in time that takes between an O(n^2) vs O(n*log n) 
performing the same operation. The initial size of the array is 500 elements.

An output could be:  

         n      O(n^2)     O(n log n)
         -      ------     ----------
       500    7.31e-05       5.78e-05
      1000   0.0002788      0.0001205
      2000   0.0010805      0.0002513
      4000   0.0047924      0.0005264
      8000   0.0193025      0.0013542
     16000   0.0834579      0.0023939
     32000    0.306647      0.0050877
     64000     1.11097      0.0107875
    128000     4.26689       0.022895
    256000     20.4378      0.0472562
    
## Make the progams
The compiler used is g++, to compile use:
* removeDuplicatesCheck:
`make removeDuplicatesCheck`

* removeDuplicatesComplexity
`make removeDuplicatesComplexity`
