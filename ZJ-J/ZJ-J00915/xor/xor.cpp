#include<bits/stdc++.h>
using namespace std;
long long a[500005];
long long x[500005];
int ans=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n;
	long long k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		x[i]=x[i-1]^a[i];
	}
	for(int l=1;l<=n;l++){
		for(int r=l;r<=n;r++){
			int f=x[l-1]^x[r];
			if(f==k){
				l=r+1;
				ans++;
			}
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
