#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

int main() {
    string input;
    map<string, vector<string>> name_numbers;
    map<string, string> number_name;
    while (getline(cin, input) && input != "exit") {
        if (input[0] > '0' && input[0] < '9') {
            size_t pos_space = input.find(' ');
            string number = input.substr(0, pos_space);
            if (pos_space == string::npos) {
                map<string, string>::iterator it = number_name.find(number);
                if (it == number_name.end()) {
                    cout << "There is no such number in the phone book" << endl;
                } else cout << it->second << endl;
            } else {
                string name = input.substr(pos_space + 1, string::npos);
                pair<map<string, string>::iterator, bool> p = number_name.insert({number, name});
                if (p.second)name_numbers[name].push_back(number);
                else cout << "There is already a person with this phone number" << endl;
            }
        } else {
            map<string, vector<string>>::iterator it=name_numbers.find(input);
            if(it==name_numbers.end())cout<<"There is no such person in the phone book"<<endl;
            else{
                for(const auto& phone_num:it->second)cout<<phone_num<<' ';
                cout<<endl;
            }
        }
    }
    return 0;
}
