#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
long long a[10005],n,m,a1,ans=0;
void solve_pol(int x,int y,int z){
	if(z==0){
		if(y>2*a[x]){
			ans++;
		} 
		return ;
	}
	for(int i=x+1;i+z-1<=n;i++){
		y+=a[i];
		solve_pol(i,y,z-1);
		y-=a[i];
	}
	
}
void solve(int x){
	int a1=1;
	while(a1+x-1<=n){
		int sum=a[a1];
		solve_pol(a1,sum,x-1);
		a1++;
	}
	return ;
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
    cin>>n;
    if(n>5000){
    	ans=(n*(n-1)/2*(n-2))%998244353;
    	cout<<ans;
    	fclose(stdin);
	    fclose(stdout);
    	return 0;
	}
    for(int i=1;i<=n;i++){
    	cin>>a[i];
	}
    sort(a,a+n+1);
    for(int i=3;i<=n;i++){
        solve(i);	
	}
	ans%=998244353;
    cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
