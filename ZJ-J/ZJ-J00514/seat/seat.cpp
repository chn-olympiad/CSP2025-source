#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;
int a[N];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	int cnt=a[1];
	sort(a+1,a+n*m+1,cmp);
	int k;
	for(k=1;k<=n*m;k++){
		if(a[k]==cnt) break;
	}
	int x=1,y=1;
	bool odd=1;
	for(int i=1;i<=n*m;i++){
		if(i==k){
			cout<<y<<' '<<x;
			return 0;
		}
		
		if(x==1 and !odd){
			y++,odd^=1;	
		}else if(x==n and odd){
			y++,odd^=1;
		}else{
			if(odd) x++;
			else x--;
		}
	}
	return 0;
}