#include<bits/stdc++.h>
using namespace std;

int a[105]={},fen,pai,l;
bool cmp(int a,int b){
	if(a<b) return a>b;
	else return a>b;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	l=n*m;
	for(int i=0;i<=l-1;i++){
		cin>>a[i];
	}
	fen=a[0];
	sort(a,a+l,cmp);
	for(int i=0;i<=l-1;i++){
		if(a[i]==fen){
			pai=i+1;
			break;
		}
	}
	int anh,anl;
	if(pai%n!=0){
		anl=pai/n+1;	
	}else{
		anl=pai/n;
	}
	if(anl%2!=0){
		anh=pai%n;
		if(anh==0){
			anh=n;
		}
	}else{
		anh=n-pai%n+1;
		if(anh==n+1){
			anh=1;
		}
	}
	cout<<anl<<" "<<anh;
	
	return 0;
}
