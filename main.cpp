#include <iostream>

using namespace std;

class node {
  public: 
    char data;
    node* next;

    node(char data, node* next) {
      this->data = data;
      this->next = next;
    }
};

class list {
  public: 
    node* head;

    list () {
      head = nullptr;
    }

    void push (char data) {
      node* new_node = new node (data, head);
      head = new_node;
    }

    char pop () {
      node* del = head;
      char value = del->data;
      head = del->next;
      delete del;
      return value;
    }

    int calculate () {
      while(head->next != nullptr){
        int number1 = pop() - '0';
        char op = pop();
        int number2 = pop() - '0';
        int result = 0;
        
        if(op == '-'){
          result = number1 - number2;
        }
        if(op == '+'){
          result = number1 + number2;
        }
        if(op == '*'){
          result = number1 * number2;
        }
        if(op == '/'){
          result = number1 / number2;
        }
        
        push(result + '0');
      }

      int answer = pop() - '0';
      return answer;
    } 
};

int main () { 
  string ask1;
  std::cout << "what equation do u wanna solve ";
  std::cin >> ask1;

  list l;
  
  for(int i = ask1.length() - 1; i >= 0; i--) {
    char vali = ask1[i];
    l.push(vali);
  }
    
  cout << "\nresult: " << l.calculate() << "\n";
}
