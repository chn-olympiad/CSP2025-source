#include<bits/stdc++.h>
using namespace std;
const int N=1005;
int a[N];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int s;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	s=a[1];
	sort(a+1,a+n*m+1,cmp );
	int w;
	for(int i=1;i<=n*m;i++){
		if(s==a[i]){
			w=i;
			break;
			
		}
	}
	int h;
	if(w%(n*2)>n){
		h=w/(2*n)*2+2;
		w%=(2*n);
		w-=n;
		w=n-w+1;
	}
	else if(w%(n*2)==0){
		h=w/(n*2)*2;
		w=1;
	}
	else{
		h=w/(n*2)*2+1;
		w%=(2*n);
	}
	cout<<h<<" "<<w;
	return 0;
}
