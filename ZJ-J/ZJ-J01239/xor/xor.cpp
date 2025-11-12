#include<bits/stdc++.h>
using namespace std;
long long n,k,cnt,ans,mx,dfw;
vector <long long> mp(21);
vector <long long> vis(21);
map<vector<long long>,long long> mp2;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	mp2[mp]=500001;
	while(k){
		vis[++cnt]=k%2;
		k/=2;
	}
	for(int i=1;i<=n;i++){
		long long a,sum=0;
		cin>>a;
		if(a==0) continue;
		while(a){
			mp[++sum]+=a%2;
			mp[sum]%=2;
			a/=2;
		}
		mx=max(mx,sum);
		vector<long long> fw(21);
		for(int j=1;j<=mx;j++){
			if(vis[j]!=mp[j]){
				fw[j]=1;
			}
			else fw[j]=0;
		}
		if(mp2[fw]&&mp2[fw]>=dfw){
			//cout<<i<<endl;
			ans++;
			dfw=i;
		}
		mp2[mp]=i;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdin);
	return 0;
}
