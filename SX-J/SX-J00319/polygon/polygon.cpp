#include<bits/stdc++.h>
using namespace std;
int a[110];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
	int m,cnt=0,ans=0;;
	cin>>m;
	for(int i=1;i<=m;i++){
		cin>>a[i];
		cnt+=a[i];
	}
	sort(a+1,a+1+m);
	if(cnt>2*a[m]){
		ans=1;
	}
	cout<<ans;
	return 0;
}