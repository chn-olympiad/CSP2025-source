#include<bits/stdc++.h>
#include<vector>
#include<map>
using namespace std;
map<int,int> b;
map<vector<int>,int> p;
vector<int> v_1;
int m,ans,a[5010];
bool pd(vector<int> v){
	int sum=0,ma=0;
	sort(v.begin()+1,v.end());
	if(p[v]==1){
		return 0;
	}else{
		p[v]=1;
		for(int i=0;i<v.size();i++){
			sum+=v[i];
			ma=max(ma,v[i]);
		}
		if(sum>2*ma){
			return 1;
		}else{
			return 0;
		}
	}
}
void dfs(vector<int> v,int m){
	if(v.size()>=m){
		if(pd(v)){
			ans++;
			ans%=998244353;
		}
		return;
	}
	for(int i=1;i<=m;i++){
		if(b[i]==0){
			b[i]=1;
			v.push_back(a[i]);
			dfs(v,m);
			v.pop_back();
			b[i]=0;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	for(int i=3;i<=m;i++){
		dfs(v_1,i);
	}
	printf("%d",ans);
	return 0;
}