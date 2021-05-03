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
<img width="777" alt="Screen Shot 2021-05-03 at 3 05 32 AM" src="https://user-images.githubusercontent.com/38399357/116834004-81835000-abbc-11eb-8e13-2ec96d2c3bbd.png">

## Application
A text file is provided containing the images (in the form of a vector with the last element in the vector being the image ID) to be put in the hash table. Hash collision issues are solved using both linear probing and separate chaining. With a given image check in the hash table if it is present or not,if it is present then the ID retrieved is returned to check if your retrieval was correct or not.
Data set is from the THE MNIST DATABASE of handwritten digits.
