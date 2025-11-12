#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
int n,m,cnt,w,q;
int main(){
	cin>>n>>m;
	int p=n*m;
	int a[p];
	for(int i=0;i<p;i++){
		cin>>a[i];
	}
	int q=a[0];
	sort(a,a+p);
	
	cnt=(q/n+1)%2
	w=q%n
	return 0;
}
