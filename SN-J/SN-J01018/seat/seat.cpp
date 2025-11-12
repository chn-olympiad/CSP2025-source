//SN-J01018  赵晗羽  西安辅轮中学 
#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[105],s,x=1,y=1;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	int t=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)if(a[i]==t)s=i;
	for(int i=1;i<=m;i++){
		if(i*n>=s){
			y=i;
			break;
		}
	}
	if(y%2){
		x=s-(y-1)*n;
	}else{
		x=n-(s-(y-1)*n)+1;
	}
	cout<<y<<" "<<x;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
