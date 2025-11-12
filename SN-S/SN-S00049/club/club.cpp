#include <bits/stdc++.h>
using namespace std;
int t,a[10000],b[10000],c[10000],n,L=0,m;
void club(int l,int k,int a1,int b1,int c1){
	if(a1>m||b1>m||c1>m){
		return;
	}else if(k==n){
		L=max(L,l);
		return;
	}
	club(l+a[k],k+1,a1+1,b1,c1);
	club(l+b[k],k+1,a1,b1+1,c1);
	club(l+c[k],k+1,a1,b1,c1+1);
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	for(int o=0;o<t;o++){
		cin>>n;m=n/2;
		for(int i=0;i<n;i++){
			cin>>a[i]>>b[i]>>c[i];
		}
		club(0,0,0,0,0);
		printf("%d\n",L);
		L=0;
	}
	return 0;
} 
