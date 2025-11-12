#include<bits/stdc++.h>
using namespace std;
int n,m,s[205],a,flag1,flag2,x,y;
bool cmp(int x,int y){
	return x>y;
}
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>s[i];
	}
	a=s[1];
	sort(s+1,s+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(s[i]==a){
			a=i;
			break;
		}
	}
	flag1=a/(2*n);
	flag2=a%(2*n);
	if(!flag2){
		flag2=8;
	}
	x=2*flag1+1;
	if(flag2>n){
		x++;
		y=2*n-flag2+1;
	}else{
		y=flag2;
	}
	cout<<x<<" "<<y;
	return 0;
}
