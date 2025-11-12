#include <bits/stdc++.h>
using namespace std;
int n,m,a[105];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int s=n*m,l,k,o,p;
	for(int i=1;i<=s;i++){
		cin>>a[i];
	}
	l=a[1];
	sort(a+1,a+s+1,cmp);
	for(int i=1;i<=s;i++){
		if(a[i]==l){
			k=i;
			break;
		}
	}
	o=k/n;
	if((k%n)!=0){
		o++;
		if(o%2){
			p=k%n;
		}
		else{
			p=n-k%n+1;
		}
	}else{
		if(o%2){
			p=1;
		}
		else{
			p=n;
		}
	}
	cout<<o<<" "<<p;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
