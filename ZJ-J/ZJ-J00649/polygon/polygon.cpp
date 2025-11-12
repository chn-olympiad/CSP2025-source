#include<bits/stdc++.h>
using namespace std;
int n,a[5005],q,cnt,s[5005];
void dfs(int depth,int mx,int sum,int x){
	if(depth>n){
		if(x>=3&&sum>2*mx)cnt++;
		return;
	}
	dfs(depth+1,max(mx,a[depth]),sum+a[depth],x+1);
	dfs(depth+1,mx,sum,x);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		q+=(a[i]!=1);
		s[i]=a[i]+s[i-1];
	}
	//1.n=3 12pts
	if(n==3)cout<<(a[1]+a[2]>a[3])+(a[1]+a[3]>a[2])+(a[3]+a[2]>a[1]);
	//2.a[i]=1 24pts
	else if(!q)cout<<n*(n-2)-(2 + n-1)*(n-1 - 2 + 1)/2;
	//36pts
	
	//3.dfs O(n^3)/O(2^n) 40pts
	else dfs(1,0,0,0);
/*	for(int i=3;i<=n;i++){
		for(int j=1;j<=n-i+1;j++){
			int mx=0;
			for(int k=j;k<=i+j-1;k++)mx=max(mx,a[k]);
			cnt+=(s[i+j-1]-s[j-1]>2*mx);
	//	printf("i%d j%d mx%d cnt%d s%d\n",i,j,mx,cnt,s[i+j-1]-s[j-1]);
		}
	}*/
	cout<<cnt;
	//64pts
	fclose(stdin);
	fclose(stdout);
	return 0;
}
