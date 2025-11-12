#include<bits/stdc++.h>
using namespace std;
long long n,m,p,r;
int a[10001];
int s[16][16];
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
	r=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			s[i][j]=a[p];
			p++;
			if(a[p]==r){
			cout<<i<<" "<<j;
				return 0;
			}
		}
	}
	
	return 0;
}
