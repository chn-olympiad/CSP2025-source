#include<bits/stdc++.h>
using namespace std;
const int N=500005;
int n,c[N],k;
bool cnt[N];
long long ans;
bool find(int x){
	for(int i=x;i<=n;i++){
		if(cnt[i]==1)return 0;
	}
	return 1;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		int a;
		cin>>a;
		c[i]=c[i-1]^a;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int x=c[i-1]^c[j];
			if(x==k&&find(i)){
				ans++;
				cnt[i]=1;
				cnt[j]=1;
			}
		}
	}
	cout<<ans;
	return 0;
}
