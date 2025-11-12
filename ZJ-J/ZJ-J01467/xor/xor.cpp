#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int a[N];
unordered_map<int,int>mp;
int sum[N];
int main(){
	//finished this problem at 2025.11.1 9:00 
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int last=0;
	int id=1;
	int ans=0;
	while(id<=n){
		mp.clear();
		mp[0]=1;
		while(id<=n){
			sum[id-last]=(sum[id-last-1]^a[id]);
			if(mp[sum[id-last]^k]){
				ans++;
				last=id;
				id++;
				break;
			}
			mp[sum[id-last]]=1;
			id++;
		}
	}
	cout<<ans<<"\n";
	return 0;
}
