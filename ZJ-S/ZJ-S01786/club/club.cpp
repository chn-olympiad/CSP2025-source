#include<bits/stdc++.h>
#define inf 0x7fffffff
#define int long long
using namespace std;
void read(int&a){
	int f=1,x=0;
	char ch=getchar();
	while(ch<48||ch>57){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>=48&&ch<=57){
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	a=f*x;
}
void print(int x){
	if(x<0){
		putchar('-');
		print(-x);
		return;
	}
	if(x<10){
		putchar(x+48);
		return;
	}
	else{
		print(x/10);
		putchar(x%10+48);
		return;
	}
}
int v[100010][4];
int t[4],c[4],ans;
bool vis[100010][4];
priority_queue<pair<int,int> >q[4];
int n;
void dfs(int x){
	if(x>n){
		ans=max(ans,t[1]+t[2]+t[3]);
		return;
	}
	for(int i=1;i<=3;i++){
		if(c[i]+1>n/2)continue;
		c[i]++;
		t[i]+=v[x][i];
		dfs(x+1);
		c[i]--;
		t[i]-=v[x][i];
	}
}
void insert(int i){
	priority_queue<pair<int,int> >temp;
	for(int j=1;j<=3;j++){
		temp.push({v[i][j],j});
	}
	pair<int,int>x,y,z,P;
	x=temp.top();
	temp.pop();
	y=temp.top();
	temp.pop();
	z=temp.top();
	temp.pop();
	if(!vis[i][x.second]){
		vis[i][x.second]=true;
		q[x.second].push({-(x.first-y.first),i});
		P=q[x.second].top();
		if(q[x.second].size()<=n/2)return;
		else{
			ans+=P.first;
			q[x.second].pop();
			insert(P.second);
		}
	}
	else if(!vis[i][y.second]){
		vis[i][y.second]=true;
		q[y.second].push({-(y.first-z.first),i});
		P=q[y.second].top();
		if(q[y.second].size()<=n/2)return;
		else{
			ans+=P.first;
			q[y.second].pop();
			insert(P.second);
		}
	}
	else if(!vis[i][z.second]){
		vis[i][z.second]=true;
		q[z.second].push({-inf,i});
		P=q[z.second].top();
		if(q[z.second].size()<=n/2)return;
		else{
			ans+=P.first;
			q[z.second].pop();
			insert(P.second);
		}
	}
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	read(T);
//	cin>>T;
	while(T--){
		ans=0;
		while(!q[1].empty())q[1].pop();
		while(!q[2].empty())q[2].pop();
		while(!q[3].empty())q[3].pop();
//		cin>>n;
		read(n);
		c[1]=c[2]=c[3]=0;
		for(int i=1;i<=n;i++){
			int maxx=0,pos=0;
			for(int j=1;j<=3;j++){
				vis[i][j]=false;
				read(v[i][j]);
//				cin>>v[i][j];
				if(maxx<v[i][j]){
					pos=j;
					maxx=v[i][j];
				}
			}
			c[pos]++;
			ans+=maxx;
		}
//		if(c[1]<=n/2&&c[2]<=n/2&&c[3]<=n/2){
//			cout<<ans<<'\n';
//			continue;
//		}
//		c[1]=c[2]=c[3]=0;
//		if(n<=10){
//			ans=0,t[1]=t[2]=t[3]=0;
//			dfs(1);
//			cout<<ans<<'\n';
//			continue;
//		}
		for(int i=1;i<=n;i++){
			insert(i);
		}
		print(ans);
		puts("");
	}
	return 0;
}
