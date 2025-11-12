#include<bits/stdc++.h>
using namespace std;
int a[10001];
int main(){
	int n,m,k,a,b;
	int w;
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	a=n;
	while(n--){
		cin>>a;
		for(int i=1;i<=n;i++){
			cin>>k;
		}
		if(w==0){
			a--;
			k--;
			if(k==0){
				a--;
			}
		}
	}
	cout<<a;
	return 0;
} 
