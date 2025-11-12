#include<bits/stdc++.h>
using namespace std;
int n;
const int N=1e5+10;
int arr[N][4];
int dfs(int cl,int rs,int s1,int s2,int s3)
{
	if(rs>n)
		return 0;
	if(s1>n/2||s2>n/2||s3>n/2)
		return 0;
	return arr[rs][cl]+max(dfs(1,rs+1,s1+1,s2,s3),max(dfs(2,rs+1,s1,s2+1,s3),dfs(3,rs+1,s1,s2,s3+1)));
		
}
int main(){
	freopen("club4.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int a=1;a<=n;a++)
			for(int b=1;b<=3;b++)
				cin>>arr[a][b];
		int ans=max(dfs(1,1,1,0,0),max(dfs(2,1,0,1,0),dfs(3,1,0,0,1)));
		cout<<ans<<endl;
	}	
	
	
	
	
	
	
	
	

	
	return 0;
} 
