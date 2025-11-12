#include <bits/stdc++.h>
using namespace std;
int a[105];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,face=1,xm=0;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	xm=a[1];
	sort(a+1,a+1+n*m);
	int place=n*m,j=1;
	for(int i=1;place>=1;){
		if(a[place]==xm){
			cout<<i<<" "<<j<<endl;
			break;
		}
		if(j+face!=m+1 && j+face!=0){
			j+=face;
		}else{
			i++;
			face=0-face;
		}
		place--;
	}
	return 0;
}
