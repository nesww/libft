#include <libft/ftypes.h>
/*
 * Linked list.
 */
typedef struct s_list {
  void *content;
  struct s_list *next;
} t_list;

/*
 * ft_lstnew - Create a new linked list.
 * @param content (void*): content that will be stored
 *
 * Create and allocate memory for the new linked list.
 * Last element has next=NULL.
 *
 * Return: the pointer to the start of the linked list.
 */
t_list *ft_lstnew(void *content);

/*
 * ft_lstadd_front - Add a new element to the front of the list.
 * @param lst (t_list**): pointer to the address of the start of the list
 * @param newl (t_list*): new element to add
 *
 * Add a new element to the start of the linked list, acting as
 * the new head of the linked list. The previous head will be the
 * next element of the provided new element.
 */
void ft_lstadd_front(t_list **lst, t_list *newl);

/*
 * ft_lstsize - Get the size of the linked list.
 * @param lst (t_list*): addres of the start of the linked list
 *
 * Count each element of the linked list using its `next`,
 * containing the address of the next element until it's NULL.
 *
 * Return: the size of the linked list
 */
i32 ft_lstsize(t_list *lst);

/*
 * ft_lstlast - Get the last element of the linked list.
 * @param lst (t_list*): start address of the linked list
 *
 * Get the last element of the linked list. Uses the `next`
 * property of the struct checking if it's NULL.
 *
 * Return: the pointer to the last element (or tail) of the linked list
 */
t_list *ft_lstlast(t_list *lst);

/*
 * ft_lstadd_back - Add a new element to the tail of the list.
 * @param lst (t_list**): pointer to the address of the start of the list
 * @param newl (t_list*): new element to add
 *
 * Add a new element to the tail (end) of the linked list.
 * The previous last element will then point to the new current element,
 * and the new element will have no next (next set to NULL).
 */
void ft_lstadd_back(t_list **lst, t_list *newl);

/*
 * ft_lstdelone - Delete one single element of the list, freeing it.
 * @param lst (t_list*): address of the element to free
 * @param del (void (void*)): function interface to free memory
 *
 * Delete one element of the linked list, from its address.
 * Will free any allocated memory linked to the element.
 * The del function required will be used as an interface for
 * specific freeing strategy depending on the content of the list.
 */
void ft_lstdelone(t_list *lst, void (*del)(void *));

/*
 * ft_lstclear - Clear the linked list.
 * @param lst (t_list**): pointer to the start addres of the list
 * @param del (void (void*)): function interface to free memory
 *
 * Clear all the content of the list and delete/free every elements.
 * Uses the del interface function to free possibly allocated memory
 * depending on the content of the list.
 * The initial pointer is set to NULL.
 */
void ft_lstclear(t_list **lst, void (*del)(void *));

/*
 * ft_lstiter - Apply the function to all elements of the list.
 * @param lst (t_list*): address of the first element of the list
 * @param f (void (void*)): function to apply to every element
 *
 * Apply a function to all elements of the linked list, modifying its
 * content.
 */
void ft_lstiter(t_list *lst, void (*f)(void *));

/*
 * ft_lstmap - Apply the function to all elements of the list, to a new list.
 * @param lst (t_list*): address of the first element of the list
 * @param f (void (void*)): function to apply to every element
 *
 * Apply a function to all elements of the linked list, allocating a new
 * linked list memory.
 * If anything fails (any malloc), will clean memory with ft_lstclear, and
 * return NULL.
 *
 * Return: the address to the head of the new linked list modified with the
 * function, NULL if any malloc fails.
 */
t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
