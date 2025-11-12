#include<bits/stdc++.h>
using namespace std;
long long n,m,ans,a[505],num,day[505];
bool con[505];
string s;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	s=" "+s;
	for(long long i=1;i<s.size();i++){
		if(s[i]=='1'){
			num++;
			day[num]=i;
		}
	}
	for(int i=1;i<=n;i++) cin>>a[i];
	cout<<pow(2,num-1);
	return 0;
}
