#include<bits/stdc++.h>
using namespace std;
const int N=5005;
int a[N];
int cnt=0;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	} 
	sort(a+1,a+n+1,cmp);
	if(n==3){
		int sumx=a[1]+a[2]+a[3];
		if(sumx>a[1]*2){
			cout << 1;
		}else{
			cout << 0;
		}
	} 
	return 0;
} 
