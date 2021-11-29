#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct Node
{
    int data;
    Node *left;
    Node *right;
};

// display the tree
void display(Node *root)
{
    if (root == NULL)
        return;
    printf("%d ", root->data);
    display(root->left);
    display(root->right);
}

// get min value node
Node *minValueNode(Node *root)
{
    Node *current = root;
    while (current->left != NULL)
    {
        current = current->left;
    }
    return current;
}

// get max value node
Node *maxValueNode(Node *root)
{
    Node *current = root;
    while (current->right != NULL)
    {
        current = current->right;
    }
    return current;
}

// insertion
Node *insert(Node *root, int data)
{
    if (root == NULL)
    {
        root = (Node *)malloc(sizeof(Node));
        root->data = data;
        root->left = NULL;
        root->right = NULL;
    }
    else if (data <= root->data)
    {
        root->left = insert(root->left, data);
    }
    else
    {
        root->right = insert(root->right, data);
    }
    return root;
}

// deletion
Node *deleteNode(Node *root, int data)
{
    if (root == NULL)
    {
        return root;
    }
    else if (data < root->data)
    {
        root->left = deleteNode(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = deleteNode(root->right, data);
    }
    else
    {
        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            root = NULL;
        }
        else if (root->left == NULL)
        {
            Node *temp = root;
            root = root->right;
            free(temp);
        }
        else if (root->right == NULL)
        {
            Node *temp = root;
            root = root->left;
            free(temp);
        }
        else
        {
            Node *temp = minValueNode(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }
    return root;
}

// search
void search(Node *root, int data)
{
    if (root == NULL)
    {
        printf("Not found\n");
        return;
    }
    else if (data < root->data)
    {
        search(root->left, data);
    }
    else if (data > root->data)
    {
        search(root->right, data);
    }
    else
    {
        printf("Found %d\n", root->data);
    }
}

// postordedr traversal
void postorder(Node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

// inorder traversal
void inorder(Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// preorder traversal
void preorder(Node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// height
int height(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    else
    {
        int lheight = height(root->left);
        int rheight = height(root->right);
        if (lheight > rheight)
        {
            return (lheight + 1);
        }
        else
        {
            return (rheight + 1);
        }
    }
}

// delete full tree & ask for confirmation
void deleteTree(Node *root)
{
    // ask for confirmation
    printf("\nAre you sure you want to delete the whole tree? (y/n) ");
    char ch;
    scanf(" %c", &ch);

    if (ch == 'y' || ch == 'Y')
    {
        // delete tree
        if (root != NULL)
        {
            deleteTree(root->left);
            deleteTree(root->right);
            free(root);
        }
        else{
            printf("\nTree is empty.\n");
        }
    }
    else{
        printf("\nTree not deleted.\n");
    }
}

// mirror of tree
void mirror(Node *root)
{
    if (root != NULL)
    {
        Node *temp = root->left;
        root->left = root->right;
        root->right = temp;
        mirror(root->left);
        mirror(root->right);
    }
}

// count nodes
int countNodes(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    else
    {
        return (countNodes(root->left) + countNodes(root->right) + 1);
    }
}

// main
int main()
{
    Node *root = NULL;
    int choice, data;
    while (1)
    {
        printf("\n1. Insert\n2. Delete\n3. Search\n4. Preorder\n5. Inorder\n6. Postorder\n7. Height\n8. Mirror\n9. Count Nodes\n10. Delete Tree\n11. Display\n12. Exit\n\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter the data: ");
            scanf("%d", &data);
            root = insert(root, data);
            break;
        case 2:
            printf("\nEnter the data: ");
            scanf("%d", &data);
            root = deleteNode(root, data);
            break;
        case 3:
            printf("\nEnter the data: ");
            scanf("%d", &data);
            search(root, data);
            break;
        case 4:
            printf("\nPreorder traversal: ");
            preorder(root);
            break;
        case 5:
            printf("\nInorder traversal: ");
            inorder(root);
            break;
        case 6:
            printf("\nPostorder traversal: ");
            postorder(root);
            break;
        case 7:
            printf("\nHeight: %d\n", height(root));
            break;
        case 8:
            printf("\nMirror of tree: ");
            mirror(root);
            break;
        case 9:
            printf("\nCount Nodes: %d\n", countNodes(root));
            break;
        case 10:
            deleteTree(root);
            break;
        case 11:
            // display
            display(root);
            break;
        case 12:
            exit(0);
        default:
            printf("\nWrong choice.\n");
        }
    }
    return 0;
}
