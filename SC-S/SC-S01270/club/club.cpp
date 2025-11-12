#include<bits/stdc++.h>
using namespace std;
int T,n;
int la[100010],lb[100010];
long long ans;//need chu shi hua
struct CLUB{
	int club1,club2,club3;
};
vector<CLUB>v;
bool cmp1(CLUB a,CLUB b){
	return a.club1>b.club1;
}
void dfs(int temp,long long sum,int c1n,int c2n,int c3n){
	if(temp==n){
		ans=max(ans,sum);
	}
	if(c1n<(n/2)){
		dfs(temp+1,sum+v[temp].club1,c1n+1,c2n,c3n);
	}
	if(c2n<(n/2)){
		dfs(temp+1,sum+v[temp].club2,c1n,c2n+1,c3n);
	}
	if(c3n<(n/2)){
		dfs(temp+1,sum+v[temp].club3,c1n,c2n,c3n+1);
	}
	
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	bool iftt0=1;
	for(int te_=0;te_<T;te_++){
		cin>>n;
		v.clear();
		ans=0;
		for(int i=0;i<n;i++){
			CLUB a;
			cin>>a.club1>>a.club2>>a.club3;
			if(a.club2!=0||a.club3!=0){
				iftt0=0;
			}
			v.push_back(a);
		}
		if(iftt0){
			sort(v.begin(),v.begin()+v.size(),cmp1);
			for(int j=0;j<n/2;j++){
				ans+=v[j].club1;
			}
			cout<<ans<<"\n";
			continue;
		}
		dfs(0,0,0,0,0);
		cout<<ans<<"\n";
	}
	return 0;
}