#include<bits/stdc++.h>
using namespace std;//c=1^2;
int n,k,i,f[1000010],a[1000010],c[1000010],b[1000010],cd,j,t,h,w,mx,s,s1,s2;
struct no{
	int l,r,zh;
}u[1000010];
bool cmp(no t,no w){
	return t.zh<w.zh;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(i=1;i<=n;i++)
		cin>>f[i];
	a[1]=b[n]=f[1];
	for(i=2;i<=n;i++)
		a[i]=a[i-1]^f[i];
	for(cd=1;cd<=n;cd++)
		for(t=1;t<=n;t++)
		{
			h=a[cd]^a[t-1];
			if(h==k)
			{
				h=a[cd]^a[t-1];
				//cout<<a[cd]<<" "<<a[t]<<" "<<h<<"\n";
				j++,c[j]=min(cd,t),b[j]=max(cd,t);
			}	
		}
	for(i=1;i<=j;i++)
		u[i].l=c[i],u[i].r=b[i],u[i].zh=c[i]+b[i];
	//sort(u+1,u+1+j,cmp);
//	for(i=1;i<=j;i++)
//		cout<<u[i].l<<" "<<u[i].r<<"\n";
	n=j;
	for(i=1;i<=n;i++)
	{
		s=1;
		s1=u[i].l;s2=u[i].r;
		for(j=1;j<=n;j++)
		{
			if(j==i)continue;
			if(u[j].r<s1)
			{
				s++;
				s1=u[j].l;
			}
			if(u[j].l>s2)
			{
				s++;
				s2=u[j].r;
			}
		}
		mx=max(mx,s);
	}	
	cout<<mx;
}
