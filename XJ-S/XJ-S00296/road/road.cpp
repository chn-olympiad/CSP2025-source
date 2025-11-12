#include<bits/stdc++.h>
using namespace std;
const int N = 1e4+20;
int fa[N];
int gf(int x){
    if(fa[x] == x){
        return x;
    }
    return fa[x] = gf(fa[x]);
}
const int K = 11;
int c[K];
vector<tuple<int,int,int>> ext_edge[K];
vector<tuple<int,int,int>> ext_uedg[K];
vector<tuple<int,int,int>> merge_dat(const vector<int> &points,int l,int r){
    if(l == r){
        return ext_uedg[points[l]];
    }
    int mid = (l + r)/2;
    auto v1 = merge_dat(points,l,mid);
    auto v2 = merge_dat(points,mid+1,r);
    vector<tuple<int,int,int>> v3(v1.size()+v2.size());
    merge(v1.begin(),v1.end(),v2.begin(),v2.end(),v3.begin());
    return v3;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    cin>>n>>m>>k;
    if(n == 1){
        cout<<0<<'\n';
        return 0;
    }
    for(int i = 1;i <= n;i++){
        fa[i] = i;
    }
    vector<tuple<int,int,int>> edgs;
    for(int i = 1;i <= m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        edgs.push_back(make_tuple(w,u,v));
    }
    sort(edgs.begin(),edgs.end());
    vector<tuple<int,int,int>> uedgs;
    for(tuple<int,int,int> e : edgs){
        int u,v,w;
        tie(w,u,v) = e;
        int uu = gf(u),vv = gf(v);
        if(uu == vv){
            continue;
        }
        uedgs.push_back(e);
        fa[uu] = vv;
    }
    long long ans =0 ;
    for(tuple<int,int,int> e : uedgs){
        ans += get<0>(e);
    }
    if(k == 0){
        cout<<ans<<'\n';
        return 0;
    }
    for(int i = 1;i <= k;i++){
        cin>>c[i];
        for(int j = 1;j <= n;j++){
            int w;
            cin>>w;
            ext_edge[i].push_back(make_tuple(w,i + n,j));
        }
        sort(ext_edge[i].begin(),ext_edge[i].end());
        for(int j = 1;j <= n + k;j++){
            fa[j] = j;
        }
        auto p1 = uedgs.begin(),p2 = ext_edge[i].begin();
        while(p1 != uedgs.end() && p2 != ext_edge[i].end()){
            int u,v,w;
            if(get<0>(*p1) < get<0>(*p2)){
                tie(w,u,v) = *p1;
                int uu = gf(u),vv = gf(v);
                if(uu != vv)fa[uu] = vv;
                p1++;
            }else{
                tie(w,u,v) = *p2;
                int uu = gf(u),vv = gf(v);
                if(uu != vv){
                    ext_uedg[i].push_back(*p2);
                    fa[uu] = vv;
                }
                p2++;
            }
        }
        //ext_uedg[i] = ext_edge[i];
        // 剩下的没必要算了。    
    }
    //long long ans = 0x3f3f3f3f3f3f3f3f;
    for(int S = 1;S < (1<<k);S++){
        long long cur_ans = 0;
        vector<int> points;
        for(int i = 0;i < k;i++){
            if((S >> i)&1){
                cur_ans += c[i + 1];
                points.push_back(i + 1);
            }
        }
        for(int i = 1;i <= n + k;i++){
            fa[i] = i;
        }
        auto es1 = merge_dat(points,0,points.size() - 1);
        auto p1 = uedgs.begin(),p2 = es1.begin();
        while(p1 != uedgs.end() && p2 != es1.end()){
            int u,v,w;
            if(get<0>(*p1) < get<0>(*p2)){
                tie(w,u,v) = *p1;
                p1++;
            }else{
                tie(w,u,v) = *p2;
                p2++;
            }
            int uu = gf(u),vv = gf(v);
            if(uu != vv){
                fa[uu] = vv;
                cur_ans += w;
            }
        }
        while(p1 != uedgs.end()){
            int u,v,w;
            tie(w,u,v) = *p1;
            p1++;
            int uu = gf(u),vv = gf(v);
            if(uu != vv){
                fa[uu] = vv;
                cur_ans += w;
            }
        }
        ans = min(ans,cur_ans);
        //cerr<<S<<' '<<cur_ans<<'\n';
    }
    cout<<ans<<'\n';
}