#include <bits/stdc++.h>
using namespace std;
int n,m,c[510],op[510],sum[510];
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++) cin>>c[i];
	for(int i=1;i<=n;i++) op[i]=i;
//	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+(s[i-1]=='0');
//	for(int i=1;i<=n;i++) cout<<sum[i]<<" ";
//	cout<<"\n";
	int ans=0;
	do{
//		for(int i=1;i<=n;i++) cout<<op[i]<<" ";
//		cout<<"\n";
		int suml=0,cnt=0;
		for(int i=1;i<=n;i++){
			if(s[i-1]=='0'||cnt>=c[op[i]]) cnt++;
			else suml++;
//			else cnt++;
		}
		if(suml>=m){
			ans++;
		}
	}while(next_permutation(op+1,op+n+1));
	cout<<ans;
	return 0;
}
