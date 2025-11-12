#include<bits/stdc++.h>
using namespace std;
const int N=15;

int a[N][N];
int s[N*N];
int tmp;
int n,m;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>s[i];
	}
	tmp=s[1];
	sort(s+1,s+n*m+1);
	int updown=1,x=1,y=1;//updown-1时向下，1向上
	if(s[n*m]==tmp){
		cout<<1<<" "<<1;
		return 0;
	}
	for(int i=n*m-1;i>=1;i--){
		if(updown==1&&x==n){
			y++;
			updown=-1;
		}
		else if(updown==-1&&x==1){
			y++;
			updown=1;
		}
		else {
			x+=updown;
		}
		if(s[i]==tmp){
			cout<<y<<" "<<x;
			return 0;
		}
	} 
	
	return 0;
}
