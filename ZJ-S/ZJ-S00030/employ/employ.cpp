#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	long long cnt=0,ans=1;
	int arr[10001];
	for(int i=1;i<=n;i++){
		cin>>arr[i];
		if(arr[i]) cnt++;
	}
	for(int i=1;i<=cnt;i++){
		ans*=i;
		ans%=998244353;
	}
	cout<<ans;
}                                                
