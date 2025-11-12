#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6;
long long a[maxn],n,k,sum[maxn],f[maxn];
vector<long long>qujian[maxn];
unordered_map<long long,bool>px;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		sum[i]=sum[i-1]^a[i];
		f[i]=-1;
		qujian[sum[i]].push_back(i);
	}
	f[0]=0;
	
	for(int i=1;i<=n;i++){
		if(px[sum[i]]==false){
			sort(qujian[sum[i]].begin(),qujian[sum[i]].end());
			px[sum[i]]=true;
		}
	}
	for(int i=1;i<=n;i++){
		if(i!=0){
			f[i]=max(f[i],f[i-1]);
		}
		int now=sum[i-1];
		int mb=k^now;
		auto xb=lower_bound(qujian[mb].begin(),qujian[mb].end(),i)-qujian[mb].begin();
		for(int j=xb;j<qujian[mb].size();j++){
			int next=qujian[mb][j];
			f[next]=max(f[next],f[i-1]+1);
		}
	}
	cout << f[n];
	return 0;
}