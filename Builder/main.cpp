#include <iostream>
#include <string>
#include <sstream>


class EmailBuilder;
class Email{
    public:
        friend class EmailBuilder;
        EmailBuilder static make();
        std::string toString() const;
    private:
        Email() = default;
        std::string _from, _to, _title, _content;
        friend std::ostream& operator <<(std::ostream&, const Email&);
};

class EmailBuilder{
    public:
        EmailBuilder& from(const std::string &from);
        EmailBuilder& to(const std::string &to);
        EmailBuilder& title(const std::string &title);
        EmailBuilder& content(const std::string &content);

        operator Email&&(){return std::move(email);}

    private:
        Email email;
};

EmailBuilder& EmailBuilder::from(const std::string &from){
    email._from = from;
    return *this;
}

EmailBuilder& EmailBuilder::to(const std::string &to){
    email._to = to;
    return *this;
}

EmailBuilder& EmailBuilder::title(const std::string &title){
    email._title = title;
    return *this;
}

EmailBuilder& EmailBuilder::content(const std::string &content){
    email._content = content;
    return *this;
}


EmailBuilder Email::make() { return EmailBuilder();}

std::string Email::toString() const{
    std::stringstream ss;
    ss << "From:" << _from << "\n"
       << "To:" << _to << "\n"
       << "Title:" << _title << "\n"
       << "Content:" << _content << "\n";
    return ss.str();
}

std::ostream& operator<<(std::ostream& ostream, const Email& email){
    ostream << email.toString();
}


int main(int c, char** v)
{
    Email email = Email::make()
                            .from("me@mail.com")
                            .to("you@mail.com")
                            .title("C++ friends")
                            .content("We love Builder Design Pattern!");

    std::cout << email.toString();
}