#include <iostream>
#include <algorithm>
using namespace std;

struct Node{ // KHỞI TẠO KIỂU NODE 
     int data;
     Node* next;

};

Node* create() {                         // HÀM KHỞI TẠO NODE ĐẦU TIÊN;
    Node* head = new Node;
    head = NULL;
    return head;
}



Node* addtail(Node* head, int value) {   // HÀM THÊM NODE VÀO CUỐI 
    Node* p;
    Node* temp = new Node;
    temp->data = value;
    temp->next = NULL;
    if (head == NULL) {                  // Nếu rỗng thì cho = temp luôn 
        head = temp;
    }
    else {
        p = head;
        while (p->next != NULL) {        // Duyệt đến khi con trỏ NEXT là null 
            p = p->next;
        }
        p->next = temp;
    }
    return head;
}
Node* addhead (Node* head, int value) {  // HÀM THÊM NODE ĐẦU
    Node* temp = new Node;
    temp->data = value;
    temp->next = NULL; 
    if (head == NULL) {
        head = temp; // //Nếu linked list đang trống thì Node temp là head luôn
    }
    else {
        Node* p = new Node;
        p = head;
        temp->next = p; // Trỏ next của temp = head hiện tại
        head = temp; // Đổi head hiện tại = temp(Vì temp bây giờ là head mới )
    }
    return head;
}


Node* Deletehead(Node* head) {                 // XÓA NODE ĐẦU
    if (head == NULL) cout << "khong co gi de xoa";
    else {
        head = head->next;
    }
    return head;
}

Node* Deletetail(Node* head) {                // XÓA NODE CUỐI 
    if (head==NULL ) {
        cout << "Khong co gi de xoa";
    }
    else if (head->next = NULL) {
        cout << "Khong co gi de xoa";
    }
    else {
        Node* p = new Node;
        p = head;
        while (p->next->next != NULL) {
            p = p->next;
        }
        p->next = NULL;
    }
    return head;
}
Node* DeletePosition(Node* head, int v) { // XOA VI TRI: V
    if (v == 0 || head == NULL || head->next == NULL)
    {
        Deletehead(head);
    }
    else
    {
        int k = 0;
        Node* p = head;
        while (k != v && p->next->next != NULL)
        {
            k++;
            p = p->next;
        }
        if (k == v)
        {
            p->next = p->next->next;
        }

    }
    return head;
}

void Traverser(Node* head) {            // HÀM IN 
    cout<<("\n");
    Node* mid;
    mid = head;
    while (mid != NULL) {
        cout << ("%5d", mid->data) <<endl<< " => SO TIEP THEO LA: ";
        mid = mid->next;
    }
    }

Node* input(int n) {                    // NHẬP N CÁI DANH SÁCH LIÊN KẾT ĐƠN
    Node* head = create();
    int value;
    for (int i = 0; i < n; i++) {
        cin >> value;
        head = addtail(head, value);
    }
    return head;
}

int main() {
    int n;
    cin >> n;
    Node* head;
    head = input(n);
    DeletePosition(head, 2);
        Traverser(head);
    
    return 0;
}
