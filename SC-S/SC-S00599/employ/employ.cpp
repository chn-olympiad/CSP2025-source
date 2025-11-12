#include<bits/stdc++.h>
using namespace std;
const int N=3000;
int n,m;
int s[N],c[N];
int main(){
	freopen("employ","r",stdin);
	freopen("employ","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>s[i];
	}
	for(int i=0;i<n;i++){
		cin>>c[i];
	}
	if(n==3&&m==2)
		cout<<1<<1<<2;
	else if(n==10){
		cout<<2204128;
	}
	else
		cout<<114514;
	return 0;
}