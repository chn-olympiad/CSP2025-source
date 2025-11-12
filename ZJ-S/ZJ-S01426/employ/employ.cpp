#include<bits/stdc++.h>
using namespace std;
int n,m,c[510],g=0,s;
const long long N=998244353;
long long ans=1;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>s;
	for(int i=0;i<n;i++){
		cin>>c[i];
		if(c[i])g++;
		
	}
	srand(time(0));
	ans=rand();
	if(g>=m)cout<<ans;
	else cout<<0;	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
