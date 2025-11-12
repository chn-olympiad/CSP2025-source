#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
using namespace std;
int a[505];
long long cmp(long long n){
	if(n<=1){
		return 1;
	}return n*cmp(n-1)%998244353;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
int n,m;
cin>>n>>m;
string s;
cin>>s;
int sum=0;
for(int i=0;i<n;i++){
	cin>>a[i];
	if(a[i]==0){
		sum++;
	}
}
	cout<<cmp(n-sum)%998244353;
	return 0; 
} 
