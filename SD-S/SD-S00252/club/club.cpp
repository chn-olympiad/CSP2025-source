#include <bits/stdc++.h>
using namespace std ;
int w,n,a[100005][3] ;
int flag1=0,flag2=0 ;
int n0=0,n1=0,n2=0,maxx=-1 ;
int x[100005] ;
struct aaa{
	int x,y ;
};
bool cmp(int x,int y){
	return x<y ;
}
void dfs(int t){
	if(t==n){
		if((n0+1)<=n/2){
			x[t]=0 ;
			int sum=0 ;
			for(int i=1 ;i<=n ;i++){
				sum+=a[i][x[i]] ;
			}
			maxx=max(maxx,sum) ;
			x[t]=-1 ;
		}
		if((n1+1)<=n/2){
			x[t]=1 ;
			int sum=0 ;
			for(int i=1 ;i<=n ;i++){
				sum+=a[i][x[i]] ;
			}
			maxx=max(maxx,sum) ;
			x[t]=-1 ;
		}
		if((n2+1)<=n/2){
			x[t]=2 ;
			int sum=0 ;
			for(int i=1 ;i<=n ;i++){
				sum+=a[i][x[i]] ;
			}
			maxx=max(maxx,sum) ;
			x[t]=-1 ;
		}
	}
	if((n0+1)<=n/2){
		x[t]=0 ;
		n0++ ;
		dfs(t+1) ;
		n0-- ;
		x[t]=-1 ;
	}
	if((n1+1)<=n/2){
		x[t]=1 ;
		n1++ ;
		dfs(t+1) ;
		n1-- ;
		x[t]=-1 ;
	}
	if((n2+1)<=n/2){
		x[t]=2 ;
		n2++ ;
		dfs(t+1) ;
		n2-- ;
		x[t]=-1 ;
	}
	return ;
}
int main(){
	ios::sync_with_stdio(false) ;
	freopen("club.in","r",stdin) ;
	freopen("club.out","w",stdout) ;
	cin>>w ;
	while(w--){
		cin>>n ;
		flag1=0 ;flag2=0 ;
		n0=0 ;n1=0 ;n2=0 ;
		maxx=-1 ;
		for(int i=1 ;i<=n ;i++){
			cin>>a[i][0]>>a[i][1]>>a[i][2] ;
			if(a[i][1]!=0){
				flag1=1 ;
			}
			if(a[i][2]!=0){
				flag2=1 ;
			}
		}
		if(flag1==0&&flag2==0){
			int b[100005] ;
			for(int i=1 ;i<=n ;i++){
				b[i]=a[i][0] ;
			}
			sort(b,b+n,cmp) ;
			int sum=0 ;
			for(int i=n ;i>=n/2+1 ;i--){
				sum+=b[i] ;
			}
			cout<<sum<<endl ;
			continue ;
		}
		dfs(1) ;
		cout<<maxx<<endl ;
	}
	fclose(stdin) ;
	fclose(stdout) ;
	return 0 ;
}
