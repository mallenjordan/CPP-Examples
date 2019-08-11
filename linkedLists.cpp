#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>

using namespace std;

class LinkedNode {
	private:
	public:
		int intData;
		LinkedNode *next;
};

class LinkedList {
	private:
		LinkedNode *head, *tail, *current;
		int intSize;

	public:
		LinkedList() {
			head = NULL;
			tail = NULL;
			current = NULL;
			intSize = 0;
		}

		LinkedNode *front(void) { return head; }
		LinkedNode *back(void) { return tail; }

		int size(void) { return intSize; }

		void push_front(LinkedNode *node) {
			if (node != NULL) {
				if (intSize == 0) { head = tail = node; }
				else {
					node->next = head;
					head = node;
				}
				intSize++;
			}
		}

		void push_back(LinkedNode *node) {
			if (node != NULL) {
				if (intSize == 0) { head = tail = node; }
				else {
					tail->next = node;
					tail = node;
				}
				intSize++;
			}
		}

		// Tnsert new node after index.
		void push_index(LinkedNode *node, int intIndex) {
			if ((node == NULL) || (intIndex < 0) || (intIndex >= intSize)) { return; }
			else {
				if (intSize == 0) {
					push_front(node);
				}
				else {
					current = at(intIndex);
					node->next = current->next;
					current->next = node;
					intSize++;
				}
			}
		}

		// Note: pop'n nodes out will not delete the memory allocations.
		// This only removes them from the linked list and returns the removed node address.
		LinkedNode *pop_front (void) {
			LinkedNode *nodeReturn = NULL;

			if (intSize > 0) {
				nodeReturn = head;

				intSize--;
				if (intSize == 0) { head = tail = current = NULL; }
				else { head = head->next; }
			}

			return nodeReturn;
		}

		LinkedNode *pop_back (void) {
			LinkedNode *nodeReturn = NULL;

			if (intSize > 0) {
				nodeReturn = tail;

				intSize--;
				if (intSize == 0) { head = tail = current = NULL; }
				else {
					tail = at(intSize - 1);
					tail->next = NULL;
				}
			}

			return nodeReturn;
		}

		LinkedNode *pop_index (int intIndex) {
			LinkedNode *nodeReturn = NULL, *nodeParent = NULL;

			if (intSize > 0) {
				nodeReturn = at(intIndex);

				intSize--;
				if (intSize == 0) { head = tail = current = NULL; }
				else {
					if (intIndex == 0) {
						head = head->next;
					}
					else {
						nodeParent = at(intIndex - 1);
						nodeParent->next = nodeReturn->next;
					}
				}
			}

			return nodeReturn;
		}

		// Swaps the two nodes.
		void swap(int intIndexA, int intIndexB) {
			LinkedNode *nodeA = NULL, *nodeB = NULL;
			if ((intIndexA < 0) || (intIndexA >= intSize) || (intIndexB < 0) || (intIndexB >= intSize) || (intIndexA == intIndexB)) { return; }
			else {
				if (intIndexA == 0) {
					nodeB = pop_index(intIndexB);
					nodeA = pop_index(intIndexA);

					push_front(nodeB);
					push_index(nodeA, intIndexB - 1);
				}
				else {
					nodeB = pop_index(intIndexB);
					nodeA = pop_index(intIndexA);
					push_index(nodeB, intIndexA - 1);
					push_index(nodeA, intIndexB - 1);
				}
			}
		}

		// Just clears the whole linked list.
		// Warning: No memory handling here, nodes are still out there.
		void clear(void) {
			intSize = 0;
			head = tail = current = NULL;
		}

		LinkedNode *at (int intIndex) {
			current = NULL;
			if ((intIndex < 0) || (intIndex >= intSize) || (intSize == 0)) { return NULL;  }
			else {
				current = head;
				for (int intIteration = 0; intIteration < intIndex; intIteration++) {
					current = current->next;
				}

				return current;
			}
		}
};

int main(void) {
	LinkedNode *nodeNew = NULL;
	LinkedNode *nodeHandler = NULL;
	LinkedList linkList;
	int intIndex = 0, intSize = 0;

	srand((unsigned int)time(NULL));

	for (intIndex = 0; intIndex < 10; intIndex++) {
		nodeNew = new LinkedNode;
		nodeNew->intData = rand() + 1;
		linkList.push_back(nodeNew);
		nodeNew = NULL;
	}
	
	cout << "Number of nodes in Linked List: " << linkList.size() << endl;

	nodeHandler = linkList.front();
	intSize = linkList.size();
	for (intIndex = 0; intIndex < intSize; intIndex++) {
		cout << "Node #[" << intIndex << "] Data[" << setw(6) << nodeHandler->intData << "]" << endl;
		nodeHandler = nodeHandler->next;
	}
	nodeHandler = NULL;

	// A little fun node swap
	linkList.swap(1, 8);

	// Need to delete out data before exiting.
	intSize = linkList.size();
	for (intIndex = 0; intIndex < intSize; intIndex++) {
		nodeHandler = linkList.pop_front();
		if (nodeHandler != NULL) {
			delete nodeHandler;
			nodeHandler = NULL;
		}
	}

	return 0;
}
