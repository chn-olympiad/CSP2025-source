#include<bits/stdc++.h>
#include<array> 
#define int long long
using namespace std;
const int N=1e5+9;
int f1[N],f2[N];
int maxn(array<int,3> a){
    int idx=0;
    for(int i=0;i<3;i++){
        if(a[idx]<a[i])idx=i;
    }
    return idx;
}
bool cmp1(array<int,3> x,array<int,3> y){
    return (x[maxn(x)])>(y[maxn(y)]);
}
bool cmp2(array<int,3> x,array<int,3> y){
    return (x[maxn(x)])<(y[maxn(y)]);;
}
int solve1(vector<array<int,3>> v,int n){
    int d[3]{};
    sort(v.begin(),v.end(),cmp2);
    int idx=maxn(v[0]);d[idx]++;
    f1[0]=v[0][idx];
    
    for(int i=1;i<n;i++){
        int idx=maxn(v[i]);d[idx]++;
        if(d[idx]<=n/2){f1[i]=f1[i-1]+v[i][idx];}
        else {
            int tmp=0;
            if(idx==0){
                tmp=max(v[i][1],v[i][2]);
            }else if(idx==1){
                tmp=max(v[i][0],v[i][2]);
            }else if(idx==2) {
                tmp=max(v[i][0],v[i][1]);
            }
            f1[i]=f1[i-1]+tmp;
        }
        
        //cout<<d[idx]<<" "<<idx<<" ";
        //cout<<endl;
       
    }
    //for(int i=0;i<3;i++)cout<<d[i]<<" ";
    return f1[n-1];

}
int solve2(vector<array<int,3>> v,int n){
    int d[3]{};
    sort(v.begin(),v.end(),cmp1);
    
    int idx=maxn(v[0]);d[idx]++;
    f2[0]=v[0][idx];
    for(int i=1;i<n;i++){
        int idx=maxn(v[i]);d[idx]++;
        if(d[idx]<=n/2){f2[i]=f2[i-1]+v[i][idx];}
        else {
            int tmp=0;
            if(idx==0){
                tmp=max(v[i][1],v[i][2]);
            }else if(idx==1){
                tmp=max(v[i][0],v[i][2]);
            }else if(idx==2) {
                tmp=max(v[i][0],v[i][1]);
            }
            f2[i]=f2[i-1]+tmp;
        }
        
        //cout<<d[idx]<<" "<<idx<<" ";
        //cout<<endl;
    }
    return f2[n-1];

}

signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
    int T;cin>>T;
    while(T--){
        int n;cin>>n;
        vector<array<int,3>> v;
        for(int i=1;i<=n;i++){
            int a1,a2,a3;cin>>a1>>a2>>a3;
            v.push_back({a1,a2,a3});
        };
        cout<<max(solve1(v,n),solve2(v,n));
        cout<<endl;
    }
}
