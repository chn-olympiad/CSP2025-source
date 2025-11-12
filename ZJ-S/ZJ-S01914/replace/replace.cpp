#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;
map<ull,int>mp;
ull base=233;
ull has(string s){
    int rs=0;
    for(char c:s){
        rs=rs*base+(ull)(c);
    }
    return rs;
}
string s1,s2;
signed main(){
    int n,q;
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    scanf("%d%d",&n,&q);
    while(n--){
        cin>>s1>>s2;
        for(int i=0;i<s1.size();i++){
            s1[i]=(s1[i]-'a')*26+s2[i]-'a';
        }
        mp[has(s1)]++;
    }
    while(q--){
        cin>>s1>>s2;
        string nw;
        int pl=-1,pr=-1;
        for(int i=0;i<s1.size();i++){
            if(s1[i]==s2[i]) continue;
            if(pl==-1) pl=i;
            pr=i;
        }
        int ans=0;
        for(int i=0;i<s1.size();i++){
            ull rs=0;
            for(int j=i;j<s1.size();j++){
                rs=rs*base+((s1[j]-'a')*26+s2[j]-'a');
                if(i<=pl&&pr<=j) ans+=mp[rs];
            }
        }
        printf("%d\n",ans);
    }
}