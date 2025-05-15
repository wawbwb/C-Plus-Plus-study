#include <iostream>

// 定义链表节点结构
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// 链表类
class LinkedList {
private:
    ListNode* head;

public:
    // 构造函数
    LinkedList() : head(nullptr) {}

    // 在链表头部插入节点
    void insertFront(int value) {
        ListNode* newNode = new ListNode(value);
        newNode->next = head;
        head = newNode;
    }

    // 在链表尾部插入节点
    void insertBack(int value) {
        ListNode* newNode = new ListNode(value);
        if (!head) {
            head = newNode;
            return;
        }
        ListNode* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = newNode;
    }

    // 删除第一个值为value的节点
    void remove(int value) {
        if (!head) return;

        if (head->val == value) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        ListNode* current = head;
        while (current->next && current->next->val != value) {
            current = current->next;
        }

        if (current->next) {
            ListNode* temp = current->next;
            current->next = temp->next;
            delete temp;
        }
    }

    // 打印链表
    void display() {
        ListNode* current = head;
        while (current) {
            std::cout << current->val << " -> ";
            current = current->next;
        }
        std::cout << "nullptr" << std::endl;
    }

    // 析构函数
    ~LinkedList() {
        while (head) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    LinkedList list;
    
    // 测试插入操作
    list.insertBack(1);
    list.insertBack(2);
    list.insertBack(3);
    list.insertFront(0);
    
    // 打印链表
    std::cout << "Original list: ";
    list.display();
    
    // 测试删除操作
    list.remove(2);
    std::cout << "After removing 2: ";
    list.display();
    
    return 0;
}