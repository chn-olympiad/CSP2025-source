#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],f[15][15];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int t=n*m;
	for(int i=1;i<=t;i++){
		cin>>a[i];
	}
	int ans=a[1];
	sort(a+1,a+t+1,cmp);
	int x=1,y=1,cnt=0;
	while(true){
		f[x][y]=a[++cnt];
		if(f[x][y]==ans){
			cout<<y<<" "<<x;
			break;
		}
		if(y%2==1){
			if(x==n) y++;
			else x++;
		}else{
			if(x==1) y++;
			else x--;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
