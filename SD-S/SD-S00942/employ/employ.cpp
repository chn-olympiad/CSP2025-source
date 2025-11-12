#include <bits/stdc++.h>
using namespace std;

const int N=500;
int n,m;
char d;
int a[N],p[N];
int mk[N];
long long ans=0;
bool A=true;

void dfs(int x,int q1,int t,int pas1){
	int q=q1,pas=pas1;	
	
	if(p[t]==1&&a[x]>q){
		pas++;
	}
	else if((p[t]==0)||(a[x]<=q)){
		q++;
	}
	if(t==n){
		if(pas>=m){
			ans++;
			ans=ans%998244353;
		} 
		return;
	}
	for(int i=1;i<=n;i++){
		if(mk[i]==0){
			mk[i]=1;
			dfs(i,q,(t+1),pas);
			mk[i]=0;
		}
	}
	return;
}

bool cmp(int a,int b){
	return a>b;
}

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>d;
		p[i]=d-'0';
		if(p[i]==0)A=false;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	for(int i=1;i<=n;i++){
		mk[i]=1;
		dfs(i,0,1,0);
		mk[i]=0;
	}
	cout<<ans;
	
	return 0;
} 
