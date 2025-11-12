#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000005];
bool abc(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	int q=a[0],w;
	sort(a,a+n*m,abc);
	for(int i=0;i<n*m;i++){
		if(a[i]==q){
			w=i;
		}
	}
	int y;
	if((w/n+1)%2==0){
		y=abs(w%n+1-n)+1;
	}else{
		y=w%n+1;
	}
	cout<<w/n+1<<' '<<y;
	return 0;
}
