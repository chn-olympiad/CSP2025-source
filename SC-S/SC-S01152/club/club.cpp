#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+10;
long long a[MAXN][5];
struct node{
	long long sum,id,x,ne;
	bool operator<(const node &ao)const{
		//if(ao.sum==sum)return id<ao.id;
		return sum>ao.sum;
	}
};
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n;
	cin>>t;
	vector<priority_queue<node> > q(4);
	while(t--){
		cin>>n;
		memset(a,0,sizeof a);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
			long long mx=1,mxn=2;
			if(a[i][1]>a[i][mx]){
				mx=1;
				mxn=mx;
			}
			if(a[i][2]>a[i][mx]){
				mx=2;
				mxn=mx;
			}
			if(a[i][3]>a[i][mx]){
				mx=3;
				mxn=mx;
			}
			if(mxn==mx){
				mxn=(mx-1+3-1)%3+1;
				if(a[i][mx%3+1]>a[i][mxn]){
					mxn=mx%3+1;
				}
			}
			long long mc=a[i][mx]-a[i][mxn];
			//cout<<i<<' '<<mc<<'\n';
			//cout<<1; 
			if(q[mx].size()+1>n/2){
				//cout<<1.5;
				node p=q[mx].top();
				if(p.sum<mc&&p.x!=3){
					q[mx].pop();
					q[mx].push({mc,i,1,mxn});
					long long nx=a[p.ne]-a[6-mx-p.ne];
					if(p.x+1==3) nx=2e9;
					q[p.ne].push({nx,p.id,p.x+1,6-mx-p.ne});
				}else{
					long long nx=6-mx-mxn;
					mc=a[i][mxn]-a[i][nx];
					q[mxn].push({mc,i,2,nx});
				}
			}else{
				//cout<<1.6;
				q[mx].push({mc,i,1,mxn});
			}		
			//cout<<2;
		}

		long long ans=0;
		for(int i=1;i<=3;i++){
			while(!q[i].empty()){
				node p=q[i].top();
				q[i].pop();
				//cout<<p.id<<','<<p.sum<<' ';
				ans+=a[p.id][i]; 
			}
			//cout<<'\n';
		}
		cout<<ans<<'\n';
	}
	return 0;
}

