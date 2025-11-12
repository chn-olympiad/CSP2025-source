#include<iostream>
#include<cstdio>
using namespace std;
int n,m,a[505],c[505],k,ans;
string s;
bool b[505];
void f(int x){
	if(x>=n){
		k=0;
		for(int i=0,j=0;i<n;i++){
			if(s[i]=='0'||a[c[i]]<=j)j++;
			else k++;
		}
		ans=(ans+(k>=m))%998244353;
		return;
	}
	for(int i=0;i<n;i++){
		if(!b[i]){
			c[x]=i,b[i]=1;
			f(x+1);
			b[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=0;i<n;i++)cin>>a[i];
	f(0);
	cout<<ans;
	return 0;
}
