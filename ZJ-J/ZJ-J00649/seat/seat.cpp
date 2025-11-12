#include<bits/stdc++.h>
using namespace std;
int a[105],n,m,cnt,x=1,y=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		cnt+=(a[i]>a[1]);
	}
	while(cnt){
		cnt--;
		if((x==n&&y%2)||(x==1&&!(y%2)))y++;
		else if(y%2==1)x++;
		else x--;
	}
	cout<<y<<' '<<x;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
