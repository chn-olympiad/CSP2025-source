#include<bits/stdc++.h>
using namespace std;
int n,t,sum,a[5001],ans;
void dg(int x,int s,int w,int m){ 
	if(x==0){
		if(a[w]*2<s){
			ans++;
			ans%=998244353;
		}
		return ;
	}
	for(int i=1;i<m;i++)
		dg(x-1,s+a[i],max(w,i),i);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
	}
	sort(a+1,a+n+1);
	for(int i=n;i>=1;i--)
		if(a[i]*2>=sum){
			t++;
			sum-=a[i];
			a[i]=0;
		}
	for(int i=3;i<=n-t;i++)
		dg(i,0,0,n-t+1); 
	cout<<ans;
	return 0;
}
