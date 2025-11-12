#include<bits/stdc++.h>
using namespace std;
queue<int>v;
int a[1000000],b[10000010];
long long t;

int main(){
	long long n,k;
	int l;
	int ans[100000010];
	int k2=k;
		for(int i=0;k2>0;i++){
			int ii=k%2;
			k2/=2;
			ans[i]=ii;
		}
	for(int i=1;i<=k;i++){
		cin>>l;
		v.push(l);
		if(l==k)	t++;v.pop();
		}
	while(!v.empty()){
		int m=v.front();
		v.pop();
		
		int f[100000010];
		for(int i=0;m>0;i++){
			int q=m%2;
			m/=2;
			f[i]=q;
		}
		int n2=v.front();	
		v.pop();
		int g[100000010];
		for(int i=0;m>0;i++){
			int q=n2%2;
			n2/=2;
			g[i]=q;
		}
		f.replace(0,f.lenth());
		g.replace(0,g.size());
		int o[100000010];
		for(int i=0;i<max(f.size(),g.size());i++){
			if(f[i]==g[i]){
				o[i]=1;
			}
			else	o[i]=0;
		}
		o.replace(o.begin(),o.end());
		if(o=ans)	memset(o,0);t++;
	}
	cout<<t;
}
