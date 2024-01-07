# CODING A HASHTABLE
* A hash table needs:
    * an array of nodes structure
    * with each element pointing to a linked list

THAT IS:

* Given a linked list structure:
_typedef struct sllist_
_{_
    _VALUE val;_
    _struct sllist *next;_
_}_
_sllnode;_

* Declare the hash table array
_sllnode *hashTableArray[hashTableWidth] = {NULL};_
so that each element (that's why _{}_ are used) points to _NULL_

