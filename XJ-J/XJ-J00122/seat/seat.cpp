#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],w,o;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int l=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==l){
			l=i;
			break;
		}
	}
	int lie=l/n;
	if(l%n!=0){
		lie++;
	}
	o=lie*n;
	if(lie%2!=0){
		for(int i=n;i>=1;i--){
			if(o==l){
				cout<<lie<<" "<<i;
			}
			o--;
		}
	}
	else{
		for(int i=1;i<=n;i++){
			if(o==l){
				cout<<lie<<" "<<i;
			}
			o--;
		}
	}
	return 0;
} 
