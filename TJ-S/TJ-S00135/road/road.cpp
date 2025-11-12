#include<bits/stdc++.h>
using namespace std;
long long n,m,p,b[15][10005],s[10005],cnt,ans;
struct node{
	long long u,v,w;
}a[1000005];
bool cmp(node A,node B){
	return A.w<B.w;
}
long long find_set(long long x){
	if(s[x]==x)return x;
	return s[x]=find_set(s[x]);
}
void Kruscal(){
	for(long long i=1;i<=n;i++)
		s[i]=i;
	sort(a+1,a+1+m,cmp);
	for(long long i=1;i<=m;i++)
	{
		long long x=find_set(a[i].u),y=find_set(a[i].v);
		if(x==y)continue;
		s[x]=y;
		cnt++;
		ans+=a[i].w;
		if(cnt==n-1)break;
	}
	cout<<ans<<endl;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>p;
	for(long long i=1;i<=m;i++)
		cin>>a[i].u>>a[i].v>>a[i].w;
	for(long long i=1;i<=p;i++)
	{
		cin>>b[i][0];
		for(long long j=1;j<=n;j++)
		{
			cin>>b[i][j];
			if(!b[i][j])b[i][0]=j;
		}
	}
	for(long long i=1;i<=p;i++)
	{
		for(long long j=1;j<=n;j++)
			if(j!=b[i][0])
			{
				a[++m].u=b[i][0];
				a[m].v=j;
				a[m].w=b[i][j];
			}
	}
	Kruscal();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
