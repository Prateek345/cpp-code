// C++ program for addition of two polynomials
// using Linked Lists
#include <bits/stdc++.h>
using namespace std;

// Node structure containing power and coefficient of
// variable
struct Node {
	int coeff;
	int pow;
	struct Node* next;
};

// Function to create new node
void createNode(int x, int y, struct Node** temp)
{
	struct Node *r, *z;
	z = *temp;
	if (z == NULL) {
		r = (struct Node*)malloc(sizeof(struct Node));
		r->coeff = x;
		r->pow = y;
		*temp = r;
		r->next = (struct Node*)malloc(sizeof(struct Node));
		r = r->next;
		r->next = NULL;
	}
	else {
		r->coeff = x;
		r->pow = y;
		r->next = (struct Node*)malloc(sizeof(struct Node));
		r = r->next;
		r->next = NULL;
	}
}

// Function Adding two polynomial numbers
void PolyAdd(struct Node* poly1, struct Node* poly2,
			struct Node* poly)
{
	while (poly1->next && poly2->next) {
		// If power of 1st polynomial is greater then 2nd,
		// then store 1st as it is and move its pointer
		if (poly1->pow > poly2->pow) {
			poly->pow = poly1->pow;
			poly->coeff = poly1->coeff;
			poly1 = poly1->next;
		}

		// If power of 2nd polynomial is greater then 1st,
		// then store 2nd as it is and move its pointer
		else if (poly1->pow < poly2->pow) {
			poly->pow = poly2->pow;
			poly->coeff = poly2->coeff;
			poly2 = poly2->next;
		}

		// If power of both polynomial numbers is same then
		// add their coefficients
		else {
			poly->pow = poly1->pow;
			poly->coeff = poly1->coeff + poly2->coeff;
			poly1 = poly1->next;
			poly2 = poly2->next;
		}

		// Dynamically create new node
		poly->next
			= (struct Node*)malloc(sizeof(struct Node));
		poly = poly->next;
		poly->next = NULL;
	}
	while (poly1->next || poly2->next) {
		if (poly1->next) {
			poly->pow = poly1->pow;
			poly->coeff = poly1->coeff;
			poly1 = poly1->next;
		}
		if (poly2->next) {
			poly->pow = poly2->pow;
			poly->coeff = poly2->coeff;
			poly2 = poly2->next;
		}
		poly->next
			= (struct Node*)malloc(sizeof(struct Node));
		poly = poly->next;
		poly->next = NULL;
	}
}

// Display Linked list
void show(struct Node* node)
{
	while (node->next != NULL) {
		printf("%dx^%d", node->coeff, node->pow);
		node = node->next;
		if (node->coeff >= 0) {
			if (node->next != NULL)
				printf("+");
		}
	}
}

// Driver code
int main()
{
	struct Node *poly1 = NULL, *poly2 = NULL, *poly = NULL;

	// Create first list of 5x^2 + 4x^1 + 2x^0
	//insert nodes here
        
	// Create second list of -5x^1 - 5x^0
	createNode(1, 2, &poly2);
	createNode(-2, 1, &poly2);
	createNode(-4, 0, &poly2);
        createNode(3, 2, &poly1);
	createNode(6, 1, &poly1);
	createNode(6, 0, &poly1);


	printf("First Number: ");
	show(poly1);

	printf("\n\nSecond Number: ");
	show(poly2);

	poly = (struct Node*)malloc(sizeof(struct Node));

	// Function add two polynomial numbers
	PolyAdd(poly1, poly2, poly);

	// Display resultant List
	printf("\n\n Added polynomial: ");
	show(poly);

	return 0;
}
