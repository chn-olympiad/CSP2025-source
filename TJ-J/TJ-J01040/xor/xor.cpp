#include<bits/stdc++.h>
using namespace std;
int e[500005]={},c;
int d[10005][10005];
bitset<10005*10005> w;
//vector<int> d(500005*500005);
//bitset<500005*500005> d;
int dfs(int l,int r){
    if(l==r){
        return (e[r]^e[l-1])==c;
    }
    if(l<10005 && r<10005){
        if(w[l*r+r]){
            return d[l][r];
        }
        for(int b=l+1;b<=r;b++){
           d[l][r]=max(d[l][r],dfs(l,b-1)+dfs(b,r));
        }
        w[l*r+r]=1;
        return d[l][r]+(d[l][r]==0 && ((e[r]^e[l-1])==c));
    }
    int da=0;
    //cout<<'('<<l<<" "<<r<<":";
    for(int b=l+1;b<=r;b++){
        da=max(da,dfs(l,b-1)+dfs(b,r));
    }
    //cout<<da+(da==0 && ((e[r]^e[l-1])==c))<<')';
    return da+(da==0 && ((e[r]^e[l-1])==c));
}
int main(){
    //freopen("xor.in","r",stdin);
    //freopen("xor.out","w",stdout);
    freopen("xor4.in","r",stdin);
    int a;
    cin>>a>>c;
    for(int b=1;b<=a;b++){
        cin>>e[b];
        e[b]^=e[b-1];
        //if(d[b]==c){
        //    he++;
        //}
    }
    cout<<dfs(1,a);
	return 0;
}
