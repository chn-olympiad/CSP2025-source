// #include<bits/stdc++.h>
// #define endl '\n'
// #define ull unsigned long long
// #define P pair<ull,ull>
// using namespace std;
// const int N=2e5+25;
// const int base1=131,base2=137;
// int n,q;
// P t1[N],t2[N];
// int L[N];
// ull qpow(ull base,ull power){
//     ull res=1;
//     while(power){
//         if(power&1)
//             res*=base;
//         base*=base;
//         power>>=1;
//     }
//     return res;
// }
// P gethash(string s){
//     ull sum1=0,sum2=0;
//     int len=s.size();
//     for(int i=0;i<len;i++){
//         sum1=sum1*base1+s[i]-'0';
//         sum2=sum2*base2+s[i]-'0';
//     }
//     return P{sum1,sum2};
// }
// void solve(){
//     cin>>n>>q;
//     for(int i=1;i<=n;i++){
//         string s1,s2;
//         cin>>s1>>s2;
//         L[i]=s1.size();
//         t1[i]=gethash(s1);
//         t2[i]=gethash(s2);
//     }
//     while(q--){
//         string s1,s2;
//         cin>>s1>>s2;
//         int len=s1.size();
//         if(len!=s2.size()){
//             cout<<0<<endl;
//             continue;
//         }
//         int ___=int(s1[0]!=s2[0]);
//         for(int i=1;i<len;i++)
//             if(s1[i]!=s2[i]&&s1[i-1]==s2[i-1])
//                 ___++;
//         if(___!=1){
//             cout<<0<<endl;
//             continue;
//         }
//         P H1=gethash(s1),H2=gethash(s2);
//         int cnt=0;
//         for(int i=1;i<=n;i++){
//             int _=0;
//             for(int j=0;j<len-L[i]+1;j++){
//                 ull _1=qpow(base1,j),_2=qpow(base1,L[i]);
//                 ull _1_=qpow(base2,j),_2_=qpow(base2,L[i]);
//                 if(i==2&&j==3)
//                     cout<<"--->";
//                 if(H1.first/_1%_2==t1[i].first/_1%_2&&H1.second/_1_%_2_==t1[i].second/_1_%_2_
//                  &&H2.first/_1%_2==t2[i].first/_1%_2&&H2.second/_1_%_2_==t2[i].second/_1_%_2_){
//                     _++;
//                     cout<<i<<" "<<j<<endl;
//                 }
//             }
//             cnt+=int(_==1);
//         }
//         cout<<cnt<<endl;
//     }
//     return;
// }
// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(0),cout.tie(0);
//     // freopen("replace.in","r",stdin);
//     // freopen("replace.out","w",stdout);
//     int T=1;
//     // cin>>T;
//     while(T--)
//         solve();
//     return 0;
// }
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
const int N=2e5+25;
int n,q;
string t1[N],t2[N];
void solve(){
    cin>>n>>q;
    for(int i=1;i<=n;i++)
        cin>>t1[i]>>t2[i];
    while(q--){
        string s1,s2;
        cin>>s1>>s2;
        int len=s1.size();
        if(len!=s2.size()){
            cout<<0<<endl;
            continue;
        }
        int ___=int(s1[0]!=s2[0]);
        for(int i=1;i<len;i++)
            if(s1[i]!=s2[i]&&s1[i-1]==s2[i-1])
                ___++;
        if(___!=1){
            cout<<0<<endl;
            continue;
        }
        int cnt=0;
        for(int i=1;i<=n;i++){
            int L=t1[i].size();
            int _=0;
            for(int j=0;j<len-L+1;j++)
                if(t1[i]==s1.substr(j,L)&&t2[i]==s2.substr(j,L))
                    _++;
            cnt+=int(_==1);
        }
        cout<<cnt<<endl;
    }
    return;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int T=1;
    // cin>>T;
    while(T--)
        solve();
    return 0;
}