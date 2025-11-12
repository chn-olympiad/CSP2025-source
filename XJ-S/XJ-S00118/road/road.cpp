#include<bits/stdc++.h>
using namespace std;

int n,m,k;

struct node{
    int to,hf;
};

vector<node> e[1000005];
int c[11];
int a[11][100005];
bool vis[100005];

int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        e[u].push_back(node{v,w});
        e[v].push_back(node{u,w});
    }
    bool flagc=0;
    for(int i=1;i<=k;i++){
        cin>>c[i];
        if(c[i]!=0) flagc=1;
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
            if(a[i][j]!=0)
                flagc=1;
        }
    }

    if(flagc==0&&k!=0){
        cout<<0;
        return 0;
    }
    else{
        long long ans=0;
        
        for(int i=1;i<=n;i++){
            //cout<<i<<endl;
            if(e[i].size()==1){
                vis[i]=1;
                ans+=e[i][0].hf;
                //cout<<"-*"<<e[i][0].hf<<endl;
            }
            else{
                vis[i]=1;
                int minn=INT_MAX;
                bool flag=0;
                for(int j=0;j<e[i].size();j++){
                    node eg=e[i][j];
                    if(vis[eg.to]==0){
                        flag=1;
                        minn=min(minn,eg.hf);
                    }
                    //cout<<i<<" "<<eg.to<<" "<<eg.hf;
                }
                //cout<<endl;
                if(flag==1)
                    ans+=minn;
                //cout<<minn<<endl;
            }
        }
        cout<<ans;
    }
    return 0; 
}
/*
4 4 0
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
