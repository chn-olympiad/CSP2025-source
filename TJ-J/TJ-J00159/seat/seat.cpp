#include<bits/stdc++.h>//seat
using namespace std;
int c[105];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout); 
	int n,m,nm;
	cin>>n>>m;
	nm=n*m;
	for(int i=1;i<=nm;i++){
		cin>>c[i];
	}
	int cr=c[1],ci;
	sort(c+1,c+1+nm,cmp);
	for(int i=1;i<=nm;i++){
		if(c[i]==cr) ci=i;
	}
	int l,h;
	int cnt=ci%n,cntt=ci/n;
	if(cnt==0)l=cntt;
	else l=cntt+1;
	
	if(l%2==1){//ji
		if(ci%n==0) h=n;
		else h=cnt;
	}
	else {
		if(ci%n==0) h=n;
		else h=n-cnt+1;
	}
	cout<<l<<' '<<h;
	return 0;
}/*5 4
14 19 3 4 5 6 7 8 9 10 11 12 13 2 15 16 17 18 1 20
 */
