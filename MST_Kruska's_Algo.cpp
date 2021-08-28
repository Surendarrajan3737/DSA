#include <bits/stdc++.h>

using namespace std;

struct node{
    int u;
    int v;
    int w;
    node(int x,int y,int z){
        u = x;
        v = y;
        w = z;
    }
};

bool comp(node a,node b){
    if(a.w < b.w) return true;
    return false;
}

int findpar(int z,vector<int> &parent,vector<int> &rank1){
    if(parent[z] == z)
        return z;
    return parent[z] = findpar(parent[z],parent,rank1);
}

void Union(int u,int v,vector<int> &parent,vector<int> &rank1){
    int par1 = findpar(u,parent,rank1);
    int par2 = findpar(v,parent,rank1);

    if(rank1[par1] < rank1[par2]){
        parent[par1] = par2;
    }
    else if(rank1[par1] > rank1[par2]){
        parent[par2] = par1;
    }
    else{
        parent[par2] = par1;
        rank1[par1]++;
    }
}

int main()
{
    int N,m;
    cin >> N >> m;
    vector<node> edges;
    
    // Sorted based on weight
    for(int i=0;i<m;i++){
        int u,v,w;
        cin >> u >> v >> w;
        edges.push_back(node(u,v,w));
    }

    sort(edges.begin(),edges.end(),comp);

    // Disjoint set method used 
    vector<int> parent(N);
    vector<int> rank1(N,0);

    for(int i=0;i<N;i++){
        parent[i] = i;
    }
    
    int cst = 0;
    vector<pair<int,int>> mst;
    for(auto x : edges){
//       two nodes will combine only when their parents are different;
        if(parent[x.u] != parent[x.v]){
            cst += x.w;
            mst.push_back({x.u,x.v});
            Union(x.u,x.v,parent,rank1);
        }
    }

    cout << "The cst of the minimum spaning tree is : " << cst << '\n';

    for(auto x : mst){
        cout << x.first << " - " << x.second << '\n';
    }

    return 0;
}
