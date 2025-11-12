#include<bits/stdc++.h>
using namespace std;
int a[1005];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n >> m;
	int t,w;
	for(int i = 1;i <= n*m;i++){
		cin >> a[i];
	}
	t = a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i = 1;i <= n*m;i++){
		if(a[i] == t){
			w = i;
			break;
		}
	}
	int r = w%2;
	int c = 0;
	if(w/2%2 == 0){
		c = w/2+1;
	}else{
		c = w/2;
	}
	if(r == 0){
		r = n;
		c--;
	}
	if(c%2 == 0){
		cout << c <<" "<< n+1-r;
	}else{
		cout << c <<" "<< r;
	}
}
