#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int n,m,a[200],x;
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	x=a[0];
	sort(a,a+n*m,cmp);
	for(int i=0;i<n*m;i++){
		if(a[i]==x){
			cout<<i/n+1<<" ";
			if((i/n+1)%2==0){
				cout<<n-i%n;
			}
			else cout<<i%n+1;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

