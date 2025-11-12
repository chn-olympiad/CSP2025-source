#include<bits/stdc++.h>
using namespace std;
struct node{
	int x;
	int num;
};
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,a[5005]={0};
	long long q=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=n-1;i>=2;i--){
			q+=(i*(i-1)*(n-i))/2;
	}
	cout<<q; 
	return 0;
}
