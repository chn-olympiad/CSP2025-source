#include<iostream>
#include<algorithm>
using namespace std;
char c[5010];
int a[5010];
long long px(int n){
	int a1=1;
	if(n==1) return 1;
	return (n*px(n-1))%998244353;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,f=0;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>c[i];
	}
	if(m==1){
		int s;
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		sort(a,a+n);
		int i;
		for(i=0;i<n;i++){
			if(a[i]!=0) break;
		}
		n-=i;
		cout<<px(n);
		return 0;
	}
	return 0;
}
