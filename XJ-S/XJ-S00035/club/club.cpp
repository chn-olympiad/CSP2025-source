#include<bits/stdc++.h>
using namespace std;
long long t,n,a[100005][5],b[5],k[100005],f[100005][5];
long long ans=0,sum;
void dfs(int x,int c){
	if(b[c]>(n/2)){
		return;
	}
	ans+=a[x][c];
	b[c]++;
	if(b[c]>(n/2)){
		ans-=a[x][c];
		b[c]--;
		return;
	}
	if(x==n){
		sum=max(sum,ans);
		ans-=a[x][c];
		b[c]--;
		return;
	}
	dfs(x+1,1);
	dfs(x+1,2);
	dfs(x+1,3);
	ans-=a[x][c];
	b[c]--;
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		sum=0;
		cin>>n;
		int o=0,p=0;
		for(int i=1;i<=n;i++){
			cin>>a[i][1];
			cin>>a[i][2];
			cin>>a[i][3];
			k[i]=a[i][1];
			o+=a[i][2];
			p+=a[i][3];
		}
		if(o==0 && b==0){
			sort(k,k+n+1);
			for(int i=1;i<=n/2;i++){
				sum+=k[i];
			}
			cout<<sum<<endl;
			
		}
		else{
			dfs(1,1);
			dfs(1,2);
			dfs(1,3);
			cout<<sum<<endl;
		}
		sum=0;
		ans=0;
		memset(b,0,sizeof(b));
	}
}
