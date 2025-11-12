#include<bits/stdc++.h>
using namespace std;
priority_queue<pair<int,int> >qu1;
priority_queue<pair<int,int> >qu2;
priority_queue<pair<int,int> >qu3;
int n;
long long ans=0;
int vis[100005];
int d[100005],e[100005],f[100005];
void dfs(int i,int a,int b,int c,long long s){
	if(i==n+1){
		//cout<<s<<" ";
		ans=max(ans,s);
		return ;
	}
	if(a<n/2)dfs(i+1,a+1,b,c,s+d[i]);
	if(b<n/2)dfs(i+1,a,b+1,c,s+e[i]);
	if(c<n/2)dfs(i+1,a,b,c+1,s+f[i]);
	return ;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t=0;
	cin>>t;
	while(t--){
		ans=0;
		int fx=0,fy=0,fz=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			int a,b,c;
			cin>>a>>b>>c;
			d[i]=a;
			e[i]=b;
			f[i]=c;
			qu1.push({a,i});
			qu2.push({b,i});
			qu3.push({c,i});
			vis[i]=0;
		}
		if(n<=10){
			dfs(1,0,0,0,0);
			cout<<ans<<"\n";
			continue;
		}
		for(int i=1;i<=3*n;i++){
			//cout<<i<<" ";
			int xi=qu1.top().second;
			int x=(vis[xi]==0&&fx<n/2)?qu1.top().first:0;
			int yi=qu2.top().second;
			int y=(vis[yi]==0&&fy<n/2)?qu2.top().first:0;
			int zi=qu3.top().second;
        	int z=(vis[zi]==0&&fz<n/2)?qu3.top().first:0;
            if(x>=y&&x>=z&&x!=0){
            	//cout<<x<<" ";
            	ans+=x;
            	vis[xi]++;
            	fx++;
				qu1.pop();
			}else if(y>x&&y>=z&&y!=0){
				//cout<<y<<" ";
				ans+=y;
            	vis[yi]++;
            	fy++;
				qu2.pop();
			}else if(z!=0){
				//cout<<z<<" ";
				ans+=z;
            	vis[zi]++;
            	fz++;
				qu3.pop();
			}else {
				if(!qu1.empty())qu1.pop();
				if(!qu2.empty())qu2.pop();
				if(!qu3.empty())qu3.pop();
			}
			if(fx+fy+fz==n)break;
		}
		while(!qu1.empty())qu1.pop();
		while(!qu2.empty())qu2.pop();
		while(!qu3.empty())qu3.pop();
		cout<<ans<<"\n";
	}
	return 0;
}

