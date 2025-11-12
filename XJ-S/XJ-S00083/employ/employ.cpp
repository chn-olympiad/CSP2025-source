#include<bits/stdc++.h>
using namespace std;
int n,m,s1[1000],ans=1,c[1000];
char s[1000];
int jie(int x){
	if(x==1)return 1;
	return (x*jie(x-1))%998244353;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	int t=n;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	if(m==1){
		cout<<jie(n);
	}
	return 0;
}
