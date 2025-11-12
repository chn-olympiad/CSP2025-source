#include<bits/stdc++.h>
using namespace std;
int a[5005],ans,n;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	if(n==3&&a[0]+a[1]+a[2]>max(max(a[0],a[1]),a[2])*2){
		cout<<1;
	}
	else{
		cout<<0;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
