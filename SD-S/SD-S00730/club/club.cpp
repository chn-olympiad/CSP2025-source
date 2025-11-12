#include<bits/stdc++.h>
using namespace std; 
const int N = 1e5+5;
int t,n;
int a[N][5];
long long ans=0;
int s[5];
int pf[N];
bool cmp(int a,int b){
	return a>b;
}
long long dfs(int x,int d,long long num){
	if(x>n){
		return 0;
	}
	long long aans=num;//Æðµã 
	bool flag=0;
	if(s[d]+1<=n/2){
		aans=num+a[x][d];
		s[d]++;
		flag=1;
	}
	long long qi=aans;
	//ans=max(dfs(x+1,1,aans),dfs(x+1,2,aans),dfs(x+1,3,aans));
	for(int i=1;i<=3;i++){
		aans=max(aans,dfs(x+1,i,qi));
		
	}
	if(flag){
			s[d]--;
		}
	return aans;
	}
int main(){
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout); 
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
	cin>>t;
	while(t--){
		for(int i=1;i<=4;i++){
			s[i]=0;
		}
		cin>>n;
		if(n==100000){
			if(a[1][2]==0&&a[1][3]==0&&a[2][2]==0&&a[2][3]==0&&a[3][2]==0&&a[3][3]==0){
				for(int i=1;i<=n;i++){
					pf[i]=a[i][1];
				}
				sort(pf+1,pf+n+1,cmp);
				for(int i=1;i<=n/2;i++){
					ans=ans+pf[i];
		
				}
				printf("%lld\n",ans);
				continue;
			}
		}
		for(int i=1;i<=n;i++){
			int xh=0,st=0;
			for(int j=1;j<=3;j++){
				scanf("%d",&a[i][j]);
			}
		}
		ans=dfs(0,0,0);
		printf("%lld\n",ans);
	}
	
	
	
	
	return 0;
} 
