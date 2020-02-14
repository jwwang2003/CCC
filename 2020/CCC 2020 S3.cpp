#include<iostream>
#include<map>

using namespace std;

bool check(map<string, bool> &m, map<char, int> &ref, string n, string h)   {
    if (m[h])   return false;
    else    {
        map<char, int> mTemp;
        for (int i = 0; i < h.size(); ++i)   {
            ++mTemp[h[i]];
        }
        if (ref == mTemp)   {
            m[h] = true;
            return true;
        }
        else return false;
    }
}

int main()  {
    string N;
    string K;
    cin >> N;
    cin >> K;
    int nL = N.size();
    int kL = K.size();

    map<char, int> ref;
    map<string, bool> storage;
    for (int i = 0; i < nL; ++i) {
        ++ref[N[i]];
    }
    
    int counter = 0;
    for (int i = 0; i <= kL - nL; ++i)   {
        if (check(storage, ref, N, K.substr(i, nL)))    {
            ++counter;
        }
    }

    cout << counter << endl;

    return 0;
}