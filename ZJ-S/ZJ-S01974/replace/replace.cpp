#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,q;
const int N=2e5+10;
string s[N][2];
int ans=0;
void fun(string now,int x,string tar,int begin){
	for (int i=0; i<s[x][0].size(); i++){
		now[begin+i]=s[x][1][i];
	}
	if (now==tar){
		ans++;
	}
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	for (int i=1; i<=n; i++){
		cin>>s[i][0]>>s[i][1];
	}
	for (int i=1; i<=q; i++){
		string a1,t1;
		cin>>a1>>t1;
		ans=0;
		for (int j=1; j<=n; j++){
			int pos=a1.find(s[j][0]);
			if (pos>=0){
				fun(a1,j,t1,pos);
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}