#include<bits/stdc++.h>
using namespace std;
long long a[110];
bool cmp(long long a,long long b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,w=0;
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
		if(!i) w=a[i];
	}
	sort(a,a+m*n,cmp);
	for(int i=0;i<n*m;i++){
		if(w==a[i]){
			w=i;
			break;
		}
	}
	int lie=w/n+1;
	int hang;
	if(lie&1) hang=w+1-(lie-1)*n;
	else hang=lie*n-w;
	cout<<lie<<" "<<hang;
	return 0;
}
