#include<bits/stdc++.h>
using namespace std;
const int maxn=1000;
int n,m,a[maxn],sum,cnt,x,y;
bool cmp(int b,int c){
	return b>c;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie();
	cout.tie();
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	sum=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==sum){
			cnt=i;
			break;
		}
	}
	x=(cnt-1)/n+1;
	if(x%2==0){
		cnt-=(x-1)*n;
		y=n+1-cnt;
	}
	else{
		cnt-=(x-1)*n;
		y=cnt;
	}
	cout<<x<<" "<<y;
	return 0;
}
