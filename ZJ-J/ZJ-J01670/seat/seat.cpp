#include<bits/stdc++.h>
using namespace std;
const int N=100+5;
int n,m,a[N];
int mp[N][N];
int x=1,y=1;//×ø±ê 
int endx,endy;//½áÊø 
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	int past=a[1];
	sort(a+1,a+n*m+1,cmp);
	//µØÍ¼ 
	if(m%2==0) endx=1,endy=m;
	else endx=n,endy=m;
	int cnt=1;
	while(x!=endx||y!=endy){
		if(a[cnt]==past) break;
		mp[x][y]=a[cnt++];
		if(x==n&&y%2==1) y++;
		else if(x==1&&y%2==0) y++;
		else if(y%2==1) x++;
		else x--;
	}
	cout<<y<<" "<<x<<"\n";
	fclose(stdin);
	fclose(stdout);
	return 0;
}
