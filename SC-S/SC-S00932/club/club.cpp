#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n;
array<array<int,4>,N>a;
array<vector<int>,4>b;
vector<int>tmp;
inline void work(){
	cin>>n;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=3;++j)cin>>a[i][j];
		a[i][0]=-1;
	}
	int res=0;
	for(int i=1;i<=n;++i){
		int j=0;
		for(int k=1;k<=3;++k)if(a[i][k]>a[i][j])j=k;
		b[j].push_back(i),res+=a[i][j];
	}
	int j=0;
	for(int k=1;k<=3;++k)if(b[k].size()>b[j].size())j=k;
	if(b[j].size()>n/2){
		for(int k:b[j]){
			int p=0;
			for(int q=1;q<=3;++q)if(q!=j){
				if(a[k][q]>a[k][p])p=q;
			}
			tmp.push_back(a[k][j]-a[k][p]);
		}
		sort(tmp.begin(),tmp.end());
		int f=b[j].size()-n/2;
		for(int i=0;i<f;++i)res-=tmp[i];
		tmp.clear();
	}
	for(int k=1;k<=3;++k)b[k].clear();
	cout<<res<<'\n';
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	int T;cin>>T;
	while(T--)work();
	return 0;
}