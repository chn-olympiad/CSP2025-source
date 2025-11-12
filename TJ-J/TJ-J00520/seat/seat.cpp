#include<bits/stdc++.h>
using namespace std;
long long int n,m;
long long int a[105];
bool cmp(int x,int y){
	return x,y;
}
int l=0,h=0;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]<=a[n]){
			l+=1;
			h+=i;
		}
	}
	cout<<l<<h;
	return 0;
}
