#include<bits/stdc++.h>
using namespace std;
const int N=1100;
int a[N];
bool cmp(int o,int u){
	return o>u;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int k=a[1];
	sort(a+1,a+n*m+1,cmp);
	int p=1;
	int x=1,y=1;
	while(1){
		while(x<=n){
			if(a[p]==k){
				cout<<y<<" "<<x;
				return 0;
			}
			p++;
			x++;
		}
		x--;
		y++;
		while(x>=1){
			if(a[p]==k){
				cout<<y<<" "<<x;
				return 0;
			}
			p++;
			x--;
		}
		x++;
		y++;
	} 
	return 0;
}
