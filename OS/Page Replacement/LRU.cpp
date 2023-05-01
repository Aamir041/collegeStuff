#include <bits/stdc++.h>
using namespace std;

// void showlist(list<int> g)
// {
//     cout<<"List: ";
//     list<int>::iterator it;
//     for (it = g.begin(); it != g.end(); ++it)
//         cout << '\t' << *it;
//     cout << '\n';
// }

bool pageNotPresent(int frames[], int n, int pageNum)
{
    for (int i = 0; i < n; i++)
    {
        if (frames[i] == pageNum)
        {
            return false;
        }
    }
    return true;
}

void printFrame(int frames[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << frames[i] << " ";
    }
    cout << endl;
}

int lruEleIndex(int frames[], int n, int numReplace)
{
    for (int i = 0; i < n; i++)
    {
        if (frames[i] == numReplace)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int pageHit = 0;
    int pageFault = 0;
    list<int> recentPages;
    cout << "\nEnter number of frames: ";
    int n;
    cin >> n;
    

    int *frames = new int[n];
    for (int i = 0; i < n; i++)
    {
        frames[i] = -1;
    }

    int strLen;
    cout<<"\nEnter Reference String Length: ";
    cin>>strLen;
    cout<<endl;

    int *pages = new int[strLen];
    for (int i = 0; i < strLen; i++)
    {
        cout << "Enter page number: ";
        cin >> pages[i];
    }

    cout<<endl;
    int top = 0;

    for (int i = 0; i < strLen; i++)
    {  
        if (top > n-1)
        {
            if (pageNotPresent(frames, n, pages[i]))
            {
                int numReplace = recentPages.back();
                int lruIndex = lruEleIndex(frames, n, numReplace);
                if (lruIndex >= 0)
                {
                    frames[lruIndex] = pages[i];
                    recentPages.pop_back();
                    recentPages.push_front(pages[i]);
                }
                else{
                    cout<<"Error"<<endl;
                    return 0;
                }
                pageFault++;
            }
            else
            {
                pageHit++;
                recentPages.remove(pages[i]);
                recentPages.push_front(pages[i]);
            }
        }
        else
        {
            if (pageNotPresent(frames, n, pages[i]))
            {
                pageFault++;
                frames[top++] = pages[i];
                recentPages.push_front(pages[i]);
            }
            else{
                pageHit++;
                recentPages.remove(pages[i]);
                recentPages.push_front(pages[i]);
            }

        }
        // showlist(recentPages);
        printFrame(frames, n);
    }
    cout<<"Page Hit: "<<pageHit<<endl;
    cout<<"Page Fault: "<<pageFault<<endl;
}