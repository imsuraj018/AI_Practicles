// Simple Rule-Based Chatbot in C++

#include <iostream>
#include <string>

using namespace std;

int main()
{
    string userInput;

    cout << "====================================\n";
    cout << "     Welcome to Customer Chatbot\n";
    cout << "====================================\n";

    cout << "Type 'exit' to end the chat.\n\n";

    while (true)
    {
        cout << "You: ";
        getline(cin, userInput);

        // Exit condition
        if (userInput == "exit")
        {
            cout << "Chatbot: Thank you for visiting. Goodbye!\n";
            break;
        }

        // Product Information
        else if (userInput.find("product") != string::npos)
        {
            cout << "Chatbot: We offer laptops, smartphones, and accessories.\n";
        }

        // Price Information
        else if (userInput.find("price") != string::npos)
        {
            cout << "Chatbot: Product prices start from Rs. 10,000.\n";
        }

        // Service Information
        else if (userInput.find("service") != string::npos)
        {
            cout << "Chatbot: We provide 24/7 customer support and free delivery.\n";
        }

        // Delivery Query
        else if (userInput.find("delivery") != string::npos)
        {
            cout << "Chatbot: Delivery usually takes 3-5 business days.\n";
        }

        // Return Policy
        else if (userInput.find("return") != string::npos)
        {
            cout << "Chatbot: Products can be returned within 7 days.\n";
        }

        // Greeting
        else if (userInput.find("hello") != string::npos ||
                 userInput.find("hi") != string::npos)
        {
            cout << "Chatbot: Hello! How can I help you today?\n";
        }

        // FAQ
        else if (userInput.find("payment") != string::npos)
        {
            cout << "Chatbot: We accept UPI, Credit Card, Debit Card, and Net Banking.\n";
        }

        // Unknown query
        else
        {
            cout << "Chatbot: Sorry, I didn't understand your query.\n";
        }
    }

    return 0;
}