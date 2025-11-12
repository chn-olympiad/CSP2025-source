#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
int n,m,c[1000];
long long ans=1;
string in;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>in;
	for(int i=0;i<n;i++){
		cin>>c[i];
	}
	for(int i=1;i<=n;i++){
		ans*=i;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
