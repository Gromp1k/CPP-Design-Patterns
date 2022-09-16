//
// Created by Kacper on 26/08/2022.
//

#ifndef CPP_DESIGN_PATTERNS_BRIDGE_H
#define CPP_DESIGN_PATTERNS_BRIDGE_H

#include <string>
#include <vector>

class TextAppImpl{
public:
    virtual void SendTextImpl(std::vector<std::string> recipients,std::string textField) = 0;
};

class PlayTextAppImpl : public TextAppImpl{
public:
    PlayTextAppImpl();
    virtual ~PlayTextAppImpl();
    virtual void SendTextImpl(std::vector<std::string> recipients, std::string textField);
};

class TMobileTextAppImpl : public TextAppImpl {
public:
    TMobileTextAppImpl();
    virtual ~TMobileTextAppImpl();
    virtual void SendTextImpl(std::vector<std::string> recipients, std::string textField);
};

class TextApp {
public:
    TextApp(TextAppImpl* impl);
    virtual ~TextApp();

    virtual void Open() = 0;
    virtual void Close() = 0;
    virtual void AddText(std::string textField);
    virtual void SendText();
    virtual void AddRecipient(std::string recipient);
    virtual void RemoveRecipient(std::string recipient);

private:
    TextAppImpl* m_pImpl;
    std::string m_textField;
    std::vector<std::string> m_recipients;
};

class GalaxyS22TextApp: public TextApp {
public:
    GalaxyS22TextApp(TextAppImpl* impl);
    virtual ~GalaxyS22TextApp();
    virtual void Open();
    virtual void Close();
};

class IPhone13TextApp : public TextApp {
public:
    IPhone13TextApp(TextAppImpl* impl);
    virtual ~IPhone13TextApp();
    virtual void Open();
    virtual void Close();
};

#endif //CPP_DESIGN_PATTERNS_BRIDGE_H
