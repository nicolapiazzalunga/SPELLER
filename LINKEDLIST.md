# CREATING A LINKED LIST
Linked lists are a DATA STRUCTURE composed by NODES; each node is itself a STRUCTURE composed by:
* a data point,
* a pointer to the NEXT node.

* Declaration:
_typedef struct sllist_
_{_
    _VALUE val;_
    _struct sllist *next;_
_}_
_sllnode;_

* The head of a sllist should be declared as something like a global variable POINTING TO _NULL_:
_sllnode *headOfList = NULL;_

* Each member of the _sllnode_ struct can be accessed with arrow notation:
_n->val = ...;_
i.e. the val member of the node pointed by the _sllnode_ struct ponter _n_ is equal to ...

* So that the link to the next node can be established modifying the pointer member of node:
_n->next = pointerToNextNode;_

* The end of the list is signalled as null:
_final->next = NULL;_

# ADDING A NODE
* Node insertion is typically implemented at the beginning of the linked list.
* Not necessary to perform insertion at the beginning, but faster.

* First create a node with malloc:
_node *n = malloc(sizeof(sllnode));_

* Then insert the datapoint into the value member of the node struct:
_n->val = value;_

* Then make the new node point to the first element (not the head) of the linked list:
_n->next = headOfList->next;_

* Finally, make the head point to the new node:
_headOfList->next = n;_