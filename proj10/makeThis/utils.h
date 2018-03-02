/*
 * File:    utils.h
 * Authors: Christian Soto
 *
 * Purpose: Declares types and functions for the utils.c code.
 */


#ifndef UTILS_H
#define UTILS_H

/* target is a struct which represents a linkedList of target with a list of dependecies
*/

typedef struct target{
        struct target *next;
        struct dep *deps;
	struct command *commands;
        char *targetName;
	int visitedFlag;
	int primaryFlag;
	int targetFlag;
}target;

/* dep is a struct which represents a list of dependecies
*/
typedef struct dep{
        struct dep *next;
        struct target *dTarget;
} dep;

/* command is struct that will hold the commands for the target struct
*/
typedef struct command{
        char *theCommand;
        struct command *next;
}command;

/* addTarget()
 *
 * Input:  The old target List, and targetName and targetFlag to add.
 * Output: The updated target List
 *
 * This might require that we allocate a new node into the target List (or maybe
 * it might not);
 *
 * This returns NULL if there is a memory error; it will also clean up the
 * entire list if this happens.
 */

target *addTarget(target *list, char *targetName, int targetFlag);

/* freeList()
 *
 * Input:  The current list (which might be NULL)
 *
 * Frees all of the nodes (both taret and dependent) in the current list.
 */
void freeList(target *list);

/* addDep()
 *
 * Input:  The old target List, and depName to add.
 * Output: The updated target List and depenedent list
 *
 * This might require that we allocate a new node into the dependent List (or maybe
 * it might not);
 *
 * This returns NULL if there is a memory error; it will also clean up the
 * entire list if this happens.
 */

void addDep(target *head, char *targetName, char *depName);

/*printList(target *head)
 *
 *Input: the target linked list
 *Output: targets and dependents printed out in post order form.
*/


void printList(target *head);

void addCommand(target *head, char *targetName, char *commandStr);

char *trimwhitespace(char *str);

void postOrderTraverse(target *t);

void postOrder(target *head, char *targetName);

int countTargets(char *line);

#endif

