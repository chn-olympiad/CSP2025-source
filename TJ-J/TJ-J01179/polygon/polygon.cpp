#include<bits/stdc++.h>
using namespace std;
long long a[10010],n,cnt=0,sl=3,tmp1=1;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	while(sl++&&sl<=n){
		for(int i=1;i<=n;i++){
			if((a[i]+a[i+1]+a[i+2]+a[i+3])*2>max(max(a[i],max(a[i+1],a[i+2])),a[i+3])) cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
