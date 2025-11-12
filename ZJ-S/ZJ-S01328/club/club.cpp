#include<bits/stdc++.h>
using namespace std;
int T,n,a,b,c,ans;
int qf[(int)(1e5+10)];
struct node{
	int x,y,z;
}f[(int)(1e5+10)];
bool pa;
void youhua(){
	ios::sync_with_stdio(0);
	cin.tie(0);
}
bool cmp(node x,node y){
	return x.x>y.x;
}
void dfs(int xx,int sum){
//	cout<<a<<" "<<b<<" "<<c<<" "<<sum<<"\n";
	if(sum+qf[n]-qf[xx-1]<=ans) return;
	if(xx==n+1){
		ans=max(ans,sum);
		return;
	}
	if(a+1<=n/2){
		a++;
		dfs(xx+1,sum+f[xx].x);
		a--;
	}
	if(b+1<=n/2){
		b++;
		dfs(xx+1,sum+f[xx].y);
		b--;
	}
	if(c+1<=n/2){
		c++;
		dfs(xx+1,sum+f[xx].z);
		c--;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	youhua();
	cin>>T;
	while(T--){
		cin>>n;
		
		memset(qf,0,sizeof(qf));
		pa=true;
		a=b=c=0;
		ans=0;
		
		for(int i=1;i<=n;i++){
			cin>>f[i].x>>f[i].y>>f[i].z;
			if(f[i].y!=0) pa=false;
			qf[i]=qf[i-1]+max(f[i].x,max(f[i].y,f[i].z));
		} 
		if(pa){
			sort(f+1,f+n+1,cmp);
			for(int i=1;i<=n/2;i++)
				ans=ans+f[i].x;
		}
		else dfs(1,0);
		cout<<ans<<"\n";
	}
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0 
*/

