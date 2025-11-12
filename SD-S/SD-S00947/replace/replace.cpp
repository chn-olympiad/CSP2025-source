#include<bits/stdc++.h>
using namespace std;
#define int long long
#define R read()
inline int read(){
	int re=0;
	char ch;
	while (1){
		ch=getchar();
		if ('0'<=ch and ch<='9')	break;
	}
	while (1){
		re=re*10+ch-'0';
		ch=getchar();
		if ('0'>ch or ch>'9')	return re;
	}
}
const int N=27,M=1e6+5;
int n,q;
int cnt;
string a,b;
vector<string> l1[N][N],l2[N][N];
vector<int >sz[N][N];
vector<int >v1[N][N][N],v2[N][N][N];
int vv1[N],vv2[N];
int oo1[M][N],oo2[M][N];
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	n=read(),q=read();
	for (int i=1;i<=n;i++){
		string x,y;
		cin>>x>>y;
		int siz=x.size()-1;
		l1[x[0]-'a'][y[0]-'a'].push_back(x);
		l2[x[0]-'a'][y[0]-'a'].push_back(y);
		sz[x[0]-'a'][y[0]-'a'].push_back(siz);
		for (int i=0;i<=siz;i++)
			vv1[x[i]-'a']++,vv2[y[i]-'a']++;
		for (int i=0;i<N;i++)
			v1[x[0]-'a'][y[0]-'a'][i].push_back(vv1[i]),v2[x[0]-'a'][y[0]-'a'][i].push_back(vv2[i]),vv1[i]=vv2[i]=0;
	}
	while (q--){
		int l=1145141,r=-919810;
		int ans=0;
		cin>>a>>b;
		int s=a.size();
		a='0'+a;
		b='0'+b;
		if (a.size()!=b.size()){
			cout<<0<<"\n";
			continue;
		}
		for (int i=1;i<=s;i++){
			for (int j=0;j<N;j++)	oo1[i][j]=oo1[i][j-1],oo2[i][j]=oo2[i][j-1];
			oo1[i][a[i]-'a']++;
			oo2[i][b[i]-'a']++;
			if (a[i]!=b[i])	l=min(l,i),r=max(r,i);
		}	
		for (int i=1;i<=l;i++)
			for (int j=0;j<(int)sz[a[i]-'0'][b[i]-'0'].size();j++)
				if (sz[a[i]-'0'][b[i]-'0'][j]+1+i>=r and sz[a[i]-'0'][b[i]-'0'][j]+1+i<=s){
					bool flag=0;
					for (int k=0;k<26;k++)	
						if (oo1[sz[a[i]-'0'][b[i]-'0'][j]+i][j]-oo1[i-1][k]!=v1[a[i]-'0'][b[i]-'0'][j][k] or oo2[sz[a[i]-'0'][b[i]-'0'][j]+l][i]-oo2[i-1][j]!=v2[a[i]-'0'][b[i]-'0'][j][k]){
							flag=1;
							break;
						}
					if (flag==1)	continue;
					for (int k=0;k<=sz[a[i]-'0'][b[i]-'0'][j];k++)
						if (l1[a[i]-'0'][b[i]-'0'][j][k]==a[k+1+l] and l2[a[i]-'0'][b[i]-'0'][j][k]==b[k+1+l]){
							flag=1;
							break;
						}
					if (flag==1)	continue;
					ans++;
				}
		for (int j=1;j<=s;j++)
			for (int i=0;i<N;i++)	oo1[j][i]=oo2[j][i]=0;
		cout<<ans<<"\n";
	}
}

