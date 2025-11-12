#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
const int N=1e5+5;
int a[N];
int main() {
//	freopen("seat.in","r",stdin);
//	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;++i){
		cin>>a[i];
	}
	int b=a[1];
	for(int i=2;i<=n*m;++i){
		if(a[i]>a[i-1]){
			int s=a[i-1];
			a[i-1]=a[i];
			a[i]=s;
		}
	}
	for(int i=2;i<=n*m;++i){
		if(a[i]==b){
			if(i>m){
    			cout<<(i/m)+1<<" "<<i-n;
			}else{
				cout<<"1"<<" "<<i;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}