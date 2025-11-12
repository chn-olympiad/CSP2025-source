#include<bits/stdc++.h>
using namespace std;
const int mod=998224353;
int n;
int a[5005];
long long s[5005];
long long num;
bool cmp(int a,int b){
	if(a>b){
		return 1;
	}
	else return 0;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n==3){
		cin>>a[1]>>a[2]>>a[3];
		sort(a+1,a+4);
		if(a[1]+a[2]+a[3]>2*a[3]){
			cout<<1;
		}
		else cout<<0;
		return 0; 
	}
	return 0;
}
