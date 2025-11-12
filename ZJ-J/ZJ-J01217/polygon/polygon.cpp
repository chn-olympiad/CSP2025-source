#include<bits/stdc++.h>
using namespace std;
int n,a[5010],ans;
long long s;
bool f;
struct hh{
	int ma,al,k;
};
queue<hh> q;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i!=1&&a[i]!=a[i-1])f=1;
	}
	if(f==0){
		s=1;
		for(int i=1;i<=n;i++)s*=2,s%=998244353;
		s=s+998244353-n-n*(n-1)/2;
		cout<<s%998244353;
		return 0;
	}
	sort(a+1,a+1+n);
	hh hhh;
	hhh.al=0,hhh.k=0,hhh.ma=0;
	q.push(hhh);
	while(!q.empty()){
		hh u=q.front();
		q.pop();
		if(u.ma*2<u.al)ans++;
		for(int i=u.k+1;i<=n;i++){
			hh h;
			h.ma=a[i];
			h.k=i;
			h.al=u.al+a[i];
			q.push(h);
		}
	}
	cout<<ans%998244353;
}
