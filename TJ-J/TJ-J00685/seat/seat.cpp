#include <bits/stdc++.h>
using namespace std;
int n;int top;
int m,a[1000],c;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n>>m;
	for (int i = 1; i<= n*m; i++){
			cin >>a[i];
			if (i==1){c=a[i];}
	}
	sort(a+1,a+n*m+1,cmp);
	for (int i = 1; i<= n*m; i++){
		if (a[i]==c){
			c=i;
			break;
		}
	}
	int v=c%m;
	int h=c/m;
	if (v)h++;
	if (!v)v++;
	if (h%2){
		cout <<h<<" "<<v;
	}else{
	cout <<h<<" "<<m+1-v;
}

	return 0;
} 
