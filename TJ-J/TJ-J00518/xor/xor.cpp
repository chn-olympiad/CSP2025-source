#include<bits/stdc++.h>
using namespace std;
int n,m,ma=0,a[110];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ma=max(ma,a[i]);
	}
	cout<<ma;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
