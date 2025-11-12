#include<bits/stdc++.h>
#define pib pair<int,bool>
#define fi first
#define se second
using namespace std;
const int N = 5e5+10;
map<int,int> mp;
int n,a[N],sum[N],k,last,x,cnt;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin >> n >> k;
	for(int i = 1;i <= n;i ++){
		cin >> a[i];
	}
	for(int i = 1;i <= n;i ++){
		sum[i]=sum[i-1]^a[i];
		if(mp[k^sum[i]^last]>x || (k^sum[i]^last)==0){
			last=sum[i],x=i,cnt++;
		}
		mp[sum[i]^last]=i;
	}
	cout << cnt;
	return 0;
}