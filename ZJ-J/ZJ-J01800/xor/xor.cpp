#include<bits/stdc++.h>
using namespace std;
int n,x,k,f[500005],m,last,ans;
vector<int> v[1024*1024];
struct qj{
	int l,r;
};
vector<qj> a;
bool com(qj a,qj b){
	return a.r<b.r||a.r==b.r&&a.l<b.l;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>x;
		f[i]=f[i-1]^x;
		v[f[i]].push_back(i);
	}
	for(int i=0;i<=n-1;i++){
		x=f[i]^k;
		for(int j=0;j<v[x].size();j++){
			if(v[x][j]<i+1)continue;
			qj nqj;
			nqj.l=i+1;
			nqj.r=v[x][j];
			a.push_back(nqj);
			break;
		}
	}
	stable_sort(a.begin(),a.end(),com);
	for(int i=0;i<a.size();i++){
		if(a[i].l>last){
			ans++;
			last=a[i].r;
		}
	}
	cout<<ans;
	return 0;
}
