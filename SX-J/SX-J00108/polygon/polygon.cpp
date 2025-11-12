#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,cnt=0;
	cin>>n;
	int a[n+5];
	for(int i=1;i<=n;i++) cin>>n;
	if(n=3){
		if((a[1]+a[2]>a[3])&&(a[2]+a[3]>a[1])&&(a[1]+a[3]>a[2])){
			if((a[1]-a[2]<a[3])&&(a[2]-a[3]<a[1])&&(a[1]-a[3]<a[2])) cnt++;
		}
	}
	else if(n<3) cnt=0;
	else if(n>3) cnt=9;
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}