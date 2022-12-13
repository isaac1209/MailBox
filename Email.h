
#ifndef MAILBOX_EMAIL_H
#define MAILBOX_EMAIL_H
#include <iostream>
class Email {
private:
    std::string who;
    std::string date;
    std::string subject;
public:
    Email(std::string who,std::string date,std::string subject);
    friend std::ostream & operator<<(std::ostream& cout, Email p);
    friend struct CompWhoDateSubject;
    friend struct CompDateWhoSubject;
    friend struct CompSubjectWheDate;

};

Email::Email(std::string who, std::string date, std::string subject):
        who(std::move(who)),date(std::move(date)),subject(std::move(subject)) {}

std::ostream & operator<<(std::ostream& cout, Email p){
    cout<<p.who<<", "<<p.subject<<", "<<p.date<<std::endl;
    return cout;
}

#include "Email.h"
struct CompWhoDateSubject{
    bool operator()( Email& lhs, Email& rhs){
        if(lhs.who != rhs.who){
            return lhs.who < rhs.who;
        }

        if(lhs.date != rhs.date){
            return lhs.date < rhs.date;
        }

        return lhs.subject < rhs.subject;


    }
};

struct CompDateWhoSubject{
    bool operator()(Email& lhs, Email& rhs){

        if(lhs.date != rhs.date){
            return lhs.date < rhs.date;
        }
        if(lhs.who != rhs.who){
            return lhs.who < rhs.who;
        }


        return lhs.subject < rhs.subject;


    }
};


struct CompSubjectWheDate{
    bool operator()(Email& lhs, Email& rhs){

        if(lhs.subject != rhs.subject){
            return lhs.subject < rhs.subject;
        }

        if(lhs.who != rhs.who){
            return lhs.who < rhs.who;
        }

        return lhs.date < rhs.date;



    }
};


#endif //MAILBOX_EMAIL_H
