#include<bits/stdc++.h>
using namespace std;


long long n,ans=0,maxp;
long long a[100010][4]={},b[100010]={};

void dfs(long long k,long long sum,long long fp,long long sp,long long tp){
	
	if(k>n){
		ans=max(sum,ans);
		return;
	}
	
	for(long long i=1;i<=3;i++){
		long long fp2=fp,sp2=sp,tp2=tp;
		
		if(i==1) fp2++;
		else if(i==2) sp2++;
		else tp2++;
		
		if(fp2>maxp || sp2>maxp || tp2>maxp) continue;
		if(sum+a[k][i]+a[k+1][4]<=ans) continue;
		
		dfs(k+1,sum+a[k][i],fp2,sp2,tp2);
	}
}

void game(){
	
	bool flag=1;
	
	ans=0;
	cin>>n;
	maxp=n/2;
	for(long long i=1;i<=n;i++){
		cin>>a[i][1]>>a[i][2]>>a[i][3];
		if(a[i][2]!=0 || a[i][3]!=0) flag=0;
		if(flag) b[i]=a[i][1];
		
	}
	
	if(flag){
		sort(b+1,b+n+1);
		ans=0;
		for(int i=n;i>maxp;i--){
			ans+=b[i];
		}
		cout<<ans<<endl;
		return;
	}
	
	for(long long i=n;i>=1;i--){
		a[i][4]=max(max(a[i][1],a[i][2]),a[i][3]);
		if(i!=n){
			a[i][4]+=a[i+1][4];
		}
	}
	
	dfs(1,0,0,0,0);
	
	cout<<ans<<endl;
	
	return;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	int t;
	cin>>t;
	for(int i=1;i<=t;i++){
		game();
	}
	
	return 0;
}

