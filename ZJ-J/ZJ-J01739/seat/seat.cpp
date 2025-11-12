#include<bits/stdc++.h>
using namespace std;
int n,m,x,y;
struct seatt{
	int c;
	int ui;
	bool operator<(const seatt tmp)const{
	      return tmp.c<c;
	}
}a[1005];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].c;
		a[i].ui=i;
	}
	sort(a+1,a+1+n*m);
	x=1;y=1;
	for(int i=1;i<=n*m;i++){
		if(a[i].ui==1){
			cout<<y<<" "<<x;
			return 0;
		}
		if(x==n&&y%2==1){
           y++;
		   continue;			
		}
		if(x==1&&y%2==0){
			y++;
			continue;
		}
		if(y%2==0){
			x--;
		}
		else{
			x++;
		}
	}
	return 0;
}
