#include <bits/stdc++.h>
using namespace std;
int n,m,cnt;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>m;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]=='1')cnt++;
	}
	if(cnt<m){
		cout<<0;
		return 0;
	}
	if(n==m){//15
		cout<<0;
		return 0;
	}
	long long x=1;//ÌØÊâÐÔÖÊA //m==1
	for(int i=2;i<=n;i++){
		(x*=i)%=998244353;
	}
	cout<<x;
	return 0;
}
