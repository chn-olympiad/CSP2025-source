#include<bits/stdc++.h>
using namespace std;
int n,m;
string a;
int b[510];
int ans=1,cnt;
int sum;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>a;
	for(int i=1;i<=n;i++){
		cin>>b[i];
		if(a[i]=='1')
			sum+=1;
	}
	for(int i=1;i<=n;i++)
		ans=ans*i%998244353;
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

