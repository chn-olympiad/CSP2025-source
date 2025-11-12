#include<bits/stdc++.h>
using namespace std;
int a[11][11],b[101];
bool f(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;++i){
		cin>>b[i];
	}
	int r=b[0],rt=0;
	sort(b,b+n*m-1,f);
	for(int i=0;i<n*m;++i){
		if(b[i]==r){
			rt=i;
		}
	}
	long long ansx=0,ansy=0;
	ansx=rt/n;
	if(ansx%2==0){
		ansy=rt%n;
	}
	else{
		ansy=m-rt%n;
	}
	cout<<ansx+1<<" "<<ansy+1;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
