#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;
int n,k;
int a[500010];
int sum[500010];
vector<PII> v;
vector<int> v2;
int ans=0;
bool cmp(PII a,PII b){
	return a.second<b.second;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.our","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		sum[i]=(sum[i-1]^a[i]);
	}
	for(int i=0;i<n;i++){
		for(int j=i+1;j<=n;j++){
			if((sum[i]^sum[j])==k){
				v.push_back({i+1,j});
			}
		}
	}
	sort(v.begin(),v.end(),&cmp);
	for(int i=0;i<v.size();i++){
		v2.push_back(v[i].first);
	}
	int pre=0;
	for(int i=0;i<v.size();i++){
		auto pos=upper_bound(v2.begin(),v2.end(),pre);
		if(pos==v2.end()) break;
		else{
			pre=v[(pos-v2.begin())].second;
			ans++;
		}
	}
	printf("%d",ans);
	return 0;
}