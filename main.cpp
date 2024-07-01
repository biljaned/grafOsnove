#include <bits/stdc++.h>

using namespace std;

const int MAXN=1005;//maximalan broj cvorova
vector<vector<int>> graf1(MAXN,vector<int>(0));//1. (bolji i korisceniji) nacin
bool graf2[MAXN][MAXN];//2. nacin
vector<bool> visited(MAXN,0);
void dfs(int node){//pretraga u dubinu
    if(visited[node]) return;
    cout << node << " ";
    visited[node]=true;
    for(int u:graf1[node])
        dfs(u);
}

int main()
{
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
    //ispisivanje grafa1
    cout << "1. nacin" << endl;
    for(int i=1; i<=n; i++){
        cout << "povezani sa " << i << " su: ";
        for(int x:graf1[i])
            cout << x << " ";
        cout << endl;
    }
    //ispisivanje grafa2
    cout << "2. nacin" << endl;
    for(int i=1; i<=n; i++){
        cout << "povezani sa " << i << " su: ";
        for(int j=1; j<=n; j++){
            if(graf2[i][j])
                cout << j << " ";
        }
        cout << endl;
    }
    cout << endl;
    cout << "poseceni po dfs: ";
    dfs(1);//pocinjemo pretragu iz 1. cvora po metodi deep first search
    cout << endl;


    return 0;
}
