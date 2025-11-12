#include<bits/stdc++.h>
using namespace std;
int n,a[5050];
int pd(int x[]){
	int sum,maxn=-1;
	for(int i=1;i<=n;i++){
		max(maxn,x[i]);
		if(x[i]==0){
			i++;
		}
		sum=sum+x[i];
	}
	if(sum>2*maxn) return 1;
	return 0;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	cout<<pd(a);
	return 0;
}
