#include<bits/stdc++.h>
using namespace std;
int n,m,m3,a[501],ans;
bool vis[501];
string s;
void emp(int x,int y)
{
	int xx;
	for(int i=1;i<=n;i++)
	{
		if(vis[i]) continue;
//		cout<<"x:"<<x<<" i:"<<i;
		if(x==1)
		{
			if(s[n-x]=='0'||y>=a[i]) 
			{
				if(m+1==n-y) {ans++;/*cout<<"[++]"<<endl;*/}
			}
			else if(m==n-y) {ans++;/*cout<<"[++]"<<endl;*/}
		}
		else
		{
			vis[i]=1;
//			cout<<endl;
			if(s[n-x]=='0'||y>=a[i]) emp(x-1,y+1);
			else emp(x-1,y);
			vis[i]=0;
		}
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=0;i<s.length();i++) if(s[i]=='1') m3++;
	for(int i=1;i<=n;i++) cin>>a[i];
	emp(n,0);
	cout<<ans;
	return 0;
	fclose(stdin);fclose(stdout);
}
