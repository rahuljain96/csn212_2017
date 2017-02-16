#include <iostream>
#include <vector>
using namespace std;

struct Interval{  // To represent an interval
		int low, high;
	};

struct IT_Node{  // To represent a node in Interval Tree
	Interval *i;
	int max;
	IT_Node *left, *right;
};

IT_Node * newNode(Interval i)  // To create a new interval in Interval Tree
{
    IT_Node *temp = new IT_Node;
    temp->i = new Interval(i);
    temp->max = i.high;
    temp->left = temp->right = NULL;
};

IT_Node *insert(IT_Node *root, Interval i)  
{
    if (root == NULL)
        return newNode(i);
 
    int l = root->i->low;
 
    if (i.low < l)
        root->left = insert(root->left, i);
 
    else
        root->right = insert(root->right, i);
 
    if (root->max < i.high)
        root->max = i.high;
 
    return root;
}

// A utility function to check if given two intervals overlap
bool overlap(Interval i1, Interval i2)
{
    if (i1.low <= i2.high && i2.low <= i1.high)
        return true;
    return false;
}
 
// The main function that searches a given interval i in a given
// Interval Tree.
Interval* overlapSearch(IT_Node *root, Interval i)
{
    // Base Case, tree is empty
    if (root == NULL) return NULL;
 
    // If given interval overlaps with root
    if (overlap(*(root->i), i))
        return root->i;

    if (root->left != NULL && root->left->max >= i.low)
        return overlapSearch(root->left, i);
 
    return overlapSearch(root->right, i);
}

void inorder(IT_Node *root)
{
    if (root == NULL) return;
    inorder(root->left);
    cout << "{" << root->i->low << ", " << root->i->high << "}"
         << " max = " << root->max << endl;
 
    inorder(root->right);
}

int main(){
	// Input Interval Data
	vector<Interval> V;
	Interval A = {12,15};
	V.push_back(A);
	Interval B = {10,30};
	V.push_back(B);
	Interval C = {17,19};
	V.push_back(C);
	Interval D = {5,20};
	V.push_back(D);
	Interval E = {15,20};
	V.push_back(E);
	Interval F = {30,40};
	V.push_back(F);


	IT_Node *root = NULL;

	// Inserting intervals into Interval Tree
	for(int i=0;i<V.size();i++){
		root = insert(root, V[i]);
	}

	// Inorder traversal of Interval Tree
	cout << "Inorder traversal of the Interval Tree :\n";
    inorder(root);

    Interval x = {14, 16};
 
    cout << "\nSearching for interval {" << x.low << "," << x.high << "}";
    Interval *res = overlapSearch(root, x);


    if (res == NULL)
        cout << "\nNo Overlapping Interval";
    else
        cout << "\nOverlaps with {" << res->low << ", " << res->high << "}";

    Interval y = {21, 23};
 
    cout << "\nSearching for interval {" << x.low << "," << x.high << "}";
    res = overlapSearch(root, y);


    if (res == NULL)
        cout << "\nNo Overlapping Interval";
    else
        cout << "\nOverlaps with {" << res->low << ", " << res->high << "}";



	return 0;
}
