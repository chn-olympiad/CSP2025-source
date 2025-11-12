#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
int n,k,fl,num;
int v[N],a[N],ans;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		fl=max(a[i],fl);
		if(a[i]==1) num++;
		a[i]=(a[i]^a[i-1]);
	}
	if(fl==k&&k==1)
	{
		cout<<num;
		return 0;
	}
	else if(fl==1&&k!=1)
	{
		cout<<0;
		return 0;
	}
	
	
	
	for(int l=1;l<=n;l++)
	{
		for(int i=1;i<=n-l+1;i++)
		{
			int s=i,e=i+l-1;
			int f=0;
			for(int q=s;q<=e;q++) if(v[q]==1){
				f=1;
				break;
			}
			if(f) continue;
			
			if(k==(a[e]^a[s-1]))
			{
				ans++;
				for(int q=s;q<=e;q++) v[q]=1;
			}
			
		}
	}
	
	cout<<ans;

	return 0;
}

