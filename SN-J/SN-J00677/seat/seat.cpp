//DuanChencheng's code
//number:SN-J00677
#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int n,m,a[15*15],ans1,ans2;
int seat[15][15];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	int pos=a[1];
	sort(a+1,a+n*m+1,cmp);
	int val=0;
	for(int i=1;i<=n*m;i++){
		if(a[i]==pos){
			val=i;
			break;
		}
	}
//	cout<<"\n\n\n";
	int x=1,y=1,cnt=0;
	while(cnt<=n*m){
		seat[x][y]=a[++cnt];
		if(seat[x][y]==pos){
			cout<<y<<' '<<x;
			break;
		}
		if(y%2==1){
			x++;
			if(x==n+1) x=n,y++;
		}else{
			x--;
			if(x==0) x=1,y++;
		}
	}
	return 0;
}
