#include <bits/stdc++.h>
using namespace std;
int n,q,cnt;
unordered_map<string,int>mp;
struct u{
    map<int,int>a;
};
vector<u>t;
vector<int>tr[400009];
int f[5000009];
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    int tot=0;
    for (int i=1;i<=n;i++){
        string s1,s2;
        cin>>s1>>s2;
        if (mp[s1]==0)mp[s1]=++cnt;
        if (mp[s2]==0)mp[s2]=++cnt;
        tr[mp[s1]].push_back(mp[s2]);
    }
    t.resize(cnt+1);
    for (int i=1;i<=cnt;i++){
        for (int v:tr[i]){
            t[i].a[v]=1;
        }
    }
    for (int i=1;i<=q;i++){
        string t1,t2;
        cin>>t1>>t2;
        if (t1.size()!=t2.size()){cout<<"0\n";continue;}
        f[0]=1;
        int ans=0;
        for (int j=0;j<t1.size();j++){
            f[j+1]=f[j]&(t1[j]==t2[j]);
        }
        for (int j=t1.size();j>0;j--){
            for (int k=0;k<j;k++){
                if (f[k]==0)break;
                int s1=mp[t1.substr(k,j-k)],s2=mp[t2.substr(k,j-k)];
                if (s1==0||s2==0){continue;}
                if (t[s1].a[s2])ans++;
            }
            if (t1[j-1]!=t2[j-1])break;
        }
        cout<<ans<<"\n";
    }
    return 0;
}
