#include <bits/stdc++.h>

using namespace std;

const int MAXN=1005;//maximalan broj cvorova
vector<vector<int>> graf1(MAXN,vector<int>(0));//1. (bolji i korisceniji) nacin
bool graf2[MAXN][MAXN];//2. nacin


int main()
{//proba
    int n,m;
    cin >> n >> m;
    //kreiranje grafa
    for(int i=0; i<m; i++){
        int a,b;
        cin >> a >> b;
        graf1[a].push_back(b);
        graf1[b].push_back(a);//posto je graf neusmeren
        graf2[a][b]=true;
        graf2[b][a]=true;
    }
    //ispisivanje grafa
    for(int i=1; i<=n; i++){
        cout << "povezani sa " << i << " su: ";
        for(int x:graf1[i])
            cout << x << " ";
        cout << endl;
    }


    return 0;
}
