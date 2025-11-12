#include<bits/stdc++.h>
using namespace std;
const int maxn=205;
int n,m,a[maxn],k;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			k++;
			cin>>a[k];
		}
	}
	int x=a[1];
	sort(a+1,a+k+1,greater<int>());
	for(int i=1;i<=k;i++){
		if(x==a[i]){
			int c=(i-1)/n+1;
			int l;
			if(c%2==1) l=i-n*(c-1);
			else l=n-(i-n*(c-1))+1;
			cout<<c<<" "<<l<<"\n";
			break;
		}
	}
	return 0;
}
