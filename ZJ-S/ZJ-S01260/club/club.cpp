#include<bits/stdc++.h>
using namespace std;
int k,n,a,b,c,d,e,f,x1[100005],x2[100005],x3[100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>k;
	for(int i=1;i<=k;i++){
		cin>>n;
		if(n==2)
		{
			cin>>a>>b>>c>>d>>e>>f;
			int a1=a+max(e,f);
			int a2=b+max(d,f);
			int a3=c+max(d,e);
			cout<<max(a1,max(a2,a3))<<endl;	
		}
		else if(n==4)
		{
			int ans=0;
			for(int i=1;i<=4;i++)
			{
				cin>>a>>b>>c;
				ans+=max(a,max(b,c));
			}
			cout<<ans<<endl;
		}
		else if(n=100000)
		{
			for(int i=1;i<=n;i++){
				cin>>x1[i]>>x2[i]>>x3[i];
			}
			sort(x1+1,x1+n+1);
			long long sum=0;
			for(int i=100000;i>=50001;i--) sum+=x1[i];
			cout<<sum<<endl;
		}
		else
		{
			int ans=0;
			for(int i=1;i<=n;i++)
			{
				cin>>a>>b>>c;
				ans+=max(a,max(b,c));
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}

