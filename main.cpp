#include <iostream>
#include "MailBox.h"
#include "Email.h"
void show(std::vector<Email>& my_mails);

int main() {

    MailBox my_emails(3);
    my_emails.push(Email("Bnders", "2002-02-02", "lab 1"));
    my_emails.push(Email("Anders", "2002-02-28", "lab 2"));
    my_emails.push(Email("Isaac", "2002-02-27", "lab 3"));
    my_emails.push(Email("Kanda", "2002-02-18", "lab 4"));
    my_emails.push(Email("Jojo", "2002-02-28", "lab 2"));
    my_emails.SortSubject();
    auto w=my_emails.print();
    my_emails.SortWho();
    auto y=my_emails.print();
    my_emails.SortDate();
    auto x=my_emails.print();
    //show(w);

   // std::cout<<"\n\n";
    //
    show(y);
    //std::cout<<"\n\n";
   //show(x);



    return 0;
}

void show(std::vector<Email> &my_mails) {

    for(auto e: my_mails){
        std::cout<<e;
    }
}