#include<bits/stdc++.h>
using namespace std;
int n,m,xx,poss,x,y;
int a[110];
bool p;
void youhua(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
bool cmp(int x,int y){
	return x>y;
}
int main(){
	youhua();
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>a[i];
	xx=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
		if(a[i]==xx){
			poss=i;
			break;
		}
	x=1;y=1;
	p=true;
	//p表示排的方向
	//p为true表示是从上到下
	//p为false表示是从下到上 
	for(int i=2;i<=poss;i++){
		if(x==n&&p==true){
			y++; 
			p=false;
		}
		else if(x==1&&p==false){
			y++;
			p=true;
		}
		else{
			if(p==true) x++;
			else x--;
		}
		//第i层循环结束时 
		//x,y表示第i个人的坐标 
	}
	cout<<y<<" "<<x;
	return 0;
}
//全部都过了
//rp++ 
