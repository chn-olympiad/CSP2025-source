#include<bits/stdc++.h>
using namespace std; //60pts
int love[4][1006]{0},n,T; 
int ans[702][702][702];
int dfs(int x,int y,int z,int a,int b,int c,int n){
	if(a>(n/2)||b>(n/2)||c>(n/2))
		return INT_MIN;
	if(a+b+c==n)
		return x+y+z;
	if(a+b+c>n)
		return INT_MIN;
	if(ans[a][b][c])
		return ans[a][b][c];
	int o=dfs(x+love[1][a+b+c+1],y,z,a+1,b,c,n);
	int p=dfs(x,y+love[2][a+b+c+1],z,a,b+1,c,n);
	int q=dfs(x,y,z+love[3][a+b+c+1],a,b,c+1,n); 
	ans[a+1][b][c]=o;
	ans[a][b+1][c]=p;
	ans[a][b][c+1]=q;
	return max(max(o,p),q);
//	return max(max(dfs(x+love[a+b+c+1][1],y,z,a+1,b,c),dfs(x,y+love[a+b+c+1][2],z,a,b+1,c)),dfs(x,y,z+love[a+b+c+1][3],a,b,c+1));
}
int dfs2(int x,int y,int a,int b,int n){
	if(a>(n/2)||b>(n/2))
		return INT_MIN;
	if(a+b==n)
		return x+y;
	if(a+b>n)
		return INT_MIN;
	if(ans[a][b][0])
		return ans[a][b][0];
	int o=dfs2(x+love[1][a+b+1],y,a+1,b,n);
	int p=dfs2(x,y+love[2][a+b+1],a,b+1,n); 
	ans[a+1][b][0]=o;
	ans[a][b+1][0]=p;
	return max(o,p);
//	return max(max(dfs(x+love[a+b+c+1][1],y,z,a+1,b,c),dfs(x,y+love[a+b+c+1][2],z,a,b+1,c)),dfs(x,y,z+love[a+b+c+1][3],a,b,c+1));
}
int main(){ 
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	
	while(T--){
		cin>>n;
		bool flag=0,vis=0;int ans=0;
		for(int i=1;i<=n;i++){
			cin>>love[1][i]>>love[2][i]>>love[3][i];
			if(love[3][i]!=0)
				flag=1;
			if(love[2][i]!=0)
				vis=1;
		}
		if(flag==0&&vis==0){
			 sort(love[1]+1,love[1]+n+1);
			 for(int i=n;i>n/2;i--)
			 	ans+=love[1][i];
			cout<<ans;
			continue;
		}
		if(flag==0&&vis!=0){
			ans=dfs2(0,0,0,0,n);
			cout<<ans<<endl;
			continue;
		}
		ans=dfs(0,0,0,0,0,0,n);
		cout<<ans<<endl; 
	}
	return 0;
}
