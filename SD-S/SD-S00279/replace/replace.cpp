#include <bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-f;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
const int N=2e5+5;
int n,q;
int p[5000006][2];
bool pr[5000006],sf[5000006];
string s[N][2];
string t[2];
vector<int> pn[N][2];
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][0]>>s[i][1];
		for(int y=0;y<2;y++){
			pn[i][y].resize(s[i][y].size()+2);
			for(int x=2;x<=(int)s[i][y].size();x++){
				int j=pn[i][y][x-1];
				while(j>0&&s[i][y][x-1]!=s[i][y][j])
					j=pn[i][y][j];
				pn[i][y][x]=j+(s[i][y][x-1]==s[i][y][j]);
			}
		}
	}
	while(q--){
		cin>>t[0]>>t[1];
		int as=0,m=t[0].size();
		for(int k=1;k<=n;k++){
			for(int y=0;y<2;y++){
				if(m<(int)s[k][y].size())
					continue;
				p[0][y]=0;
				for(int x=1;x<=m;x++){
					int j=p[x-1][y];
					while(j>0&&t[y][x-1]!=s[k][y][j])
						j=pn[k][y][j];
					p[x][y]=j+(t[y][x-1]==s[k][y][j]);
				}
			}
			pr[0]=1,sf[m+1]=1;
			for(int i=1;i<=m;i++)
				pr[i]=pr[i-1]&&t[0][i-1]==t[1][i-1];
			for(int i=m;i>=1;i--)
				sf[i]=sf[i+1]&&t[0][i-1]==t[1][i-1];
			for(int i=1;i<=m;i++){
				if(p[i][0]!=(int)s[k][0].size()||p[i][0]!=p[i][1])continue;
				if(sf[i+1]&&pr[i-(int)s[k][0].size()])
					as++;
			}
		}
		cout<<as<<"\n";
	}
	return 0;
}
