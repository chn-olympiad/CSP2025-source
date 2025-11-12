#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using ull=unsigned long long;
using pii=pair<int,int>;
constexpr int N=105,L=205;
constexpr unsigned long long B=13331,P=1e9+33;
int n,q;
string s1[N],s2[N];
ull p[L],h1[N][L],h2[N][L];
ull getH(ull* h,int l,int r) {
    return ((h[r]-h[l-1]*p[r-l+1]%P)%P+P)%P;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>q;
    p[1]=B;
    for(int i=2;i<=200;i++) p[i]=p[i-1]*B%P;
    for(int i=1;i<=n;i++) {
        cin>>s1[i]>>s2[i];
        h1[i][1]=s1[i][0];
        for(int j=1;j<s1[i].length();j++) h1[i][j+1]=(h1[i][j]*B%P+s1[i][j])%P;
        h2[i][1]=s2[i][0];
        for(int j=1;j<s2[i].length();j++) h2[i][j+1]=(h2[i][j]*B%P+s2[i][j])%P;
    }
    while(q--) {
        string t1,t2;cin>>t1>>t2;
        int len1=t1.length(),len2=t2.length();
        if(len1!=len2) {
            cout<<"0\n";
            return 0;
        }
        /*
        我不知道。
        */
    }
    return 0;
}