#include<bits/stdc++.h>
using namespace std;

class process{
    public:
    int at;
    int bt;
    int tat;
    int ct;
    int wt;
};

void sortByAT(process parray[], int np)
{
    for (int i = 0; i < np; i++)
    {
        for (int j = i + 1; j < np; j++)
        {
            if (parray[i].at > parray[j].at)
            {
                process temp = parray[i];
                parray[i] = parray[j];
                parray[j] = temp;
            }
            if (parray[i].at == parray[j].at)
            {
                if (parray[i].bt > parray[j].bt)
                {
                    process temp = parray[i];
                    parray[i] = parray[j];
                    parray[j] = temp;
                }
            }
        }
    }
}

void calculateCT(process parray[], int np)
{
    int timeLine = 0;
    parray[0].ct = timeLine + parray[0].at + parray[0].bt;
    timeLine += parray[0].ct;
    for (int i = 1; i < np; i++)
    {
        if (parray[i].at > timeLine)
        {
            parray[i].ct = parray[i].at + parray[i].bt;
        }
        else
        {
            parray[i].ct = timeLine + parray[i].bt;
        }
        timeLine = parray[i].ct;
    }
}

void calculateTAT(process parray[], int np)
{
    for (int i = 0; i < np; i++)
    {
        parray[i].tat = parray[i].ct - parray[i].at;
    }
}

void calculateWT(process parray[], int np)
{
    for (int i = 0; i < np; i++)
    {
        parray[i].wt = parray[i].tat - parray[i].bt;
    }
}

void printProcess(process parray[], int np)
{
    for (int i = 0; i < np; i++)
    {
        cout << "Process" << i + 1 << " : ";
        cout << "Arrival Time: " << parray[i].at << " Burst Time: " << parray[i].bt << " Complete Time: " << parray[i].ct << " Turn Around Time: " << parray[i].tat << " Waiting Time: " << parray[i].wt << endl;
    }
}

int main()
{

    int np;
    cout << "\nEnter number of process: ";
    cin >> np;

    process *parray = new process[np];

    for (int i = 0; i < np; i++)
    {
        cout << "\nEnter process " << i + 1 << " arrival time: ";
        cin >> parray[i].at;
        cout << "Enter process " << i + 1 << " burst time: ";
        cin >> parray[i].bt;
    }

    sortByAT(parray, np);
    calculateCT(parray, np);
    calculateTAT(parray, np);
    calculateWT(parray, np);
    printProcess(parray, np);
}