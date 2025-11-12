#include<bits/stdc++.h>
using namespace std;
long long n,q;
string st1[200010],st2[200010],t1,t2;
void Solve(){
    long long len,ans;
    bool p;
    while(q--){
        cin>>t1>>t2;
        len=t1.length();
        if(len!=(t2.length())){
            cout<<"0\n";
            continue;
        }
        ans=0;
        for(int i=1;i<=n;i++){
            long long lens=st1[i].length();
            for(int j=0;j+lens-1<len;j++){
                p=true;
                for(int k=j;k<=j+lens-1;k++)
                    if(t1[k]!=st1[i][k-j] or t2[k]!=st2[i][k-j]){
                        p=false;
                        break;
                    }
                if(p==true){
                    for(int k=0;k<j;k++)
                        if(t1[k]!=t2[k]){
                            p=false;
                            break;
                        }
                    for(int k=j+lens;k<len;k++)
                        if(t1[k]!=t2[k]){
                            p=false;
                            break;
                        }
                    if(p==true)ans++;
                }
            }
        }
        cout<<ans<<"\n";
    }
}
struct node{
    long long l,r;
}s1[200010],s2[200010],m1,m2;
long long calc_l(string s){
    long long len=s.length(),i=0;
    while(s[i]!='b' and i<len-1)i++;
    return i-0;
}
long long calc_r(string s){
    long long len=s.length(),i=0;
    while(s[i]!='b' and i<len-1)i++;
    return len-1-i;
}
void solve(){
    for(int i=1;i<=n;i++){
        s1[i].l=calc_l(st1[i]);
        s1[i].r=calc_r(st1[i]);
    }
    for(int i=1;i<=n;i++){
        s2[i].l=calc_l(st2[i]);
        s2[i].r=calc_r(st2[i]);
    }
    long long ans;
    while(q--){
        cin>>t1>>t2;
        if(t1.length()!=t2.length()){
            cout<<"0\n";
            continue;
        }
        ans=0;
        m1.l=calc_l(t1);m1.r=calc_r(t1);
        m2.l=calc_l(t2);m2.r=calc_r(t2);
        for(int i=1;i<=n;i++){
            if(m1.l<s1[i].l or m1.r<s1[i].r)continue;
            if(m1.l-s1[i].l+s2[i].l==m2.l and m1.r-s1[i].r+s2[i].r==m2.r)ans++;
        }
        cout<<ans<<"\n";
    }
}
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>n>>q;
    for(int i=1;i<=n;i++)
        cin>>st1[i]>>st2[i];
    if(n<=100 and q<=100){
        Solve();
        return 0;
    }
    solve();
    return 0;
}
