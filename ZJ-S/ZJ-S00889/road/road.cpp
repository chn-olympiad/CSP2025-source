#include<bits/stdc++.h>
using namespace std;

const int N = 1e4+10;

priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;

struct T{
    vector<pair<int,int> > child;
    bool a1 = false,a2 = true; // in the tree | use
    int v1; // height | value
}t[N];

int n,m,k;
long long dp[N];


void reset(){
    for(int i=0;i<n+k;i++){
        t[i].a1 = false;
    }
}

long long mintree(){
    reset();
    long long ans=0;
    t[0].a1 = true;
    for(int i=0;i<t[0].child.size();i++){
        if(t[t[0].child[i].second].a2)q.push(t[0].child[i]);
    }
    while(!q.empty()){
        pair<int,int> edge = q.top();
        //cout << edge.second << " ";
        q.pop();
        if((!t[edge.second].a1) && t[edge.second].a2){
            ans+=edge.first;
            t[edge.second].a1 = true;
            for(int i=0;i<t[edge.second].child.size();i++){
                if(t[t[edge.second].child[i].second].a2)q.push(t[edge.second].child[i]);
            }
            //cout << edge.second << " ";
        }
    }
    //cout << endl << ans << endl;
    return ans;
}

int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin >> n >> m >> k;
    for(int i=0;i<m;i++){
        int x,y,w;
        cin >> x >> y >> w;
        t[x-1].child.push_back({w,y-1});
        t[y-1].child.push_back({w,x-1});
    }
    for(int i=0;i<k;i++){
        int v;
        t[n+i].a2 = false;
        cin >> t[n+i].v1;
        for(int j=0;j<n;j++){
            int tmp;
            cin >> tmp;
            t[n+i].child.push_back({tmp,j});
            t[j].child.push_back({tmp,n+i});
        }
    }
    dp[0] = mintree();
    for(int i=1;i<=k;i++){
        t[n+i-1].a2 = true;
        long long tmp = mintree() + t[n+i-1].v1;
        if(tmp>=dp[i-1]){
            t[n+i].a2 = false;
            dp[i] = dp[i-1];
        }
        else dp[i] = tmp;
    }
    cout << dp[k];
    return 0;
}