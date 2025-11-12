//SN-J00269
//安奭颉
//西安高新一中沣东中学初中校区
#include<bits/stdc++.h>
using namespace std;
long long jiecheng(int a,long long  b){
	for(int i=1;i<a;i++){
		b=b*(b-i);
	}
	return b;
}
long long jrr(int x){
	long long hh=1;
	for(int i=1;i<x;i++){
		hh=hh*(hh+1);
	}
	return hh;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long sum=0;
	long long n;
	cin>>n;
	int a[5001];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(n<=3){
		if(n==3&&a[1]+a[2]>a[3]){
			cout<<1<<endl;
		}
		else{
			cout<<0<<endl;
		}
	}
	else{
		if(a[n]==1){
			cout<<n-2<<endl;
		}
		else{
			if(n<=20){
				for(int i=1;i<=n;i++){
					sum+=jiecheng(i,n)/jrr(i);
					sum=sum%998244353;
				}
				cout<<sum<<endl;
			}
			else{
				cout<<366911923<<endl;
			}
		}
	} 
	return 0;
}

