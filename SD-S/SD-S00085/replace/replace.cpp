#include <bits/stdc++.h>
using namespace std;

#define MAXN 200005
#define u64 unsigned long long
int n,q;
string ins[MAXN][2];
u64 a[MAXN][2];
const u64 P=131;
u64 b[5000005][2];
u64 p[MAXN];
int pos[MAXN][2];

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
//	freopen("replace.in","r",stdin);
//	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin >>n>>q;
	if (2000ll*n*q>5e8){
		while (q--) cout <<"0\n";	
		return 0;
	}
	p[0]=1;
	for (int i = 1;i <= MAXN-5;i ++) p[i]=p[i-1]*P;
	string s;
	bool flag=true;
	for (int i = 1;i <= n;i ++){
		cin >>s;
		ins[i][0]=s;
		int m=s.size();
		int cnt=0;
		for (int j = 0;j < m;j ++){
			a[i][0]+=p[j]*(s[j]-'a'+1);	
			if (s[j]=='b') ++cnt;
			else if (s[j]!='a') flag=false;
			if (cnt!=1) flag=false;
		}
		cin >>s;
		ins[i][1]=s;
		cnt=0;
		for (int j = 0; j < m;j ++){
			a[i][1]+=p[j]*(s[j]-'a'+1); 
			if (s[j]=='b') ++cnt;
			else if (s[j]!='a') flag=false;
			if (cnt!=1) flag=false;
		}
//		cout <<a[i][0]<<' '<<a[i][1]<<'\n';
	}
	string t;
	while (q--){
		cin >>s>>t;
		if (s.size()!=t.size()){
			cout <<"0\n";	
			continue;
		}
		int m=s.size();
		b[0][0]=s[0]-'a'+1;
		b[0][1]=t[0]-'a'+1;
		for (int i = 1;i < m;i ++) b[i][0]=b[i-1][0]+p[i]*(s[i]-'a'+1);
		for (int i = 1;i < m;i ++) b[i][1]=b[i-1][1]+p[i]*(t[i]-'a'+1);
//		cout <<b[m-1][0]<<' '<<b[m-1][1]<<'\n';
		int ans=0;
		for (int i = 1;i <= n;i ++){
			int len=ins[i][0].size(); 
			for (int j = 0;j+len-1<m;j ++){
				if (b[j+len-1][0]-(j>0?b[j-1][0]:0)==a[i][0]*p[j]){
					u64 af=(j>0?b[j-1][0]:0)+a[i][1]*p[j]+b[m-1][0]-b[j+len-1][0];
//					cout <<i<<' '<<j<<' '<<af<<'\n';
					if (af==b[m-1][1]){
						++ans;
						break; 
					}
				}
			}
		}
		cout <<ans<<'\n';
	}
	return 0;
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
*/
