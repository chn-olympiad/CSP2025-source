#include<bits/stdc++.h>
using namespace std;
int a[1000], n, m, cnt, fl;
bool cmp(int x, int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	cnt=a[1];
	sort(a+1,a+1+n*m,cmp);
	int x=1, y=1, pos=1;
	while(1){
		if(a[pos]==cnt){
			cout<<y<<" "<<x;
			return 0;
		}
		if(!(fl%2)){
			x++;
			if(x>n)x=n,y++,fl++;
		}
		else{
			x--;
			if(x<1)x=1,y++,fl++;
		}
		pos++;
	}
	return 0;
} 
