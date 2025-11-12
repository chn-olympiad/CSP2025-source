#include<bits/stdc++.h>
using namespace std;
#define FI(x) freopen(x".in","r",stdin);
#define FO(x) freopen(x".out","w",stdout);
int n,a[10005],maxn,h,s;
void DFS(int x,int manx,int hx,int l,int b){
//	cout<<x<<" "<<manx<<" "<<hx<<" "<<l<<" "<<b<<"\n";
	if(l==b){
		if(hx>manx*2){
			s++;
		}
		return;
	}
	for(int i=x+1;i<=n-(b-l)+1;i++){
		DFS(i,max(manx,a[i]),hx+a[i],l+1,b);
	}
}
int main(){
	FI("polygon");
	FO("polygon");
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		h+=a[i];
		maxn=max(a[i],maxn);
	}
	if(n<3){
		cout<<0;
		return 0;
	}
	if(n==3){
		if(h>maxn*2){
			cout<<1;
		}else{
			cout<<0;
		}
	}else{
		for(int i=3;i<=n;i++){
			for(int j=1;j<=n-i+1;j++){
				DFS(j,a[j],a[j],1,i);
			}
		}
		cout<<s;
	}
	return 0;
}
