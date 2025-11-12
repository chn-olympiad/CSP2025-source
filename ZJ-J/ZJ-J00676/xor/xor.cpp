#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long n,k,ans=0;
long long a[N];
int find(int start){
	map<int,int> mp;
	mp[0]++;
	long long sum=0;
	for(int i=start;i<=n;i++){
		sum=(sum^a[i]);
		long long cnt=(k^sum);
		if(mp[cnt]){
			ans++;
			return i;
		}
		mp[sum]++;
	}
	return 0;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	int s=1;
	while(true){
		s=find(s);
		if(s==0||s==n)break;
		s++;
	}
	cout<<ans;
	return 0;
}
