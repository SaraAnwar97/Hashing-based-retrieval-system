# Hashing-based-retrieval-system
A Hashing based retrieval system for digits images.
## Hash Tables
A hash table is a data structure which implements an associative array abstract data type, a structure that can map keys to values.
A hash table uses a hash function to compute an index into an array of slots, from which the desired value can be found.
Due to the imperfection of hash functions; collisions can occur sometimes in our hash table.To overcome this collision we used separate chaining method and
linear probing method.
## About
Given an image as an array of integers, a hash code is computed for every image. The computed hash codes will be used to populate a hash table. 
For retrieval purposes an array is given that represents an image. Then you will be asked to: <br>
1. know its label if it was previously inserted.<br>
2. add it to the hash table. <br>
3. remove it from the hash table.<br>
