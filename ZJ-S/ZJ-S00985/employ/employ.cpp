#include<bits/stdc++.h>
using namespace std;
int n,m,c[505],a[505],ans;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	s=' '+s;
	for(int i=1;i<=n;i++)cin>>c[i],a[i]=i;
	do{
		int sum=0;
		for(int i=1;i<=n;i++){
			if(s[i]=='0'||sum>=c[a[i]])sum++;
			if(n-sum<m)break;
		}
		if(n-sum>=m)ans++;
	}while(next_permutation(a+1,a+n+1));
	cout<<ans;
	return 0;
}