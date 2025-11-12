#include<bits/stdc++.h>
#define x first
#define y second
using namespace std;
typedef pair<int,int> PII;
typedef long long LL;
typedef unsigned long long ULL;
const ULL P=13331;
int n,q,m,num;
int tr[5000010][26],sz[5000010];
int ans[200010];
string l[400010],r[400010];
ULL s[200010];
pair<ULL,int> qr[6000010];
inline ULL geth(string &st)
{
    ULL s=0;for(char c:st)s=s*P+c;
    return s;
}
inline void clear()
{
    for(int i=0;i<=num;i++){
		sz[i]=0;
        for(int j=0;j<26;j++)tr[i][j]=0;
	}num=0;
}
inline void insert(string &st)
{
    int u=0;for(char c:st){
        int &p=tr[u][c-'a'];
        if(!p)p=++num;
        u=p;
    }sz[u]++;
}
inline int ask(string &st)
{
    int u=0,s=sz[u];for(char c:st){
        int p=tr[u][c-'a'];
        if(!p)break;
        s+=sz[u=p];
    }return s;
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
    int i,j,k;cin>>n>>q;
    for(i=1;i<=n;i++){
        string x,y;cin>>x>>y;
        if(x==y)continue;
        for(j=0;j<x.size();j++)
            if(x[j]==y[j])l[i]+=x[j];else break;

        for(k=x.size()-1;~k;k--)
            if(x[k]==y[k])r[i]+=x[k];else break;

        reverse(r[i].begin(),r[i].end());
        while(j<=k)s[i]=(s[i]*P+x[j])*P+y[j],j++;
        qr[++m]={s[i]*P+geth(l[i]),i};
    }for(i=n+1;i<=n+q;i++){
        string x,y;cin>>x>>y;
        if(x.size()!=y.size())continue;
        for(j=0;j<x.size();j++)
            if(x[j]==y[j])l[i]+=x[j];else break;

        for(k=x.size()-1;~k;k--)
            if(x[k]==y[k])r[i]+=x[k];else break;

        reverse(r[i].begin(),r[i].end());
        ULL s=0;
        while(j<=k)s=(s*P+x[j])*P+y[j],j++;
        ULL t=0,w=1;qr[++m]={s*P,i};
        for(j=l[i].size()-1;~j;j--){
            t+=w*l[i][j],w*=P;
            qr[++m]={s*P+t,i};
        }
    }sort(qr+1,qr+m+1);
    for(i=1;i<=m;i++){
		//cout<<qr[i].x<<' '<<qr[i].y<<'\n';
        if(qr[i].x!=qr[i-1].x)clear();
        if(qr[i].y<=n)insert(r[qr[i].y]);
        else ans[qr[i].y]+=ask(r[qr[i].y]);
    }for(i=1;i<=q;i++)cout<<ans[n+i]<<'\n';
}
