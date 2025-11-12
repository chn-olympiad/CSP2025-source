#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
const int N=5e5+10;
int n,k,a[N],b[N],c[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for (int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=b[i-1]^a[i];
	}
	memset(c,0x3f,sizeof(c));
	for (int l=n;l>=1;l--){
		for (int i=1;i+l-1<=n;i++){
			int j=i+l-1;
			if((b[j]^b[i-1])==k){
				c[i]=j;
			}
		}
	}
	int ans=0;
	for (int i=1;i<=n;i++){
		int cnt=0;
		for (int j=i;j<=n;j++){
			if(c[j]!=0x3f3f3f3f){
				j=c[j];
				cnt++;
			}
		}
		ans=max(ans,cnt);
	}
	cout<<ans;
	return 0;
}
