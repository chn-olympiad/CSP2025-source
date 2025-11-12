#include<bits/stdc++.h>
using namespace std;
int a[100010];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int k=a[1];
	sort(a+1,a+n*m+1);
	int pos;
	for(int i=1;i<=n*m;i++){
		if(a[i]==k) pos=i;
	}
	pos=n*m-pos;
	int x=1,y=1,f=0;
	while(pos>0){
		if(f==0){
			if(x==n){
				f=1;
				y++;
			}else{
				x++;
			}
		}else{
			if(x==1){
				f=0;
				y++;
			}else{
				x--;
			}
		}
		pos--;
	}
	cout<<y<<" "<<x; 
	return 0;
} 
