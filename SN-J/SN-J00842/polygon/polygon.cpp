#include<bits/stdc++.h>
using namespace std;
long long n,ji=0,mo=998244353;
long long a[10000]={};
map<int,int>M;
//bool cmd(int x,int y){
//	return x>y;
//}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >>n;
	for(int i=1;i<=n;i++){
		cin >>a[i];
	}
	if(n<3){
		cout <<0;
		return 0;
	}
	else{
		if((a[1]+a[2])<=a[3] || (a[1]+a[3])<=a[2] || (a[2]+a[3])<=a[1]){
			cout <<0;
		}
		else{
			cout <<1;
		}
	}
	return 0;
}
