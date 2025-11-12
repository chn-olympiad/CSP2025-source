//when the n gets 5000,all the a get 5000,
//output:844461548
//Process exited after 373.1 seconds with return value 0
#include<bits/stdc++.h>
//#define int long long
using namespace std;
const int N=5e3+5;
const int mod=998244353;
int n,ans;
int sum;
int a[N];
int t[N*N];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		for(int j=sum;j>=1;j--)
			t[j+a[i-1]]=(1ll*t[j+a[i-1]]+t[j])%mod;
		sum+=a[i-1];
		t[a[i-1]]++;
		t[a[i-1]]%mod;
		for(int j=a[i]+1;j<=sum;j++)
			ans=(1ll*ans+t[j])%mod;
		cout<<i<<'\n';
	}
	cout<<ans;
	return 0;
}
/*
梨花飘落在你窗前，

画中伊人在闺中怨，

谁把思念轻描淡写，

只想留住时间为你穿越。  
 
































我不问， 

弱水三千几人能为我怨， 

今生亏欠我愿等来生再还。
*/
