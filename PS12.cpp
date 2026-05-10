// Rule-Based Elementary Chatbot using C++

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// Function to convert string into lowercase
string toLowerCase(string text)
{
    transform(text.begin(), text.end(), text.begin(), ::tolower);
    return text;
}

int main()
{
    string userInput;

    cout << "========================================\n";
    cout << "      CUSTOMER INTERACTION CHATBOT\n";
    cout << "========================================\n";
    cout << "Type 'exit' to end the conversation.\n\n";

    while (true)
    {
        cout << "You: ";
        getline(cin, userInput);

        // Convert input to lowercase
        userInput = toLowerCase(userInput);

        // Exit condition
        if (userInput == "exit")
        {
            cout << "Chatbot: Thank you for visiting us. Goodbye!\n";
            break;
        }

        // Greeting
        else if (userInput.find("hello") != string::npos ||
                 userInput.find("hi") != string::npos)
        {
            cout << "Chatbot: Hello! How may I assist you today?\n";
        }

        // Product Information
        else if (userInput.find("product") != string::npos)
        {
            cout << "Chatbot: We provide laptops, smartphones, headphones, and smart watches.\n";
        }

        // Price Query
        else if (userInput.find("price") != string::npos ||
                 userInput.find("cost") != string::npos)
        {
            cout << "Chatbot: Prices start from Rs. 5,000 depending on the product.\n";
        }

        // Service Query
        else if (userInput.find("service") != string::npos)
        {
            cout << "Chatbot: We offer free delivery, installation, and 24/7 customer support.\n";
        }

        // Delivery Query
        else if (userInput.find("delivery") != string::npos)
        {
            cout << "Chatbot: Delivery takes approximately 3 to 5 working days.\n";
        }

        // Payment Query
        else if (userInput.find("payment") != string::npos)
        {
            cout << "Chatbot: We accept UPI, Debit Card, Credit Card, and Net Banking.\n";
        }

        // Return Policy
        else if (userInput.find("return") != string::npos ||
                 userInput.find("refund") != string::npos)
        {
            cout << "Chatbot: Products can be returned within 7 days with a valid bill.\n";
        }

        // Contact Query
        else if (userInput.find("contact") != string::npos)
        {
            cout << "Chatbot: You can contact us at support@company.com.\n";
        }

        // Working Hours
        else if (userInput.find("timing") != string::npos ||
                 userInput.find("hours") != string::npos)
        {
            cout << "Chatbot: Our support service is available from 9 AM to 9 PM.\n";
        }

        // Default response
        else
        {
            cout << "Chatbot: Sorry, I could not understand your query.\n";
        }
    }

    return 0;
}