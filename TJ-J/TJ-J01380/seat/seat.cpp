#include<bits/stdc++.h>
using namespace std;
int c[100005];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int a,b;
	cin>>a>>b;
	int f=a*b;
	cin>>c[0];
	int g=c[0],h=0;
	for(int i=1;i<f;i++){
		cin>>c[i];
	}
	sort(c,c+f);
	for(int i=f-1;i>=0;i--){
		h++;
		if(g==c[i]){
			break;
		}
	}
	int x=h/b+1,y=h%b;
	if(y==0){
		y=b;
	}
	cout<<x<<" "<<y;
	return 0;
}
