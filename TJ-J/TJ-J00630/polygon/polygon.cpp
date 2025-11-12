#include<bits/stdc++.h>
using namespace std;
int n,a[5005],v[5005];
long long ans;
void f(int h,int d){
	if(d>=3&&h>2*a[v[d]]){
		ans++;
		ans=ans%998244353; 
	}
	for(int i=v[d]+1;i<=n;i++){
		v[d+1]=i;
		f(h+a[i],d+1);
		v[d+1]=0;
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	f(0,0);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
