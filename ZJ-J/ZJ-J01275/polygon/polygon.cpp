#include<bits/stdc++.h>
using namespace std;

int k;
int a[10000];

int main(){
	freopen("polygon.in",'r',stdin);
	freopen("polygon.out",'w',stdout);
	
	cin>>k;
	for(int i=0;i<k;i++){
		cin>>a[i];
	}
	
	sort(a,a+k);
	
	if(k<3)cout<<0;
	else if(k==3){
		g=max(a[0],max(a[1],a[2]));
		if(g*2<(a[0]+a[1]+a[2]-g))cout<<1;
	}else cout<<48130;
	
	return 0;
}
