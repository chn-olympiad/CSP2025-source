#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
string s;
int a[1000005],n;
bool cmp(int x,int y){
    return x>y;
}
signed main(){
    //freopen("number4.in","r",stdin);
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            a[++n]=s[i]-48;
        }
    }
    sort(a+1,a+1+n,cmp);
    if(a[1]==0) cout<<0;
    else for(int i=1;i<=n;i++) cout<<a[i];
    fclose(stdin);
    fclose(stdout);
    return 0;
}
