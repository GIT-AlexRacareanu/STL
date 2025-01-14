
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include<set>

using namespace std;


struct problem
{
    string id, speciality;
    int arrivalTime, cureTime, priority;
};

struct doctor {
    string id;
    int nr_specialities,freeAfter = 9;
    set<string> specialities;
    vector<pair<string,int>> cured;
};

int main()
{
    ifstream inFile("input.txt");

    int no_problems, no_doctors;


    inFile >> no_problems;
    vector<struct problem> prb_list;

    for (int i = 0; i < no_problems; i++)
    {
        struct problem prb;
        inFile >> prb.id;
        inFile >> prb.speciality;
        inFile >> prb.arrivalTime;
        inFile >> prb.cureTime;
        inFile >> prb.priority;
        prb_list.push_back(prb);
    }

    inFile >> no_doctors;

    vector<struct doctor> doc_list;

    for (int i = 0; i < no_doctors; i++)
    {
        struct doctor doc;
        inFile >> doc.id;
        inFile >> doc.nr_specialities;
        for (int i = 0; i < doc.nr_specialities; i++)
        {
            string speciality;
            inFile >> speciality;
            doc.specialities.insert(speciality);
        }
        doc_list.push_back(doc);
    }

    sort(prb_list.begin(), prb_list.end(), [](auto &prb1, auto &prb2)
        {
            if(prb1.arrivalTime == prb2.arrivalTime)
                return prb1.priority > prb2.priority;            
            return prb1.arrivalTime < prb2.arrivalTime;
        });
    
    for (auto& prb : prb_list)
    {
        auto doctor = find_if(doc_list.begin(), doc_list.end(), [&](struct doctor doc) {
            return doc.specialities.contains(prb.speciality) && doc.freeAfter <= prb.arrivalTime && doc.freeAfter+prb.cureTime<=17;
            });
        if (doctor != doc_list.end())
        {
            doctor->freeAfter += prb.cureTime;
            doctor->cured.push_back(pair<string,int>(prb.id,prb.arrivalTime));
        }
    }
    for (auto& doc : doc_list)
    {
        if (!doc.cured.empty())
        {
            cout << doc.id << " " << doc.cured.size() << " ";
            for (auto& sth : doc.cured)
            {
                cout << sth.first << " " << sth.second << " ";
            }
            cout << endl;
        }
    }

    return 0;
}
