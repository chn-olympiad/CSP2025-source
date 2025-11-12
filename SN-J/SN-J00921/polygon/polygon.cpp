#include<bits/stdc++.h>
using namespace std;
int c(int a,int b){
	int cnt=1,ant=1;
	for(int i=1;i<=a;i++){
		cnt*=b;
		b--;
	}
	for(;a!=0;){
		ant*=a;
		a--;
	}
	return cnt/ant;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int cnt=0;
	int n;
	cin>>n;
	for(int i=3;i<=n;i++){
		cnt+=c(i,n);
	}
	cout<<cnt;
	return 0;
}
