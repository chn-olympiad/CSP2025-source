//CSP-S
//SN-S00197
//张之奇
//西安市铁一中学

#include <bits/stdc++.h>
using namespace std;

const int maxn=2e5+5;
int n,Q;
string s[maxn][2];

int find(string a,string b){
	for (int i=0;i+b.size()-1<(int)a.size();i++){
		if (a[i]==b[0]){
			int flag=1;
			for (int j=1;j<b.size();j++){
				if (a[i+j]!=b[j])	flag=0;
			}
			if (flag==1)	return i;
		}
	}
	return -1;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>Q;
	for (int i=1;i<=n;i++)	cin>>s[i][0]>>s[i][1];
	while (Q--){
		int ans=0;
		string t,tt;
		cin>>t>>tt;
		for (int i=1;i<=n;i++){
			int res=find(t,s[i][0]);
			if (res==-1)	continue;
			string ttt=t;
			for (int j=res;j<=res+s[i][0].size()-1;j++)	ttt[j]=s[i][1][j-res];
			if (ttt==tt)	ans++;
		}
		cout<<ans<<"\n";
	}
	return 0;
}
