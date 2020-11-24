#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <math.h>

using namespace std;

string decimal_to_binary(int number) {

    int binary_length = 0, number_copy = number;

    string binary_base;
    string binary;

    while(number_copy != 0)
    {
        int binary_digit = number_copy % 2;
        binary_base += to_string(binary_digit);
        number_copy /= 2;
        binary_length++;
    }

    for(int i = binary_length;i < binary_length + 8;i++) {
        if(i % 8 == 0)
            break;
        else
            binary_base += to_string(0);
    }

    int j = 0;

    for(int i = binary_base.size() - 1;i >= 0;i--) {
        binary += binary_base[i];
        j++;
    }

    return binary;
}

int binary_to_decimal(string binary_str) {
    int number,binary_length = 0;
    vector <int> binary_int;

    binary_length = binary_str.size();
    for(int i = 0;i < binary_length;i++) {
        if(binary_str[i] == '0')
            binary_int.push_back(0);
        else if(binary_str[i] == '1')
            binary_int.push_back(1);
    }

    for(int i = 0;i < binary_length;i++)
         number = (number * 2) + binary_int[i];

    return number;
}

int main()
{
    cout << "Welcome to Binary Star" << endl << endl;
    cout << "Enter code \'d b\' to convert decimal to binary." << endl;
    cout << "Enter code \'b d\' to convert binary to decimal." << endl;
    cout << "Enter code \'s b\' to convert string to binary." << endl;
    cout << "Enter code \'b s\' to convert binary to string." << endl;

    while(true) {
        char data_type, data_flow;

        cout << endl << "Please enter the code : ";
        scanf("%c %c",&data_type,&data_flow);

        cout << endl;

        // Decimal to Binary
        if(data_type == 'd' && data_flow == 'b') {
            int number = 0;
            cout << "Please enter the number : ";
            cin >> number;
            cout << "The Binary Format of the number " << number << " is " << decimal_to_binary(number) << endl;
        }
        // Binary to Decimal
        else if(data_type == 'b' && data_flow == 'd') {
            int number = 0;
            string binary;

            cout << "Please enter the Binary Format : ";
            cin >> binary;

            cout << "The Decimal Form of the Binary Format " << binary << " is " << binary_to_decimal(binary) << endl;
        }
        // String to Binary
        else if(data_type == 's' && data_flow == 'b') {
            string str,binary;

            cout << "Please enter the String : ";
            cin.ignore();
            getline(cin, str);

            for(int i = 0;i < str.size();i++)
                binary += decimal_to_binary(str[i]);

            cout << "The result is ";
            for(int i = 0;i < binary.size();i++) {
                if(i % 8 == 0 && i != 0)
                    cout << " ";
                cout << binary[i];
            }

            cout << endl;
        }
        // Binary to String
        else if(data_type == 'b' && data_flow == 's') {
            string binary,binary_8bit,binary_wo_spaces;
            string str;

            cout << "Please enter the Binary Format : ";
            cin.ignore();
            getline(cin, binary);

            for(int i = 0;i < binary.size();i++)
                if(binary[i] != ' ')
                    binary_wo_spaces += binary[i];

            binary = binary_wo_spaces;


            for(int i = 0;i < binary.size() + 1;i++) {
                if(i % 8 == 0 && i != 0) {
                    char character = binary_to_decimal(binary_8bit);
                    str += character;
                    binary_8bit.clear();
                    binary_8bit += binary[i];
                }
                else
                    binary_8bit += binary[i];
            }

            cout << "The String Form of the Binary Format is " << str << endl;
            cout << endl << "Press enter to continue " << endl;
        }
        else {
            cout << "Invalid Input . Try again" << endl << endl;
            main();
            return 0;
        }

        cin.ignore();

    }

    return 0;
}

