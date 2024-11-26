#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

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

    for (int i = 0; i < no_problems; i++)
    {
        auto itr = find_if(begin(doc_list), end(doc_list), [&](struct doctor doc)
            {
                return doc.speciality == prb_list[i].speciality;
            });
        if (itr != doc_list.end())
        {
            cout << itr->name << " " << prb_list[i].name << endl;
            doc_list.erase(itr);
        }
    }

    
    return 0;
}