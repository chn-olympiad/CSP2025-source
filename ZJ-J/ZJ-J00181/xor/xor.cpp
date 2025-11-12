#include<bits/stdc++.h>
using namespace std;
//#define int long long
#define PQ priority_queue
const int N=5e5+5;
int a[N],cnt[5];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1)cnt[1]++;
		else if(!a[i])cnt[0]++;
	}
	int ans=0;
	if(!k)
		for(int i=2;i<=n;i++)
			if(a[i]==1&&a[i-1]==1){
				ans++;
				a[i]=0;
			}
	if(k==1||!k)cout<<cnt[k]+ans;
	return 0;
}
