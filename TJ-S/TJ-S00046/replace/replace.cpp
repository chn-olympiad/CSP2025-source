#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,q;
pair <string,string> s[N],t[N];
int check(pair<string,string> s,pair <string,string> t,int j){
    for(int i=j;i<j+s.first.length();++i)
    	if(t.first[i]!=s.first[i-j])
    		return 0;
    for(int i=j;i<j+s.first.length();++i)
        t.first[i]=s.second[i-j];
    for(int i=0;i<t.first.length();i++)
        if(t.first[i]!=t.second[i])
            return 0;
    return 1;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
   freopen("replace.in","r",stdin);
   freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=0;i<n;i++)
        cin>>s[i].first>>s[i].second;
    for(int i=0;i<q;i++){
        int ans=0;
        cin>>t[i].first>>t[i].second;
        int tl=t[i].first.length();
        for(int k=0;k<n;k++)
        for(int j=0;j<tl;j++)
            if(j+s[k].first.length()<=tl&&check(s[k],t[i],j)) ans++;
        cout<<ans<<endl;
    }
    return 0;
}

//ljhjd ylwxh
//cljhjdn
