#include<bits/stdc++.h>
using namespace std;
bool fa=true,fb=true;
int n,nm,ans,j,k,a[500002],sum[500002],x;
bool vis[500002];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{	cin>>a[i];
		if(a[i]!=1) fa=false;
		if(a[i]>1) fb=false;
		if(a[i]==1) nm++;
		sum[i]=sum[i-1]^a[i];}
	if(k==0&&fa==true){
		cout<<n/2;
	}
	else if(k==0&&fb==true){
		cout<<nm/2;
	}
	else if(k==1&&fb==true){
		cout<<nm;
	}
	else{
		for(int i=1;i<=n;i++)
		if(a[i]==k){
			ans++;
			vis[i]=true;
		}
		for(int le=2;le<=n;le++)
		for(int i=1;i<=n-le+1;i++)
		{	j=i+le-1;
		if(i!=1){
			x=sum[i-1]^sum[j];
		}
		else {x=sum[j];
		}
			bool f=true;
			for(int k=i;k<=j;k++)
			if(vis[k]==true) {
				f=false;
				break;
			}
			if(f==false) continue;
			if(f&&x==k)
			{
				ans++;
				for(int k=i;k<=j;k++)
				vis[k]=true;	
			}	
		}
		cout<<ans;
	}
	return 0;
}
