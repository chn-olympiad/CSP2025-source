#include<bits/stdc++.h>
using namespace std;
int n,m,c[505];
long long ans,num;
string s;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout)
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		scanf("%d",&c[i]);
		if(c[i]){
			num++;
		}
	}
	if(num<m){
		cout<<0;
	}
	else{
		ans=1;
		for(long long i=1;i<=num;i++){
			ans=(i*ans)%998244353;
		}
		cout<<ans;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
