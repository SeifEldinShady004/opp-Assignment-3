// File name:A3_SheetPb2_20220160.cpp
// Purpose:do a task manger
// Author(s): maya ahmed
// ID(s):20220160
// Section:s6
// Date:8/12/2023
#include <bits/stdc++.h>
using namespace std;

class process
{
public:
    string name, sName;
    int pid, sHash, memory_Usage;

    void fill(string n, int id, string sn, int sh, int mem)
    {
        name = n;
        pid = id;
        sName = sn;
        sHash = sh;
        memory_Usage = mem;
    }
    static void get(vector<process> &processes)
    {
        ifstream file("C:\\tast\\gsgsgsgasagsgasgagasgsgag.txt");
        string line;
        int cntr = 0;

        while (getline(file, line))
        {
            if (cntr > 2)
            {
                stringstream ss(line);
                string word;
                vector<string> v;
                while (ss >> word)
                {
                    v.push_back(word);
                }
                v.pop_back();
                word.clear();
                int i = v.size() - 1;
                int mem = stoi(v[i--]);
                int sh = stoi(v[i--]);
                string sn = v[i--];
                int id = stoi(v[i--]);
                while (i >= 0)
                {
                    word = v[i--] + " " + word;
                }
                process task;
                task.fill(word, id, sn, sh, mem);
                processes.push_back(task);
            }
            cntr++;
        }
    }
    friend bool operator<(process &p1, process &p2)
    {
        if (p1.name != p2.name)
        {
            return p1.name < p2.name;
        }
        if (p1.pid != p2.pid)
        {
            return p1.pid < p2.pid;
        }
        return p1.memory_Usage < p2.memory_Usage;
    }
};

class process_List
{
    vector<process> processes;

public:
    process_List()
    {
        process::get(processes);
        sort(processes.begin(), processes.end());
    }

    void display()
    {
        cout << "Name\t\tPID\t\tSession Name\t\tSession#\t\tMemory Usage" << endl;
        cout << "========================= ======== ================ =========== ============\n";
        for (int i = 0; i < processes.size(); i++)
        {
            cout << processes[i].name << "\t\t" << processes[i].pid << "\t\t" << processes[i].sName << "\t\t" << processes[i].sHash << "\t\t" << processes[i].memory_Usage << " K\n";
        }
    }
};

int main()
{
    system("tasklist>C:\\tast\\gsgsgsgasagsgasgagasgsgag.txt");
    process_List taskManager;
    taskManager.display();

    return 0;
}