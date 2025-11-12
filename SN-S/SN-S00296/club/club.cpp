#include<bits/stdc++.h>
using namespace std;
int t,n,check,a[100100],b[100100],c[100100],sum=0;
int cmp(int a,int b){
	if(a>b){
		return 1;
	}
	return 0;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		check=n/2;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
		}
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=check;i++){
			sum+=a[i];
		}
		cout<<sum<<endl;
	}
	
	return 0;
}
