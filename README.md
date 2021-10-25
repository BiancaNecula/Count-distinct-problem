Data Structures Course \
HOMEWORK 2 - Count Distinct Problem

March, 2020

Bianca Necula \
Faculty of Automatic Control and Computer Science \
315CA 

# Info
```bash
git clone https://github.com/BiancaNecula/Count-distinct-problem.git
```
Run ./check.sh for testing with the checker. 

# About the project:
The problem of estimating cardinality (counting distinct elements) is, in essence, finding the number of unique elements in a collection of repeatable elements.  
More info: https://ocw.cs.pub.ro/courses/sd-ca/teme/tema2-2020  

# About the code:

* Task 1: Frequency vector
  - a vector of length 2000000 is declared and initialized with 0.
  - for each occurrence of a number, the value on the index equal to the respective number is incremented by 1.

* Task 2: Hashtable with open addressing
  - 2 structures are declared: one of type key-value type, the other of hashtable type.
  - the value will be represented by the frequency of occurrences of each string.
  - read strings from the file and apply the hash function to each one and then enter it in the hashtable.
  - the cases are treated:
    - if the element is new, enter the hashtable element at the index assigned by the hash function.
    - if there is another element in that place, then it is inserted in the next bucket, until a free one is found.
    - if the buckets at that end are occupied, it is resumed from index 0.
    - if the element already exists in the table, the value from the respective index is incremented.
  - after entering all the elements, the strings and the occurrence frequency are displayed and the memory is released.

* Task 3: HyperLogLog
  - the number of buckets m = 2 ^ 11 is established and we declare a vector of dimension m.
  - we read each number from the given file as a parameter until the end of the file.
  - the hash function is applied to each number and the first 11 bits (j) and the rest of the bits (x) are extracted in different variables.
  - count the first bits 0 of x and enter nr in the vector M checking to always display the highest possible value for the respective bucket on position j.
  - calculate the harmonic mean between the powers of 2 with the exponent each value stored in the vector M (Z).
  - the final result is displayed according to the formula: E = the attenuation factor * m * m * Z * 2.
  - the attenuation factor calculated and used for m = 2 ^ 11 was: 0.721.

