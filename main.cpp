#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    ifstream inFile("input.txt");

    int no_problems, no_doctors;
    struct problem
    {
        string name, speciality;
    };
    
    
    inFile >> no_problems;
    vector<struct problem> prb_list;

    for (int i = 0; i < no_problems; i++)
    {
        struct problem prb;
        inFile >> prb.name;
        inFile >> prb.speciality;
        cout << prb.name << ' ' << prb.speciality << '\n';
        prb_list.push_back(prb);
    }

    inFile >> no_doctors;

    struct doctor {
        string name, speciality;
    };

    vector<struct doctor> doc_list;

    for (int i = 0; i < no_doctors; i++)
    {
        struct doctor doc;
        inFile >> doc.name;
        inFile >> doc.speciality;
        cout << doc.name << ' ' << doc.speciality << '\n';
        doc_list.push_back(doc);
    }

    for (auto& problem : prb_list)
    {
        bool isFound = 0;
        for (auto& doctor : doc_list)
        {
            if (problem.speciality == doctor.speciality)
            {
                isFound = 1;
                break;
            }
        }
        isFound ? cout << problem.name << " Acceptat" << endl : cout << problem.name << " Respins" << endl;
    }
    return 0;
}