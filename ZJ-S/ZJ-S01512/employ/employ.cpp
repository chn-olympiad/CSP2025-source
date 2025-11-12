#include<bits/stdc++.h>
using namespace std;
long long t,n,mx=-(1<<30),a[100005]={},b[100005]={},c[100005]={},a1,b1,c1;
int dfs(int k,long long s){
	if (k>n){mx=max(s,mx);return 0;}
	for (int i=1;i<=3;i++){
		if (i==1 and a1>0){a1-=1;dfs(k+1,s+a[k]);a1+=1;} 
		else if (i==2 and b1>0){b1-=1;dfs(k+1,s+b[k]);b1+=1;} 
		else if (i==3 and c1>0){c1-=1;dfs(k+1,s+c[k]);c1+=1;} 
	}
	return 0;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for (int x=0;x<t;x++){
		cin>>n;a1=n/2;b1=n/2;c1=n/2;
		for (int i=1;i<=n;i++) cin>>a[i]>>b[i]>>c[i];
		dfs(1,0);
		cout<<mx<<endl;mx=-(1<<30);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}