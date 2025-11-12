#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const long long N=100000+10;
int t,n;
struct Node{
	long long num;
	int index;
	int pai;
}a[N][3],aa[N][3];
bool st[N];
bool cmp1(Node a,Node b){
	return b.num<a.num;
}

long long ans=0;
long long x=0,y=0,z=0;
void dfs(int step,int n,long long res,Node a[N][3],int x,int y,int z);
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		for(int i=1;i<=n;i++){
			st[i]=false;
		}
		ans=0;
		cin>>n;
		x=0,y=0,z=0;
		bool A_st=true;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j].num;
				a[i][j].index=j;
				aa[i][j]=a[i][j];
			}
			if(a[i][2].num!=0||a[i][3].num!=0){
				A_st=false;
			}
			sort(a[i]+1,a[i]+1+3,cmp1);
		}
		if(n<=20){
			dfs(1,n,0,aa,0,0,0);
			cout<<ans<<endl;
			continue;
		}
		Node g[N];
		for(int i=1;i<=n;i++){
			g[i]=a[i][1];
			g[i].pai=i;
		}
		sort(g+1,g+1+n,cmp1);
		if(A_st){
			for(int i=1;i<=n/2;i++){
				ans+=g[i].num;
			}
			cout<<ans<<endl;
			continue;
		}
		for(int i=1;i<=n;i++){
			if(g[i].index==1){
				if(x<n/2){
					x++;
					ans+=g[i].num;
					st[g[i].pai]=true;
				}
			}
			if(g[i].index==2){
				if(y<n/2){
					y++;
					ans+=g[i].num;
					st[g[i].pai]=true;
				}
			}
			if(g[i].index==3){
				if(z<n/2){
					z++;
					ans+=g[i].num;
					st[g[i].pai]=true;
				}
			}
		}
		
		for(int i=1;i<=n;i++){
			if(!st[i]){
				ans+=a[i][2].num;
			}
		}
		printf("%lld\n",ans);
	}
	

	return 0;
}

void dfs(int step,int n,long long res,Node a[N][3],int x,int y,int z){
	if(step==n+1){
		ans=max(res,ans);
		return ;
	}
	for(int i=1;i<=3;i++){
		if(x<n/2&&i==1){
			dfs(step+1,n,res+a[step][i].num,a,x+1,y,z);
		}
		if(y<n/2&&i==2){
			dfs(step+1,n,res+a[step][i].num,a,x,y+1,z);
		}
		if(z<n/2&&i==3){
			dfs(step+1,n,res+a[step][i].num,a,x,y,z+1);
		}
	}
}