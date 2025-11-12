#include<bits/stdc++.h>
using namespace std;
const int N=10e7+5;
int sum[N],n=0;
bool k(int a,int b){
	return a>=b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	for(int i=0;i<a.length();i++){
		if(a[i]>='0'&&a[i]<='9') {
			sum[++n]=a[i]-'0';
		}
	}
	sort(sum+1,sum+n+1,k);
	for(int i=1;i<=n;i++) cout<<sum[i];
	return 0;	
}