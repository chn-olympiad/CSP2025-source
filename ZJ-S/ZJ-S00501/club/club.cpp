#include<bits/stdc++.h>
using namespace std;
int const N=1e6+10;
int a[N][5],b[N];
int num1=0,num2=0,num3=0,n,ans=0;
void dfs(int now,int val,int x,int y,int z){
	//cout<<x<<" "<<y<<" "<<z<<endl;
	if(x>n/2)return;
	if(y>n/2)return;
	if(z>n/2)return;
	if(now==n)ans=max(ans,val);
	for(int i=1;i<=3;i++){
		if(i==1)num1++;
		if(i==2)num2++;
		if(i==3)num3++;
		dfs(now+1,val+a[now+1][i],num1,num2,num3);
		if(i==1)num1--;
		if(i==2)num2--;
		if(i==3)num3--;
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int f=0;
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(a[i][2]!=0||a[i][3]!=0)f=1;
		}
		if(f==0){
			for(int i=1;i<=n;i++)b[i]=a[i][1];
			sort(b+1,b+n+1);
			for(int i=n;i>n/2;i--)ans+=b[i];
			cout<<ans<<endl;
		}
		else{
			dfs(0,0,0,0,0);
			cout<<ans<<endl;
		}
	}
}
