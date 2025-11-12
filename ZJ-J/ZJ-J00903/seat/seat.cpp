#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int s[110];
bool f;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>s[i];
	for(int i=2;i<=n*m;i++)if(s[i]>s[1])k++;
	int x=1,y=1;
	while(k--){
		if(f)y--;	
		else y++;
		if(y<1)x++,y=1,f=0;
		else if(y>n)x++,y=n,f=1;
	}
	cout<<x<<" "<<y;
	return 0;
}
