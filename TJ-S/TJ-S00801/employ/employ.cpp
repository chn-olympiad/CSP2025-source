#include<bits/stdc++.h>
using namespace std;
long long n,m,i,x,y,z,j,k,l,o,p,c;
int a[10010];
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	if(n==m){
		if(a[0]==0&&a[1]==0){
			cout<<0;
			return 0;
		}
		cout<<1;
		return 0;
	}
	if(m==1){
		c=0;
		for(i=0;i<n;i++){
			if(a[i]!=0){
				c++;
			}
		}
		if(c!=n){
			cout<<c+1;
			return 0;
		}else{
			cout<<c;
			return 0;
		}
	}
	cout<<0;
	return 0;
}
