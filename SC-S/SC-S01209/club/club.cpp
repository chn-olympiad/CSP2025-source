#include<bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;
using std::freopen;
using std::max;
using std::priority_queue;
const int N=1e5+6;
int m[101][101][101];
int b[N];
const int dir[][3]={{1,0,0},{0,1,0},{0,0,1}};
struct BFS{
	BFS(int s=0,int p=0,int a=0,int b=0,int c=0):sum(s),pos(p),x(a),y(b),z(c){ }
	bool operator<(const BFS &b) const{
		return (sum!=b.sum?sum<b.sum:pos>b.pos);
	}
	int sum,pos,x,y,z;
};
int bfs(int sum,int pos,int x,int y,int z,int n,int a[][3])
{
	priority_queue<BFS> q;
	int ans=0;
	q.push(BFS(sum,pos,x,y,z));
	m[x][y][z]=0;
	BFS temp;
	int ns,np,nx,ny,nz;
	while(!q.empty()){
		temp=q.top();
		q.pop();
		if(temp.pos==n){
			ans=max(temp.sum,ans);
			continue;
		}
		np=temp.pos+1;
		for(int i=0;i<3;i++){
			ns=temp.sum+a[temp.pos][i];
			nx=temp.x+dir[i][0];
			ny=temp.y+dir[i][1];
			nz=temp.z+dir[i][2];
			if(nx<=n/2&&ny<=n/2&&nz<=n/2)
				if(m[nx][ny][nz]<=ns)
					if(ns+b[np]>=ans)
						q.push(BFS(ns,np,nx,ny,nz)),m[nx][ny][nz]=ns;
		}
	}
	return ans;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n,ans1,ans2,ans3;
	int a[N][3];
	cin>>t;
	while(t--){
		ans1=ans2=ans3=0;
		cin>>n;
		for(int i=0;i<n;i++)
			cin>>a[i][0]>>a[i][1]>>a[i][2];
		b[n]=0;
		for(int i=n-1;i>=0;i--)
			b[i]=b[i+1]+max(a[i][0],max(a[i][1],a[i][2]));
		memset(m,0,sizeof(m));
		cout<<bfs(0,0,0,0,0,n,a)<<endl;
	}
	return 0;
}