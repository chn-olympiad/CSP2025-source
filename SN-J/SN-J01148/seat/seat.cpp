#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	long long s[105],j=n*m;
	for(int i=1;i<=j;i++){
		cin>>s[i];
	}
	int a=s[1],b[10],g,x=1;
	sort(s+1,s+j+1);
	for(int i=j;i>=1;i--){
		b[x]=s[i];
		x++;
	}
	for(int i=1;i<=j;i++){
		if(a==b[i]){
			g=i;
		}
	}
	if(g<=m){
		cout<<"1"<<" "<<g;
	}
	long long y=g%m,h=g/m;;
	if(g>m){
		if(y==0){
			cout<<h<<" "<<h;
		}else{
			cout<<h+1<<" "<<y;
		}
	}
}
