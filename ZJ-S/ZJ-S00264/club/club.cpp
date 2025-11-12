#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll _=2e5+5;
ll N,n,x,y,z,t,k,s,a[_],b[_],c[3],d[_],i;
void P(){
	cin>>n;s=c[0]=c[1]=c[2]=0;
	for(i=0;i<n;i++){
		cin>>x>>y>>z;t=max(max(x,y),z);
		if(t==x)a[i]=0,b[i]=min(t-y,t-z);
		else if(t==y)a[i]=1,b[i]=min(t-x,t-z);
		else a[i]=2,b[i]=min(t-x,t-y);
		s+=t;c[a[i]]++;
	}
	t=-1;if(c[0]>n/2)t=0;if(c[1]>n/2)t=1;if(c[2]>n/2)t=2;
	if(~t){
		for(k=i=0;i<n;i++)if(a[i]==t)d[k++]=b[i];
		sort(d,d+k);
		for(i=0;i<k-n/2;i++)s-=d[i];
	}
	cout<<s<<'\n';
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>N;while(N--)P();
}