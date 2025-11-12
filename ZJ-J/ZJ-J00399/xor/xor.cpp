#include<bits/stdc++.h>
using namespace std;  
long long a[500005],n,k,t,s;
bool v[500005];
struct F{
	long long s,n;
}f[500005];
bool cmp(F c,F d)
{
	return c.s<d.s;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	for(long long i=1;i<=n;i++){
		t=a[i];
		f[i].n=i;
		f[i].s=-1;
		if(a[i]==k){
			f[i].s=1;
			continue;
		}
		for(long long j=i+1;j<=n;j++){
			t=t^a[j];
			if(t==k){
				f[i].s=j-i+1;
				break;
			}
		}
	}
	sort(f+1,f+1+n,cmp);
	for(long long i=1;i<=n;i++){
		if(f[i].s==-1) continue;
		else{
			bool B=1;
			for(long long j=f[i].n;j<f[i].n+f[i].s;j++){
				if(v[j]==1){
					B=0;
					break;
			}
			if(B==0) break;
			s++;           
			for(long long j=f[i].n;j<f[i].n+f[i].s;j++){
				v[j]=1;
			}
		}
	}
}
	cout<<s;
	return 0;
}