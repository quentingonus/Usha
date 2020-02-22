The program illustrating the use of singly linked list operations uses a text file to read data into the program. The task of checking if the data file is empty of not is the responsibility of the application, and not of the createList function. Hence, the main program is checking if the file is empty of not, as follows:

fseek(fp,0,SEEK_ENT) takes the file pointer to the end of the file. If the size of the file is zero, then it means it is an empty file. To find size of the file, the function ftell is used.

fseek(fp,0,SEEK_SET) resets the file pointer to the beginning of the file so that the data can be read from the file to build the list.

Remember to free the deleted node in your programs using the free(node*) function. In this example, the deleted node is being freed in the main funtion. That is because the main program is using the data from the deleted node to display. If the main function (or the called function) does not require the deleted node, free the node in the deleteNode function itself. Not freeing the deleted node results in the node occupying space on the heap.

In a doubly linked list, all functions that makes no change to the list structure (such as add and deletion functions) is the same as the singly linked list functions. Since the doubly linked list uses two pointers - previous and next - the pointers must be correctly adjusted when a new node is added or an existing node is removed from the list.