#include<bits/stdc++.h>
using namespace std;
int cmp(int s,int r){
	return s>r;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n;
	cin>>m>>n;
	int a[m*n+5];
	int sum;
	for(int i=1;i<=m*n;i++){
		cin>>a[i];
	}
	sum=a[1];
	sort(a+1,a+m*n+1,cmp);
	int js=0;
	for(int i=1;i<=m*n;i++){
		if(a[i]==sum){
			js=i;
		}
	}
	int x,y;
	if(js<m){
		cout<<1<<' '<<js;
		return 0;
	}
	if(js%m==0){
		if(js/m%2==0){
			cout<<js/m<<' '<<1;
		}else{
			cout<<js/m<<' '<<m;
		}
		return 0;
	}
	if((js/m+1)%2!=0){
		cout<<js/m+1<<' '<<js%m;
	}else{
		cout<<js/m+1<<' '<<m-(js%m)+1;
	}
return 0;
} 
