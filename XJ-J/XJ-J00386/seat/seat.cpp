#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	int a[200];
	int x,k;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1){
			x=a[i];
		}
	}
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==x){
			k=i;
		}
	}
	int l=k/n;
	if(k%n>0){
		l++;
	}
	int h=k%(n*2);
	if(h>n){
		h=n-(h-n)+1;
	}else if(h==0){
		h=n;
	}
	cout<<l<<" "<<h;
	return 0;
}
