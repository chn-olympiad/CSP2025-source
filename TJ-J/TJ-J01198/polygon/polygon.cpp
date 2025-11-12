# include<bits/stdc++.h>
using namespace std;
int n,a[6000],sum;
bool cmp(int a,int b){
	if(a>b) return true;
	else return false;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		sum+=a[i];
	}
	if(n==3){
		if(a[1]*2<sum) cout<<1;
		else cout<<0;
	}
	return 0;
}
