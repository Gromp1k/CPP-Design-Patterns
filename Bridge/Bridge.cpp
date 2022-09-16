//
// Created by Kacper on 26/08/2022.
//
#include "Bridge.h"
#include <iostream>
PlayTextAppImpl::PlayTextAppImpl() {}
PlayTextAppImpl::~PlayTextAppImpl() {}

void PlayTextAppImpl::SendTextImpl(std::vector<std::string> recipients, std::string textField) {
    std::cout << "Sending message...\n\n" << std::string("\"") << textField << std::string("\"") << "\n\n";
    std::cout << "To recipients : \n";
    bool isFirst = true;
    for(auto r = recipients.begin(); r != recipients.end(); ++r){
        if(isFirst){
            std::cout << "   " << *r ;
            isFirst = false;
        }
        else{
            std::cout << "\n" << "   " << *r;
        }
    }
    std::cout << "\nover Sprint network\n\n";
}

TMobileTextAppImpl::TMobileTextAppImpl() {}
TMobileTextAppImpl::~TMobileTextAppImpl() {}

void TMobileTextAppImpl::SendTextImpl(std::vector<std::string> recipients, std::string textField) {
    std::cout << "Sending message...\n\n" << std::string("\"") << textField << std::string("\"") << "\n\n";
    std::cout << "To recipients : \n";
    bool isFirst = true;
    for(auto r = recipients.begin(); r != recipients.end(); ++r){
        if(isFirst){
            std::cout << "   " << *r ;
            isFirst = false;
        }
        else {
            std::cout << "\n" << "   " << *r;
        }
    }
    std::cout << "\nover Verizon network\n\n";
}

TextApp::TextApp(TextAppImpl * impl): m_pImpl(impl) {}
TextApp::~TextApp() {}

void TextApp::AddText(std::string textField) {
    m_textField = textField;
}
void TextApp::SendText() {
    m_pImpl->SendTextImpl(m_recipients, m_textField);
}
void TextApp::AddRecipient(std::string recipient) {
    m_recipients.push_back(recipient);
}
void TextApp::RemoveRecipient(std::string recipient) {
    auto r = find(m_recipients.begin(), m_recipients.end(), recipient);
    if (r != m_recipients.end()) {
        m_recipients.erase(r);
    }
}

GalaxyS22TextApp::GalaxyS22TextApp(TextAppImpl* impl): TextApp(impl) {}
GalaxyS22TextApp::~GalaxyS22TextApp() {}

void GalaxyS22TextApp::Open() {
    std::cout << "Opening Galaxy S8 Text App.\n\n";
}
void GalaxyS22TextApp::Close() {
    std::cout << "Closing Galaxy S8 Text App.\n\n";
}

IPhone13TextApp::IPhone13TextApp(TextAppImpl* impl): TextApp(impl) {}
IPhone13TextApp::~IPhone13TextApp() {}

void IPhone13TextApp::Open() {
    std::cout << "Opening IPhone 8 Text App.\n\n";
}

void IPhone13TextApp::Close() {
    std::cout << "Closing IPhone 8 Text App.\n\n";
}