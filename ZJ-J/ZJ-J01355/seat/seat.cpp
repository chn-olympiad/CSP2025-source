#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],R,v;
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
	R=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==R){
			int l=i/n+(i%n!=0),h=i%n;
			cout<<l<<" ";
			if(l%2==1){
				if(h==0) cout<<n;
				else cout<<h;
			}
			else{
				if(h==0) cout<<1;
				else cout<<n-h+1;
			}
			break;
		}
	}
	cout<<endl;
	return 0;
}

