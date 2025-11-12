#include<bits/stdc++.h>
using namespace std;
int ch[5003003][26],ch2[3003003][26],ch3[3003003][26];
int dfn[3003003],sz[3003003];
int st[200200];
string a[200200],b[200200],at[200200];
int ls[200200],rs[200200],lp[200200],rp[200200];
int ans[200200];
vector<pair<int,int> >vs[3003003];
int tot,tot2,tot1,zong;
int n,q;
vector<int>vv[5003003],v[5003003],vt[3003003];
void dfs(int x){
    dfn[x]=++zong;sz[x]=1;
    for (int i=0;i<26;i++)
    if(ch2[x][i]){
        int y=ch2[x][i];
        dfs(y);sz[x]+=sz[y];
    }
}
bool cmp(int x,int y){
    return dfn[st[x]]<dfn[st[y]];
}
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    // cerr<<1.0*3003003*26*3*4/1024/1024<<"\n";
    cin>>n>>q;
    for (int i=1;i<=n;i++){
        cin>>a[i]>>b[i];
        if(a[i]==b[i])continue;
        int l=a[i].size(),r=-1;
        for (int j=0;j<a[i].size();j++)
        if(a[i][j]!=b[i][j])l=min(l,j),r=max(r,j);
        string s;
        for (int j=l;j<=r;j++)s+=a[i][j];
        for (int j=l;j<=r;j++)s+=b[i][j];
        int now=0;
        for (auto j:s){
            if(ch[now][j-'a']==0)ch[now][j-'a']=++tot;
            now=ch[now][j-'a'];
        }
        v[now].push_back(i);
        // cout<<now<<"!!!"<<tot<<" "<<i<<"\n";
        ls[i]=l,rs[i]=r;
    }
    for (int i=1;i<=q;i++){
        string aa,bb;
        cin>>aa>>bb;
        if(aa.size()!=bb.size())continue;
        int l=aa.size(),r=-1;
        for (int j=0;j<aa.size();j++)
        if(aa[j]!=bb[j])l=min(l,j),r=max(r,j);
        string s;
        for (int j=l;j<=r;j++)s+=aa[j];
        for (int j=l;j<=r;j++)s+=bb[j];
        int now=0,fl=1;
        for (auto j:s){
            if(ch[now][j-'a']==0){fl=0;break;}
            now=ch[now][j-'a'];
        }
        if(!fl)continue;
        vv[now].push_back(i);
        at[i]=aa;
        lp[i]=l,rp[i]=r;
    }
    int sum1=0,sum2=0;
    for (int i=1;i<=tot;i++)
    if(vv[i].size()&&v[i].size()){
        // cout<<i<<"~~~~~\n";
        // for (auto j:v[i])cout<<j<<" ";cout<<"\n";
        // for (auto j:vv[i])cout<<j<<" ";cout<<"\n";
        zong=0;
        // int rt1=0,rt2=0;
        for (auto j:vv[i]){
            int now=0;
            for (int k=rp[j]+1;k<at[j].size();k++){
                if(ch2[now][at[j][k]-'a']==0)ch2[now][at[j][k]-'a']=++tot1;
                now=ch2[now][at[j][k]-'a'];
            }
            st[j]=now;
            // cout<<j<<"!!!"<<now<<"\n";
        }
        dfs(0);
        sort(vv[i].begin(),vv[i].end(),cmp);
        for (auto j:vv[i]){
            int now=0;
            vt[now].push_back(dfn[st[j]]);vs[now].push_back({0,j});
            for (int k=lp[j]-1;k>=0;k--){
                if(ch3[now][at[j][k]-'a']==0)ch3[now][at[j][k]-'a']=++tot2;
                now=ch3[now][at[j][k]-'a'];
                vt[now].push_back(dfn[st[j]]);vs[now].push_back({0,j});
            }
            // cout<<dfn[st[j]]<<"%%\n";
        }
        for (auto j:v[i]){
            int now=0,fl=1;
            for (int k=rs[j]+1;k<a[j].size();k++){
                if(ch2[now][a[j][k]-'a']==0){fl=0;break;}
                now=ch2[now][a[j][k]-'a'];
            }
            if(!fl)continue;
            int ll=dfn[now],rr=dfn[now]+sz[now]-1;
            // cout<<ll<<"!@@@"<<rr<<"\n";
            now=0;
            for (int k=ls[j]-1;k>=0;k--){
                if(ch3[now][a[j][k]-'a']==0){fl=0;break;}
                now=ch3[now][a[j][k]-'a'];
            }
            if(!fl)continue;
            int pl=lower_bound(vt[now].begin(),vt[now].end(),ll)-vt[now].begin();
            int pr=upper_bound(vt[now].begin(),vt[now].end(),rr)-vt[now].begin();
            // cout<<pl<<"##"<<pr<<"\n";
            vs[now][pl].first++;
            if(pr<vs[now].size())vs[now][pr].first--;
        }
        for (int i=0;i<=tot2;i++){
            for (int j=1;j<vs[i].size();j++)
            vs[i][j].first+=vs[i][j-1].first;
            for (auto j:vs[i])
            ans[j.second]+=j.first;
        }
        for (int i=0;i<=tot1;i++){
            for (int j=0;j<26;j++)ch2[i][j]=0;
        }
        for (int i=0;i<=tot2;i++){
            vt[i].clear(),vs[i].clear();
            for (int j=0;j<26;j++)ch3[i][j]=0;
        }
        // sum1+=tot1,sum2+=tot2;
        tot1=tot2=0;
    }
    // cerr<<tot<<"@!!!"<<sum1<<" "<<sum2<<"\n";
    for (int i=1;i<=q;i++)
    cout<<ans[i]<<"\n";
}