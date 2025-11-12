#include <queue>
#include <cstdio>
#include <iostream>
using namespace std;
long long n,m,k,t,b1,b2,b3,d,sum,sum1,e1,e2,f[2000020];
priority_queue<pair<long long,pair<long long,long long> >,vector<pair<long long,pair<long long,long long> > >,greater<pair<long long,pair<long long,long long> > > >a;
pair<long long,pair<long long,long long> >b[2000010],c[2000010],r;
long long fi(int x)
{
//	cout<<x;
	if(f[x]==x) return x;
	return f[x]=fi(f[x]);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=m;i++) scanf("%lld%lld%lld",&b1,&b2,&b3),a.push({b3,{b1,b2}});
	for(int i=1;i<=n;i++) f[i]=i;
	while(t<n-1)
	{
		r=a.top(),a.pop();
		if(fi(r.second.first)==fi(r.second.second)) continue;
		f[fi(r.second.first)]=fi(r.second.second);
		b[++t]=r;
		sum+=r.first;
	}
//	for(int i=1;i<=t;i++) cout<<b[i].first<<" "<<b[i].second.first<<" "<<b[i].second.second<<endl;
//	cout<<"-----------------\n";
	while(!a.empty()) a.pop();
	for(int i=1;i<=k;i++)
	{
		scanf("%lld",&b1),e1+=b1,sum1=e1;
		for(int j=1;j<=t;j++) a.push(b[j]),c[j]=b[j];
		t=0;
		for(int j=1;j<=n;j++) scanf("%lld",&b1),a.push({b1,{n+i,j}});
		for(int j=1;j<=n+i;j++) f[j]=j;
		while(t<n+d)
		{
			r=a.top(),a.pop();
			if(fi(r.second.first)==fi(r.second.second)) continue;
			f[fi(r.second.first)]=fi(r.second.second);
//			for(int j=1;j<=n;j++) cout<<f[j]<<" ";
//			cout<<endl;
			b[++t]=r;
			sum1+=r.first;
//	cout<<t;
		}
		while(!a.empty()) a.pop();
//		cout<<2;
//		cout<<sum1<<" "<<sum<<endl;
		if(sum1>sum)
		{
			for(int j=1;j<=t;j++) b[i]=c[i];
			d++,e2=e1,t--;
		}
		else sum=sum1,e1=e2;
//		for(int j=1;j<=t;j++) cout<<b[j].first<<" "<<b[j].second.first<<" "<<b[j].second.second<<endl;
//		cout<<"-------------------\n";
	}
	printf("%lld",sum);
	return 0;
}
