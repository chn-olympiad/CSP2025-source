#include<bits/stdc++.h>
using namespace std;
int a[2010],b[2010],c[2010],aa[2010],v[2010],oo[2010];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	long long t,n,ma,s1=0,s2=0,s3=0,cnt=0,o=0,p=0,x,w,g,d,f=0,k=0;
	cin>>t;
	while(t--)
	{
		cin>>n;
		s1=0,s2=0,s3=0,cnt=0,o=0,p=0,w=0,g=0,d=0,k=0;
		memset(v,0,sizeof(v));
		memset(oo,0,sizeof(oo));
		for(int i=1;i<=n;i++)
		{
			cin>>a[i]>>b[i]>>c[i];
			if(b[i]==0)o++;
			if(c[i]==0)p++;
			if(max(a[i],max(b[i],c[i]))==a[i])x=1,aa[i]=a[i];
			else if(max(a[i],max(b[i],c[i]))==b[i])x=2,aa[i]=b[i];
			else x=3,aa[i]=c[i];
		}
		if(o==n&&p==n)
		{
			sort(aa+1,aa+n+1,cmp);
			for(int i=1;i<=n/2;i++)cnt+=aa[i];
			cout<<cnt<<"\n";
			continue;
		}
		if(p==n)
		{
			for(int i=1;i<=n;i++)k++,oo[k]=a[i];
			for(int i=1;i<=n;i++)k++,oo[k]=b[i];
			sort(oo+1,oo+n+n+1,cmp);
			for(int i=1;i<=n/2;i++)
			{
				cnt+=oo[i];
			}
			cout<<cnt<<"\n";
			continue;
		}
		for(int i=1;i<=n;i++)
		{
			f=0;
			if(aa[i]==a[i]&&s1<=n/2)s1++,w+=a[i];
			if(aa[i]==a[i]&&s1>n/2)
			{
				w=0,s1=0;
				sort(aa+1,aa+n+1,cmp);
				sort(a+1,a+n+1,cmp);
				for(int j=1;j<=n;j++)
				{
					if(aa[j]==a[j])s1++,cnt+=aa[j],v[aa[j]]=1;
					if(s1==n/2)
					{
						f=1;
						break;
					}
				}
			}
			if(aa[i]==b[i]&&s2<=n/2)s2++,g+=b[i];
			if(aa[i]==b[i]&&s2>n/2)
			{
				g=0,s2=0;
				sort(aa+1,aa+n+1,cmp);
				sort(b+1,b+n+1,cmp);
				for(int j=1;j<=n;j++)
				{
					if(aa[j]==b[j])s2++,cnt+=aa[j],v[aa[j]]=1;
					if(s2==n/2)
					{
						f=2;
						break;
					}
				}
			}
			if(aa[i]==c[i]&&s3<=n/2)s3++,d+=c[i];
			if(aa[i]==c[i]&&s3>n/2)
			{
				d=0,s3=0;
				sort(aa+1,aa+n+1,cmp);
				sort(c+1,c+n+1,cmp);
				for(int j=1;j<=n;j++)
				{
					if(aa[j]==c[j])s3++,cnt+=aa[j],v[aa[j]]=1;
					if(s3==n/2)
					{
						f=3;
						break;
					}
				}
			}
			if(f==1||f==2||f==3)break;
		}
		if(f==1)
		{
			for(int i=1;i<=n;i++)
			{
				if(!v[aa[i]])
				{
					if(b[i]>c[i])
					{
						if(s2+1<=n/2)cnt+=b[i];
						else cnt+=c[i];
					}
					else
					{
						if(s3+1<=n/2)cnt+=c[i];
						else cnt+=b[i];
					}
				}
			}
		}
		if(f==2)
		{
			for(int i=1;i<=n;i++)
			{
				if(!v[aa[i]])
				{
					if(a[i]>c[i])
					{
						if(s1+1<=n/2)cnt+=a[i];
						else cnt+=c[i];
					}
					else
					{
						if(s3+1<=n/2)cnt+=c[i];
						else cnt+=a[i];
					}
				}
			}
		}
		if(f==3)
		{
			for(int i=1;i<=n;i++)
			{
				if(!v[aa[i]])
				{
					if(a[i]>b[i])
					{
						if(s1+1<=n/2)cnt+=a[i];
						else cnt+=b[i];
					}
					else
					{
						if(s2+1<=n/2)cnt+=b[i];
						else cnt+=a[i];
					}
				}
			}
		}
		cnt=cnt+w+g+d;
		cout<<cnt<<"\n";
	}
	return 0;
}