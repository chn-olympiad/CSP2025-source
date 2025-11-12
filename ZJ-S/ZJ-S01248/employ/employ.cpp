#include<bits/stdc++.h>
using namespace std;
string a;
long long c[510],n,m,s,sjb;
bool f;
struct hh{
	int b,e;
	bool used[510];
};
queue<hh> q;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>a;
	a=' '+a;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]==0)sjb++;
		if(a[i]=='0')f=1;
	}
	if(m==n){
		if(f!=0||sjb!=0)cout<<0;
		else{
			s=1;
			for(int i=1;i<=n;i++)s*=i,s%=998244353;
			cout<<s;
		}
		return 0;
	}
	sort(c+1,c+1+n);
	hh hhh;
	hhh.b=0;
	hhh.e=0;
	for(int i=1;i<=n;i++)hhh.used[i]=0;
	q.push(hhh);
	while(!q.empty()){
		hh u=q.front();
		q.pop();
		if(u.b+u.e==n){
			if(u.b>=m)s++;
			continue;
		}
		for(int i=1;i<=n;i++){
			if(u.used[i]==1)continue;
			hh v=u;
			v.used[i]=1;
			if(u.e>=c[i])v.e++;
			else if(a[u.b+u.e+1]=='1')v.b++;
			else v.e++;
			q.push(v);
		}
	}
	cout<<s;
	return 0;
} 
