#include<bits/stdc++.h>
using namespace std;
int f[500005][25];
int n, k, a[500005], num[25], ans;
bool check(int l, int r){
	for(int i=0; i<=19; i++){
		if((f[r][i]-f[l-1][i])%2!=num[i]) return 0;
	}
	return 1;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0; i<=19; i++) num[i]=(k>>i)&1;
	for(int i=1; i<=n; i++) scanf("%d",&a[i]);
	for(int i=0; i<=19; i++){
		for(int j=1; j<=n; j++){
			if((a[j]>>i)&1) f[j][i]=f[j-1][i]+1;
			else f[j][i]=f[j-1][i];
		}
	}
	int lmin=1;
	for(int r=1; r<=n; r++){
		int l=r;
		while(l>=lmin){
			if(check(l,r)){
				ans++;
				lmin=r+1;  break;
			}
			else l--;
		}
	}
	cout<<ans;
	return 0;
}