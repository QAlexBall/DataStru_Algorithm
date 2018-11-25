//
// Created by alex on 11/24/18.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

bool valid(const std::string &string);

using namespace std;


int main(int argc, char **argv) {
    std::cout << argc << std::endl;
    std::string data[10];
    std::ifstream input("a.txt");
    std::ofstream output("b.txt");

    int i = 0;
    while (input) {
        input >> data[i];
        output << data[i] << " ";
        i++;
    }
    for (int j = 0; j < i; j++) {
        std::cout << data[j] << " ";
    }

    output << "a";
    std::filebuf fb;
    fb.open("fb.txt", std::ios::out);
    std::ostream os(&fb);
    os << "Test for os!" << endl;


    struct PersonInfo {
        string name;
        vector<string> phones;
    };

    string line, word;
    vector<PersonInfo> people;


    while (getline(cin, line)) {
        if (line == "end") {
            break;
        }
        PersonInfo info;
        istringstream record(line);
        record >> info.name;
        while (record >> word)
            info.phones.push_back(word);
        people.push_back(info);
        cout << info.name << endl;
        for (auto &phone : info.phones) {
            cout << phone << endl;
        }
    }
    filebuf fb1;
    fb1.open("personInfo.txt", std::ios::out);
    ostream os1(&fb1);
    for (const auto &entry : people) {
        ostringstream formatted, badNums;
        for (const auto &nums : entry.phones) {
            if (!valid(nums)) {
                badNums << " " << nums;
            } else
                formatted << " " << nums;
        }
        if (badNums.str().empty()) {
            os1 << entry.name << " "
               << formatted.str() << endl;
        } else
            cerr << "input error: " << entry.name
                 << " invalid number(s)" << badNums.str() << endl;
    }
    return 0;
}

bool valid(const std::string &string) {
    return string.length() > 5;
}