#include<bits/stdc++.h> 
using namespace std;
int a[15][15],b[205];
int n,m;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	int x=n*m;
	for(int i=1;i<=x;i++){
		cin>>b[i];
	}
	int l=b[1];
	sort(b,b+x);
	for(int i=1;i<=x;i++){
		if(b[i]==l){
			l=i;
			break;
		}
	}
	int ansx,ansy;
	ansx=l/n+1;
	ansy=l%n;
	if(ansy==0) ansx--,ansy=n;
	if(ansx%2==0) ansy=n-ansy+1;
	cout<<ansx<<' '<<ansy;
	return 0;
}
