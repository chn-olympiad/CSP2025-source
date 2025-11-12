#include<bits/stdc++.h>
#define ll long long 
const int N=1e5+5;
int T;
int n;
ll a[N][5];
//ll f[N][5][2];
struct node{
	ll val;
	ll pos;
	ll idx;
}num[N*5];
int sum[5];
int ans=-1;
bool cmp(node x,node y){
	return x.val>y.val;
}
void dfs(int now,int cl_1,int cl_2,int cl_3,int sum){
	if(cl_1>n/2||cl_2>n/2||cl_3>n/2){
		return ;
	}
	if(cl_1+cl_2+cl_3==n){
		ans=std::max(ans,sum);
		return ;
	}
	for(int i=1;i<=3;i++){
		if(i==1){
			dfs(now+1,cl_1+1,cl_2,cl_3,sum+a[now][1]);
		}else if(i==2){
			dfs(now+1,cl_1,cl_2+1,cl_3,sum+a[now][2]);
		}else if(i==3){
			dfs(now+1,cl_1,cl_2,cl_3+1,sum+a[now][3]);
		}
	}
}
bool vis[N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
//		memset(f,0,sizeof(f));
		ans=-1;
		scanf("%d",&n);
		bool check=false;
		for(int i=1;i<=n;i++){
			scanf("%lld%lld%lld",&a[i][1],&a[i][2],&a[i][3]);
			num[(n-1)*3+1]={a[i][1],1,i};
			num[(n-1)*3+2]={a[i][2],2,i};
			num[(n-1)*3+3]={a[i][3],3,i};
			if(a[i][2]!=0){
				check=true;
			}
		}
		if(n<=60){
			dfs(1,0,0,0,0);
		}else if(!check){
			int sum=0;
			std::sort(num+1,num+1+3*n,cmp);
			for(int i=1;i<=n/2;i++){
				sum+=num[i].val;
			}
			ans=sum;
		}else{
			memset(vis,0,sizeof(vis));
			memset(sum,0,sizeof(sum));
			ans=0;
			std::sort(num+1,num+1+3*n,cmp);
			for(int i=1;i<=3*n;i++){
				if(vis[num[i].idx]==false&&sum[num[i].pos]<n/2){
					ans+=num[i].val;
					vis[num[i].idx]=true;
					sum[num[i].pos]++;
				}
			}
		}
		
		printf("%d\n",ans);
	}
	
	
	
	return 0;
}
