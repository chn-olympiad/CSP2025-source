#include<bits/stdc++.h>
using namespace std;
long long a[514514],s[514514];
struct lr{
	int l,r;
}t[514514];
bool cmp(lr t1,lr t2)
{
	if(t1.r<t2.r) return 1;
	else if(t1.r==t2.r&&t1.l<t2.l) return 1;
	return 0;
}

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k,i,j,cnt,rnow,ans;
	cin>>n>>k;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	s[1]=a[1];
	for(i=1;i<=n;i++)
	{
		s[i]=s[i-1]^a[i];
	}
	
	cnt=1;
	s[0]=0;
	for(i=0;i<=n;i++)
		for(j=i+1;j<=n;j++)
			if((s[i]^s[j])==k){
				t[cnt].l=i+1;t[cnt].r=j;
				//cerr<<s[i]<<"^"<<s[j]<<"=="<<k<<endl;
				cnt++;
			}
			
	cnt--;
	sort(t+1,t+cnt+1,cmp);
	/*for(i=1;i<=cnt;i++)
	{
		cerr<<t[i].l<<" "<<t[i].r<<" "<<endl;
	}*/
	
	rnow=0;ans=0;
	for(i=1;i<=cnt;i++)
	{
		if(t[i].l>rnow)
		{
			rnow=t[i].r;
			ans++;
		}
		
	}
	cout<<ans<<endl;
}
