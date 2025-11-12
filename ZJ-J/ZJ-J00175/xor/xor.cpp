#include<bits/stdc++.h>
#define starlight_yuran_ovo Eric998
using namespace std;
long long n,m,s,cnt,a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++){
			long long ans=0;
			for(int k=i;k<=j;k++)ans^=a[k];
			if(ans==m&&i>s)++cnt,s=j;
		}cout<<cnt;
	return 0;
}