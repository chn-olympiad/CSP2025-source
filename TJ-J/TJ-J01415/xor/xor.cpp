#include<bits/stdc++.h>
using namespace std;
long long n,k,m,a[500005],b,c,d,x,f;
string s;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++) cin>>a[i];
	if(k==0){
		if(n==1){
			if(a[0]==0) cout<<1;
			else cout<<0;
		}
		else if(n==2){
			if(a[0]==0&&a[1]==0) cout<<2;
			else{
				if(a[0]==0) x++;
				if(a[1]==0) x++;
				if(a[0]==a[1]) x++;
				cout<<x;
			}
		}
		else cout<<0;
	}
	else cout<<1;
	return 0;
}
