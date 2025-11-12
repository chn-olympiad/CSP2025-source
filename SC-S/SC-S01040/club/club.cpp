#include<bits/stdc++.h>
using namespace std;

const int N=5e5+10;
int n,T;

int a[N][4];//满意度
int ans=0;

void dfs(int i,int sum,int c1,int c2,int c3){//第i个人 选第q种 满意度有多少  
	if(i==n){
		ans=max(ans,sum); 
		return;
	}
	for(int j=1;j<=3;j++){
		if(j==1&&(c1+1)<=n/2){
			dfs(i+1,sum+a[i+1][j],c1+1,c2,c3);
		}else if(j==2&&(c2+1)<=n/2){
			dfs(i+1,sum+a[i+1][j],c1,c2+1,c3);
		}else if(j==3&&(c3+1)<=n/2){
			dfs(i+1,sum+a[i+1][j],c1,c2,c3+1);
		}
	}
}

int o[N];

int main(){
	freopen("club.in ","r",stdin);	
	freopen("club.out ","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	
	cin >> T;
	while(T--){
		cin >> n;
		int f=1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++) cin >> a[i][j];
			if(a[i][2]!=0||a[i][3]!=0) f=0;
		}
			
			if(f==1){//只有a[i][1]有值 
				int idx=1;//注意 一定是偶数 
				for(int i=1;i<=n;i++){
					o[idx]=a[i][1];
					idx++;
				}
				sort(o+1,o+1+n);
				for(int i=n;i>n/2;i--) ans+=o[i];
			}else{
				dfs(1,a[1][1],1,0,0);
				dfs(1,a[1][2],0,1,0);
				dfs(1,a[1][3],0,0,1);
				
			}
			
		cout << ans <<'\n';
		ans=0;
	}
	return 0;
}
