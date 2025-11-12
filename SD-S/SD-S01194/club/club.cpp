#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int t;
int n;
int ps[N][4];
int psi[N];
int ans=0;
bool for_A=true,for_B=true,for_C=true;
void dfs(int ni,int a,int b,int c,int s){
	//ni:人员编号;a:部门1人数;b:部门2人数;c:部门3人数;s:总满意度;
	//分别考虑将成员n放入部门1,2,3同时记录此时的总和以及人数
	if(ni==n+1){
		ans=max(ans,s);
		return;
	}
	ni++;
	if(a<n/2){
		dfs(ni,a+1,b,c,s+ps[ni-1][1]);
	}
	if(b<n/2){
		dfs(ni,a,b+1,c,s+ps[ni-1][2]);
	}
	if(c<n/2){
		dfs(ni,a,b,c+1,s+ps[ni-1][3]);
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		for_A=true;
		for_B=true;
		for_C=true;
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>ps[i][j];
				for_A=for_A&&(j==1||ps[i][j]==0);
				for_B=for_B&&(j==2||ps[i][j]==0);
				for_C=for_C&&(j==3||ps[i][j]==0);
			}
		}
		if(for_A){
			for(int i=1;i<=n;i++){
				psi[i]=ps[i][1];
			}
			sort(psi+1,psi+1+n);
			for(int i=n;i>(n/2);i--){
				ans=ans+psi[i];
			}
			cout<<ans<<"\n";
		}else if(for_B){
			for(int i=1;i<=n;i++){
				psi[i]=ps[i][2];
			}
			sort(psi+1,psi+1+n);
			for(int i=n;i>(n/2);i--){
				ans=ans+psi[i];
			}
			cout<<ans<<"\n";
		}else if(for_C){
			for(int i=1;i<=n;i++){
				psi[i]=ps[i][2];
			}
			sort(psi+1,psi+1+n);
			for(int i=n;i>(n/2);i--){
				ans=ans+psi[i];
			}
			cout<<ans<<"\n";
		}else{
		    dfs(1,0,0,0,0);
		    cout<<ans<<"\n";
		}
	}
	return 0;
}
