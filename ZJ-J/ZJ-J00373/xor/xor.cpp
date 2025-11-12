#include<bits/stdc++.h>
using namespace std;
const int maxn=500005;
int n,m,ans,lst,a[maxn],b[maxn],sum;
int cnt[2000005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	cnt[0]++;
	for(int i=1;i<=n;i++){
		b[i]=b[i-1]^a[i];
		if(cnt[b[i]^m]){
			ans++;
			for(int j=lst;j<i;j++)cnt[b[j]]--;
			lst=i;
		}
		cnt[b[i]]++;
	}
	cout<<ans;
	return 0;
}
