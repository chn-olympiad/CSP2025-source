#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,k;
int a[N];
int f,t,e;
map<int,int> q[N];
map<int,int> mp;
map<int,int> l;
map<int,int> c;
int sum=0;
void dfs(int x,int cnt,int u){
	sum=max(sum,cnt);
	if(x==n){
		sum=max(sum,cnt);
		return ;
	}
	if(sum>n-x+1+cnt) return ;
	if((u&&!l[x])||(!u&&!c[x])) return ;
	if(u==0){
		dfs(c[x],cnt+1,1);
		dfs(c[x],cnt,0);
	}
	else{
		dfs(l[x],cnt+1,1);
		dfs(l[x],cnt,0);
	}
//	while()
//	for(int i=g+1;i<=n;i++){
//		if(mp[i]){
////			cout<<i<<' '<<mp[i]<<endl;
//			dfs(mp[i],cnt+1,1);
//			dfs(i,cnt,0);
//		}
//	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		f+=(a[i]==1);
		t+=(a[i]==0);
//		e+=(a[i]<=255)
	}
	if(f==n&&k==0) cout<<n/2;
	else if(t+f==n&&k<=1){
		if(k==0){
			for(int i=1;i<=n;){
				if(a[i]==1&&a[i+1]==1) t++,i+=2;
				else i++;
			}
			cout<<t;
		}
		else cout<<f;
	}
	else{
		for(int i=1;i<=n;i++){
			int x=a[i];q[i][i]=a[i];
			if(a[i]==k){
				mp[i]=i;	
				continue;
			}
			for(int j=i+1;j<=n;j++){
				x=x^a[j];
				q[i][j]=x;
				if(q[i][j]==k){
					mp[i]=j;
					break;	
				}
			}
		}
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++){
				if(mp[j]&&j>mp[i]&&!l[i]) l[i]=mp[j];
				if(!c[i]&&mp[j]) c[i]=mp[j]; 
			}
//		cout<<l[2]<<endl<<c[2]<<endl;	
//		cout<<mp[1]<<' '<<mp[2];
		for(int i=1;i<=n;i++){
			if(mp[i]) dfs(i,1,1);
		}
		cout<<sum;
	}
	return 0;
} 
