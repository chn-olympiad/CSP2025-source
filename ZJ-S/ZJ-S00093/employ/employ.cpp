#include<bits/stdc++.h>
using namespace std;
#define IO(fn) freopen(fn".in","r",stdin);freopen(fn".out","w",stdout);
int n,m;
int p[1234],c[1234];
bool nd[1234];
int main(){IO("employ");
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		char c;
		cin>>c;
		nd[i]=(c=='1');
	}
	for(int i=1;i<=n;i++)p[i]=i;
	for(int i=1;i<=n;i++)cin>>c[i];
	int ans=0,fail=0,tmp=0;
	do{
		tmp=0;
		for(int i=1;i<=n;i++){
			if(!nd[i])fail++;
			else fail=0;
			if(fail<c[p[i]])tmp++;
		}
		if(tmp>=m)ans++;
	}while(next_permutation(p+1,p+n+1));
	cout<<ans+1<<'\n';
}
