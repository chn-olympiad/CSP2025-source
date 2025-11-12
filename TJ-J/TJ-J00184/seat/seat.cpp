#include<bits/stdc++.h>
using namespace std;//服了，8点半才开始12点整收卷，30分钟被吃了 
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,js=0,x=1,y=1;
	int a[1005];
	cin>>n>>m;
	memset(a,-1,sizeof(a));
	for(int i=0;i<n*m;i++)cin>>a[i];
	int r=a[0];
	sort(a,a+n*m);
	for(int i=n*m-1;i>=0;i--){
		if(a[i]==-1)continue;
		if(a[i]==r)break;
		if(js%2==0&&y<n)y++;
		else if(js%2==1&&y>1)y--;
		else if(js%2==0&&y>=n){
			x++;
			js++;
		}else if(js%2==1&&y<=1){
			x++;
			js++;
		}
	}
	cout<<x<<" "<<y;
	return 0;
}
