#include <iostream>
#include <string>

using namespace std;

struct Node {
    char data;
    Node* next;
};

Node* createNode(char data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = nullptr;
    return newNode;
}

bool isEmpty(Node* top) {
    return top == nullptr;
}

Node* push(Node* top, char data) {
    Node* newNode = createNode(data);
    newNode->next = top;
    return newNode;
}

Node* pop(Node* top) {
    if (isEmpty(top)) {
        return nullptr;
    }
    Node* temp = top;
    top = top->next;
    delete temp;
    return top;
}

char peek(Node* top) {
    if (isEmpty(top)) {
        return '\0';
    }
    return top->data;
}

bool checkBrackets(const string& str) {
    Node* top = nullptr;
    for (size_t i = 0; i < str.size(); ++i) {
        char currentBracket = str[i];
        switch (currentBracket) {
        case '{':
        case '[':
        case '(':
            top = push(top, currentBracket);
            break;
        case '}':
            if (isEmpty(top) || peek(top) != '{') {
                return false;
            }
            top = pop(top);
            break;
        case ']':
            if (isEmpty(top) || peek(top) != '[') {
                return false;
            }
            top = pop(top);
            break;
        case ')':
            if (isEmpty(top) || peek(top) != '(') {
                return false;
            }
            top = pop(top); 
            break;
        }
    }
    return isEmpty(top); 
}

int main() {
    setlocale(LC_ALL, "ru");

    string inputStr;
    cout << "Введите строку: ";
    getline(cin, inputStr, ';'); 

    if (checkBrackets(inputStr)) {
        cout << "Строка корректна.\n";
    }
    else {
        cout << "Строка некорректна. Ошибка в строке: " << inputStr << endl;
    }

    return 0;
}