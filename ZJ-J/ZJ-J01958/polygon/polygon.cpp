#include<bits/stdc++.h>
using namespace std;
int n,a[6000];
long long ans;
const long long p=998244353;
int max(int a,int b) {
	return a>b?a:b;
}
vector<int>tmp;
int idx;
long long s;
map <string,bool> m;
bool all1=true;
void dfs(vector<int> x,int nowmax,long long sum,int avaCnt) {
	if(avaCnt<3)return;
	if(avaCnt==3) {
		if(sum>nowmax*2) {
			ans++;
			if(ans>p)ans=ans%p;
		}
		return;
	}
	if(sum>nowmax*2) {
		ans++;
		if(ans>p)ans=ans%p;
	}
	for(int i=0; i<x.size(); i++) {
		if(x[i]==-1)continue;
		long long nsum=sum-x[i];
		int ttmp=x[i];
		x.erase(x.begin()+i);
		x.insert(x.begin()+i,-1);
		int newmax=0;
		string id="";
		for(int j=0; j<x.size(); j++) {
			if(x[j]!=-1)id=id+char(j-'0');
			if(x[j]>newmax and x[j]!=-1)newmax=x[j];
		}
		if(m.find(id)==m.end())
			dfs(x,newmax,nsum,avaCnt-1);
		m[id]=1;
		x.erase(x.begin()+i);
		x.insert(x.begin()+i,ttmp);
	}
	return;
}
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=0; i<n; i++) {
		scanf("%d",&a[i]);
		tmp.push_back(a[i]);
		s+=a[i];
		if(a[i]!=1)all1=false;
	}
	if(all1){
		long long sum=1;
		for(int i=n-1;i>0;i--){
			sum=(sum*(i%p))%p;
		}
		cout<<sum;
		return 0;
	}
	dfs(tmp,max(max(a[0],a[1]),a[2]),s,n);
	printf("%d",ans);
	return 0;
}