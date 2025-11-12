#include<bits/stdc++.h>
using namespace std;

const int N=100+20;
int a[N];
int n,m;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int c=0,suml=0,sumr=0;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1){
			c=a[1];
		}else{
			if(a[i]<c){
				sumr+=1;
			}else{
				suml+=1;
			}
		}
	}
	int i=suml+1;
	int x=i%n;
	int y=i/n;
	if(x==0){
		if(y%2==1){
			cout<<y<<' '<<n;
		}else{
			cout<<y<<' '<<1;
		}
		return 0;
	}
	if(y%2==1){
		cout<<y+1<<' '<<n-x+1;
	}else{
		cout<<y+1<<' '<<x;
	}
	return 0;
}
