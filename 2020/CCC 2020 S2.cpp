#include <iostream>
#include <map>
#include <vector>
#include <queue>

using namespace std;

const int MAX = 1010;
int m[MAX][MAX];

int M, N;

int main()  {
    cin >> M;
    cin >> N;

    map<int, vector<pair<int, int>>> ref;

    for (int i = 1; i <= M; ++i)    {
        for (int j = 1; j <= N; ++j)    {
            ref[i*j].emplace_back(pair<int, int> (i ,j));
        }
    }

    int temp;
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> m[i][j];
        }
    }

    int posX = 0, posY = 0;
    queue<pair<int, int>> q;
    for (auto i:ref[m[posX][posY]]) {
        q.push(i);
    }

    pair<int, int> tempP;
    while(!q.empty()) {
        tempP = q.front();
        q.pop();
        for (auto i:ref[m[tempP.first-1][tempP.second-1]]) {
            q.push(i);
        }
        ref[m[tempP.first-1][tempP.second-1]].clear();
        // = ref[m[tempP.first-1][tempP.second-1]].front();
        cout << tempP.first << " " << tempP.second << endl;
        //ref[m[posX-1][posY-1]].erase(ref[m[posX-1][posY-1]].begin());
        if (tempP.first == M && tempP.second == N)  {
            cout << "yes" << endl;
            return 0;
        }
    }

    cout << "no" << endl;

    return 0;
}