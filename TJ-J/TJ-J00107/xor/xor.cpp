#include<bits/stdc++.h>
using namespace std;
int main(){
//	freopen("xor.in","r",stdin);
//	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	vector<int> a(n+1);
	for(int i=1;i<=n;i++){
		int m;
		cin>>m;
		a[i]=a[i-1]^m;
	}
	int ans=0,id=0;
	for(int i=1;i<=n;i++){
		if((a[i]^a[id])==k){
			ans++;
			id=i;
			cout<<a[i]<<' ';
		}
	}
	cout<<ans;
//	fclose(stdin);
//	fclose(stdout);
	return 0;
} 
