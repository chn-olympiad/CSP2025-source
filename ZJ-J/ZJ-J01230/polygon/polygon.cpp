#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[10000];
int cnt;
int	n,maxn=-1;
int flag;
int wl;
//void dfs(int mu,int step,int cnt2){
//	if(cnt2>wl)	return ;
//	cout<<cnt2<<"!!!!!!!!\n";
//	
//	if(mu==step){
//		cout<<cnt<<" "<<maxn<<"\n";
//		if(cnt2>maxn*2){
//			cnt++;
//			return ;
//			cout<<"*";
//		}
//	}
//	else{
//		for(int i=step;i<=n;i++){
//	
//			maxn=max(a[i],maxn);
//			cout<<a[i]<<"-"<<step<<"\n";
//			dfs(mu,step+1,cnt2+a[i]);
//		
//		
//		}
//	}
//	
//}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);

	cin>>n;
//	for(int i=1;i<=n;i++){
//		int t;
//		cin>>t;
//		a[i]=t;
//	}
//	sort(a+1,a+n+1);
//	if(a[1]+a[2]+a[3]>2*a[n])	cnt++;
//	cout<<cnt;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		wl+=a[i];
	}
	sort(a+1,a+n+1);
	
	if(n==3){
		if(a[1]+a[2]+a[3]>2*a[n])	cnt++;
	}
	
//	
//	for(int i=3;i<=n;i++){
//	
//		dfs(i,1,0);
//	}	
	cout<<cnt;
	return 0;
}
