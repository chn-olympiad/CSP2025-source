#include<bits/stdc++.h>
using namespace std;
long long cj[1000005];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>cj[i];
	}
	long long r=cj[1];
	long long h=0,rwz;
	sort(cj+1,cj+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(r==cj[i]){
			rwz=i;
			break;
		}
	}
	int l=1;
	h=rwz%n;
	if(rwz>n){
		if(h!=0){
			l=(rwz-h)/n+1;
		}else{
			l=(rwz-h)/n;
		}
	}
	cout<<l<<" ";
	if(l%2!=0){
		if(h==0){
			cout<<n;
		}else{
			cout<<h;
		}
	}else if(l%2==0){
		if(h==0){
			cout<<1;
		}else{
			cout<<n-h+1;
		}
	}
	return 0;
}
