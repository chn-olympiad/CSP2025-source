#include<bits/stdc++.h>
#define ll long long 
using namespace std;
int t,n;
ll a[200005][5];
ll f[200005][5];
ll ans;
void dfs(int b,int c,ll anew,int cnew[4]){
	/*cout<<b<<" "<<c<<" "<<anew<<" ";
	for(int i=1;i<=3;i++){
		cout<<cnew[i]<<" ";
	}
	cout<<endl;*/
	/*if(f[b][c]!=-1){
		//cout<<"fbc:"<<f[b][c]<<endl;
		return f[b][c];
	}*/
	if(b==n){
		ans=max(anew,ans);
		return;
		//cout<<"ans:"<<ans<<endl;
		//return ans;
	}
	//ll max_num=0;
	for(int i=1;i<=3;i++){
		if(cnew[i]+1>n/2) continue;
		cnew[i]++;
		//ll re=
		dfs(b+1,i,anew+a[b+1][i],cnew);
		//cout<<f[b+1][i]<<" "<<re<<endl;
		//f[b+1][i]=max(f[b+1][i],re);
		//max_num=max(max_num,f[b+1][i]);
		/*cout<<"mp:"<<endl;
		for(int j=1;j<=n;j++){
			for(int k=1;k<=3;k++){
				cout<<f[j][k]<<" ";
			}
			cout<<endl;
		}*/
		//cout<<"i"<<i<<endl;
		cnew[i]--;
	}
	//return max_num;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		memset(f,-1,sizeof(f));
		ans=0;
		cin>>n;
		for(int j=1;j<=n;j++){
			for(int k=1;k<=3;k++){
				cin>>a[j][k];
			}
		}
		int input[4]={0,0,0,0};
		dfs(0,0,0,input);
		cout<<ans<<"\n";
	}
	return 0;
}
