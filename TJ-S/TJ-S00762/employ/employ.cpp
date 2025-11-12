#include <bits/stdc++.h>
using namespace std;
int n,m,sum;
int c[100005];
char a[100005];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]=='1'){
			sum++;
		}
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	if(n==m){
		for(int i=1;i<=n;i++){
			if(a[i]=='0'){
				cout<<0<<endl;
				return 0;
			}
		}
		cout<<1<<endl;
	}else{
		if(sum==n){
			long long r=1;
			for(int i=1;i<=n;i++){
				r*=i;
				r%=998244353;
			}
			cout<<r;
			return 0;	
		}
		if(sum<=m){
			cout<<0<<endl;
			return 0;
		}
	 	long long r=1;
		for(int i=1;i<=n;i++){
			r*=i;
			r%=998244353;
		}
		cout<<r;
	}
	return 0;
} 
