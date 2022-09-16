//
// Created by Kacper on 26/08/2022.
//
#include "Bridge.h"


void SendText(TextApp& textApp)
{
    textApp.Open();

    textApp.AddRecipient(std::string("123-456-789"));
    textApp.AddRecipient(std::string("888-555-333"));

    textApp.AddText(std::string("Can you hear me now?"));

    textApp.SendText();

    textApp.Close();
}

int main()
{
    PlayTextAppImpl playTextAppImpl;
    TMobileTextAppImpl tMobilePhoneTextAppImpl;

    GalaxyS22TextApp  concreteTextApp(&playTextAppImpl);
    SendText(concreteTextApp);

    return 0;
}
