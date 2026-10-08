// URL: https://www.naukri.com/code360/problems/insertion-in-a-singly-linked-list_4609646

/************************************************************

    Following is the LinkedList class structure:

    class Node {
    public:
        int data;
        Node *next;

        Node(int val) {
            this->data = val;
            next = NULL;
        }
        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
};

************************************************************/

Node* insert(Node* head, int n, int pos, int val) {

    Node* nodeToAdd = new Node(val);

    if(pos == 0) {
        nodeToAdd->next = head;
        head = nodeToAdd; 
        return head;
    }
    
    Node* temp = head;
    for(int i = 1 ; i < pos ; i++) {
        temp = temp->next;
    }

    nodeToAdd->next = temp->next;
    temp->next = nodeToAdd;

    return head;
}
