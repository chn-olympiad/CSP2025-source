#include<bits/stdc++.h>
using namespace std;
int n,m,total=0;
int a[512];
int d[512];
bool f[512];
string str;
void fac(int l){
	if(l>n) {
		int sum=0,ans=0;
		for(int i=1;i<=n;i++) {
			if(str[i-1]=='0'||d[i]<=sum) sum++;
			else if(str[i-1]=='1'&&d[i]>sum) ans++;
		}			 
		if(ans>=m) total++;
	}
	for(int j=1;j<=n;j++) {
		if(f[j]==false){
			d[l]=a[j];
			f[j]=true;
			fac(l+1);
			f[j]=false;
		}	
	}	
}
int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;	
	cin>>str;
	for(int i=1;i<=n;i++) cin>>a[i];
	fac(1);
	cout<<total%998244353;
return 0;
}