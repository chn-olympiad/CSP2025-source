#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define up(i,j,k,l) for(int i=j;i<=k;i+=l)
#define down(i,j,k,l) for(int i=j;i>=k;i-=l)
using namespace std;
const int N=1e5+10;
int n;
struct node{
	int id,val,h;
};
node a[N][5];
int b[N][5];
int tf[N];
priority_queue<node> q[5];
bool operator<(node x1,node x2)
{
	return x1.val>x2.val;
}
int ans;
bool cmp(node x1,node x2)
{
	return x1.val>x2.val;
}
void dfs(int u,int c1,int c2,int c3,int res)
{
	if(u==n+1){
		ans=max(ans,res);
		return;
	}
	if(c1+1<=n/2){
		dfs(u+1,c1+1,c2,c3,res+b[u][1]);
	}
	if(c2+1<=n/2){
		dfs(u+1,c1,c2+1,c3,res+b[u][2]);
	}
	if(c3+1<=n/2){
		dfs(u+1,c1,c2,c3+1,res+b[u][3]);
	}	
	return;
}
void solve()
{
	bool f=true;
	cin>>n;
	up(i,1,n,1){
		up(j,1,3,1){
			cin>>a[i][j].val;
			b[i][j]=a[i][j].val;
			a[i][j].id=j;
			a[i][j].h=i;
			if(j>=2 && a[i][j].val!=0){
				f=false;
			}
			tf[i]=a[i][1].val;
		}
		sort(a[i]+1,a[i]+3+1,cmp);
	}
	if(f){
		ans=0;
		sort(tf+1,tf+n+1,greater<int>());
		up(i,1,n/2,1){
			ans+=tf[i];
		}
		cout<<ans<<endl;
		return;
	}
	if(n<=10){
		ans=0;
		dfs(1,0,0,0,0);
		cout<<ans<<endl;
		return;
	}
	node tp;
	int lid,xid;
	up(i,1,n,1){
		up(j,1,3,1){
			lid=a[i][j].id;
			if((int)q[lid].size()<n/2){
				q[lid].push(a[i][j]);
				//cout<<"CHOOSE:"<<i<<' '<<a[i][j].id<<endl;
				break;
			}
			else{
				//cout<<"FH"<<i<<endl;
				tp=q[lid].top();
				up(k,1,3,1){
					xid=a[tp.h][k].id;
					//cout<<"TP"<<tp.id<<' '<<tp.val<<' '<<tp.h<<endl;
					if(xid!=lid && tp.val<a[tp.h][k].val+a[i][j].val && (int)q[xid].size()<n/2){
						//cout<<"CHOOSE:"<<tp.h<<' '<<tp.id<<"->"<<k<<endl;
						q[lid].pop();
						q[lid].push(a[i][j]);
						q[xid].push(a[tp.h][k]);
						break;
					}
				}	
			}		
		}
	}
	ans=0;
	up(i,1,3,1){
		while(!q[i].empty()){
			//cout<<"ANS:"<<i<<' '<<q[i].top().h<<' '<<q[i].top().val<<endl;
			ans+=q[i].top().val;
			q[i].pop();
		}
	}
	cout<<ans<<endl;
	return;
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	//cout.tie(0);
	int _=1;
	cin>>_;
	up(i,1,_,1){
		solve();
	}
	return 0;
}

