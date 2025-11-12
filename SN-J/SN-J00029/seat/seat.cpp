//SN-J00029  任奕天  西安辅轮中学 
#include<bits/stdc++.h>
using namespace std;
int b[200];
int a[15][15];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>b[i];
	}
	int s=b[1],x;
	sort(b+1,b+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(b[i]==s){
			x=i;
		}
		break;
	}
	int c=x/m;
	if(x%m==0){
		if(c%2==0){
			cout<<c<<' '<<1;
		}else if(c%2!=0){
			cout<<x/m<<' '<<n;
		}
	}else{
		if((c+1)%2==0){
			cout<<c+1<<' '<<n-x%m+1;
		}else if((c+1)%2!=0){
			cout<<c+1<<' '<<x%m;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

