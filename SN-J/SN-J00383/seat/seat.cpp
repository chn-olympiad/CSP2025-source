//SN-J00383 西安高新第二初级中学 初一 张源朔 
#include<bits/stdc++.h>

using namespace std;

long long n,m,a[1005]={},x=0,y=0,ans1=0,ans2=0;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	x=a[0];
	sort(a,a+n*m);
	for(int i=0;i<n*m;i++){
		if(a[i]==x){
			y=i;
			break;
		}
	}
	y=n*m-y-1;
	ans1=(y/n)+1;
	if((y/n)%2==0){
		ans2=y%n+1;
	}
	else{
		ans2=n-(y%n);
	}
	cout<<ans1<<" "<<ans2;
	return 0;
}
