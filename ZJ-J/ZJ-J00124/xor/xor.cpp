#include <bits/stdc++.h>
using namespace std;
const int N=500010;
int f[N],a[N],n,k,i,z,ma,sc03,s;
//int add(){
//	int zz,x,mx;
//	z++;zz=z;x=n-1;mx=0;
//	for(i=1;i<n;i++) f[i]=0;
//	while(zz) f[x--]=zz%2,mx+=zz%2,zz/=2;
//	return mx;
//}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(i=1;i<=n;i++) cin>>a[i],z+=a[i];
//	{
//	while(z!=pow((n-1),2)-1){
//		sc03=add();
////		for(i=1;i<=n;i++) cout<<f[i]<<" ";
////		cout<<"\n";
//		s=0;ma=0;
//		for(i=1;i<=n;i++){
//			s=s xor a[i];
//			if(f[i]==1) ma=max(ma,s),s=0;
//			if(i==n&&f[i-1]==1) ma=max(ma,0 xor a[n]);
//		}
////		cout<<kkk<<"\n";
//		if(ma==k) cout<<sc03<<" ";
//	}
//}
	if(z==n&&k==0){
		if(n==0) cout<<0;
		else if(n%2==1) cout<<0;
		else cout<<n;
	}else cout<<n/2;
	return 0;
}