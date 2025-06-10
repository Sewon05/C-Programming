#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>

// ��� ����ü ����
typedef struct Node {
    int data;           // ������ �ʵ�
    struct Node* next;  // ���� ����� ������
} Node;

Node* insertFirst(Node* head, int data) {
    // ���ο� ��� ����
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL; // ���ο� ���� �ʱ⿡�� �ƹ��͵� ����Ű�� ����

    // Head�� NULL�� ��� (����Ʈ�� ��� ����)
    if (head == NULL) {
        return newNode; // �� ��尡 ����Ʈ�� �������� ��
    }

    // Head�� NULL�� �ƴ� ��� (����Ʈ�� ���� ��尡 ����)
    newNode->next = head; // �� ����� ������ ���� Head�� ����
    return newNode;       // �� ��带 Head�� ����
}

Node* insertLast(Node* head, int data) {
    // ���ο� ��� ����
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL; // �� ���� ����Ʈ�� ���� ��Ÿ��

    // ����Ʈ�� ��� �ִ� ���
    if (head == NULL) {
        return newNode; // �� ��尡 ����Ʈ�� �������� ��
    }

    // ����Ʈ�� ���� ��尡 �ִ� ���
    Node* current = head;
    while (current->next != NULL) { // ������ ��带 ã��
        current = current->next;
    }
    current->next = newNode; // ������ ����� next�� �� ��带 ����

    return head; // ����Ʈ�� ������(head) ��ȯ
}

Node* deleteHead(Node* head) {
    if (head == NULL) {
        printf("����Ʈ�� ��� �ֽ��ϴ�. ������ ��尡 �����ϴ�.\n");
        return NULL;
    }

    Node* temp = head;     // ���� ��� ��带 �ӽ� ����
    head = head->next;     // ��带 ���� ���� ����
    free(temp);            // ���� ��� �޸� ����

    return head;
}

// Ư�� ���� ���� ��� �ڿ� ����
void insertAfter(Node* head, int targetValue, int newData) {
    Node* current = head;

    // ��� Ž��
    while (current != NULL) {
        if (current->data == targetValue) {
            // �� ��� ���� �� ����
            Node* newNode = (Node*)malloc(sizeof(Node));
            newNode->data = newData;
            newNode->next = current->next;
            current->next = newNode;
            return;
        }
        current = current->next;
    }

    // ���� ��ġ�ϴ� ��尡 ���� ���
    printf("�� %d�� ���� ��带 ã�� �� �����ϴ�. �������� �ʽ��ϴ�.\n", targetValue);
}

// 2. ������ ��� ���� �Լ�
Node* deleteLast(Node* head) {
    if (head == NULL) {
        printf("����Ʈ�� ��� �ֽ��ϴ�. ������ ��尡 �����ϴ�.\n");
        return NULL;
    }

    if (head->next == NULL) { // ����Ʈ�� ��尡 �ϳ��� �ִ� ���
        free(head);
        return NULL;
    }

    Node* current = head;
    while (current->next->next != NULL) { // ���������� �� ��° ��� ã��
        current = current->next;
    }

    free(current->next);    // ������ ��� �޸� ����
    current->next = NULL;   // ���� ����� next�� NULL�� ����

    return head;
}

// 3. Ư�� ���� ��� ���� �Լ�
Node* deleteNode(Node* head, int targetValue) {
    if (head == NULL) {
        printf("����Ʈ�� ��� �ֽ��ϴ�. ������ ��尡 �����ϴ�.\n");
        return NULL;
    }

    if (head->data == targetValue) { // ��� ��尡 ��� ���� ���
        Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    Node* current = head;
    while (current->next != NULL && current->next->data != targetValue) {
        current = current->next;
    }

    if (current->next == NULL) { // ��� ���� ã�� ���� ���
        printf("�� %d�� ���� ��带 ã�� �� �����ϴ�.\n", targetValue);
        return head;
    }

    Node* temp = current->next;  // ������ ���
    current->next = current->next->next; // ��ũ ������
    free(temp);                   // ������ ��� �޸� ����

    return head;
}

Node* printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
    return;
}

void freeList(Node* head) {
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
    printf("��� ��尡 ���ŵǾ����ϴ�.\n");
}

int searchValue1(Node* head, const int* numB) {
    if (head == NULL) {
        printf("Head Node�� NULL �Դϴ�.\n");
        return -1;
    }
    Node* numA = head;
    int i = 0;
    while (numA != NULL) {
        ++i;
        if (numA->data == numB)return i;
        else numA = numA->next;
    }
    printf("���� �����ϴ�.\n");
    return -1;
}

void searchValue2(Node* head, const int* numB) {
    if (head == NULL) {
        printf("Head Node�� NULL �Դϴ�.\n");
        return;
    }
    if (head->data == numB) {
        printf("%d�� ������ : ����\n", numB);
        printf("%d�� ������ : %d\n", numB, head->next->data);
        return;
    }
    Node* numA = head;
    while (numA->next != NULL && numA->next->data != numB) {
        numA = numA->next;
    }
    if (numA->next = NULL) {
        printf("%d�� ã�� �� �����ϴ�.\n", numB);
        return;
    }
    printf("%d�� ���� �� : %d\n", numB, numA->data);
    //printf("%d�� ���� �� : %d\n", numB, numA->next->data);
}

int main() {
    Node* head = NULL;
    int val = 10;
    int pos = -1;
    for (int i = 0; i < 10; i++)
        head = insertLast(head, i);
    printList(head);
    pos = searchValue1(head, val);
    searchValue2(head, 10);
    printf("%d�� ��ġ�� %d��°", val, pos);
    freeList(head);

    return 0;
}
