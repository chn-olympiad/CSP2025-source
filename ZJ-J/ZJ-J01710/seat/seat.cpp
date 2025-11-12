#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;
int a[1010],id;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int num=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==num){
			id=i;
			break;
		}
	}
	int f=0;
	int t=1;
	int x,y;
	x=1,y=1;
	while(t<=n*m){
		if(!f){
			while(x<=n&&t<=n*m){
				if(t==id){
					cout<<y<<' '<<x;
					return 0;
				}
				x++;
				t++;
			}
			x--;
			y++;
		}else{
			while(x>=1&&t<=n*m){
				if(t==id){
					cout<<y<<' '<<x;
					return 0;
				}
				x--;
				t++;
			}
			x++,y++;
		}
		f^=1;
//		cout<<f<<' '<<t<<endl;
	}
	return 0;
}