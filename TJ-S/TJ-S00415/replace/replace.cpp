#include<bits/stdc++.h>
using namespace std;
int n,q;
struct eve{
	string ori,las;
	int len;
}a[100022];
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;++i){
		string orid,cha;
		cin>>orid>>cha;
		a[i].las=cha;
		a[i].ori=orid;
		a[i].len=cha.length();
	}
	for(int i=1;i<=q;++i){
		int ans=0;
		string x,y;
		cin>>x>>y;
		int l=x.length(),r=y.length();
		if(l!=r){
			cout<<0;
			continue;}
		for(int j=1;j<=n;j++)
		{
			string l=x;
			int k=x.find(a[j].ori);
			l.replace(k,k+a[j].len,a[j].las);
			if(l==y)
				ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}
