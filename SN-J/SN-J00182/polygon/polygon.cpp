//吕昊霖-SN-J00182-西安市曲江第二中学 
#include<bits/stdc++.h>
using namespace std;
int n,a[10000],s,b[5006];
long long f(int l,int n){
	int j=1;
	if(x==1){
		for(int i=1;i<=n;i++){
			
		}
	}
	for(int i=l;i<=n;i++){
		b[i]=i+f(i+1,n-1);
		j++;
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=3;i<=n-2;i++){
		cout<<f(1,i);
	}
	return 0;
} 
