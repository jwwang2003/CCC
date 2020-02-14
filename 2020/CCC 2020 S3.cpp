#include<iostream>
#include<map>

using namespace std;

bool check(map<string, bool> &m, const map<char, int> &ref, string n, string h)   {
    // if the permutation is already discovered, return false
    if (m[h])   return false;
    else    {
        // load h into map for comparison
        map<char, int> mTemp;
        for (int i = 0; i < h.size(); ++i)   {
            ++mTemp[h[i]];
        }
        if (ref == mTemp)   {
            // valid permutation, add to discovered permutations, then return true
            m[h] = true;
            return true;
        }
        else return false;
    }
}

int main()  {
    string N, H;
    cin >> N;
    cin >> H;
    int nL = N.size();
    int hL = H.size();

    map<char, int> ref;         // map for comparing permutation
    map<string, bool> storage;  // storing exiting permutations
    storage[N] = true;          // N (needle), the permutation itself should not repeat again

    // Setting up reference map
    for (int i = 0; i < nL; ++i) {
        ++ref[N[i]];
    }


    int counter = 0;
    for (int i = 0; i <= hL - nL; ++i)   {
        // read a chunk of string from H that is same size as N
        // therefore i must be smaller or equal to H length - N length
        if (check(storage, ref, N, H.substr(i, nL)))    {
            // add one to counter if it is a valid permutation
            ++counter;
        }
    }

    // Output
    cout << counter << endl;

    return 0;
}