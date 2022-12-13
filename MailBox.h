#ifndef MAILBOX_MAILBOX_H
#define MAILBOX_MAILBOX_H
#include "Email.h"
#include <vector>
#include <algorithm>

class MailBox {
private:
    std::vector<Email> mailbox;
public:

  void SortWho();
  void SortDate();
  void SortSubject();
  std::vector<Email> print();
  void push(const Email& element);
    MailBox(size_t size);
  int size();

};

void MailBox::SortWho() {

std::sort(mailbox.begin(),mailbox.end(),CompWhoDateSubject());
}

void MailBox::SortDate() {

    std::sort(mailbox.begin(),mailbox.end(),CompDateWhoSubject());
}

void MailBox::SortSubject() {
    std::sort(mailbox.begin(),mailbox.end(),CompSubjectWheDate());
}

std::vector<Email> MailBox::print() {
    return mailbox;
}

void MailBox::push(const Email &element) {
mailbox.push_back(element);
}

int MailBox::size() {
    return mailbox.size();
}

MailBox::MailBox(size_t size) {
mailbox.reserve(size);
}

#endif //MAILBOX_MAILBOX_H
