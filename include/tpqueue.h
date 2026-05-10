// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T>
class TPQueue {
 private:
  struct Node {
    T value;
    Node* next;
  };

  Node* head;

 public:
  TPQueue() {
    head = nullptr;
  }

  ~TPQueue() {
    while (head != nullptr) {
      Node* t = head;
      head = head->next;
      delete t;
    }
  }

  void push(T x) {
    Node* n = new Node;
    n->value = x;
    n->next = nullptr;

    if (head == nullptr || x.prior > head->value.prior) {
      n->next = head;
      head = n;
      return;
    }

    Node* c = head;

    while (c->next != nullptr &&
           c->next->value.prior >= x.prior) {
      c = c->next;
    }

    n->next = c->next;
    c->next = n;
  }

  T pop() {
    if (head == nullptr) {
      return T{};
    }

    Node* t = head;
    T res = head->value;

    head = head->next;
    delete t;

    return res;
  }

  bool isEmpty() {
    return head == nullptr;
  }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
