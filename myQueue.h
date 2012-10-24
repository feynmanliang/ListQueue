
/* 
 * queue.h -- public interface to the queue module
 */
#define public
#define private static

/* create an empty queue */
public void* qopen(void);        

/* deallocate a queue, assuming every element has been removed and deallocated */
public void qclose(void *qp);   

/* put element at end of queue */
public void qput(void *qp, void *elementp); 

/* get first element from a queue */
public void* qget(void *qp);

/* apply a void function (e.g. a printing fn) to every element of a queue */
public void qapply(void *qp, void (*fn)(void* elementp));
