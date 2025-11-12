#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[105];
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>m>>n;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	int r=a[0];
	for(int i=0;i<n*m;i++){
		for(int j=i+1;j<n*m;j++){
			if(a[i]<a[j]) swap(a[i],a[j]);
		}
	}
	int k=0;
	for(int i=0;i<n*m;i++){
		if(a[i]==r){
			k=i+1;
			break;
		}
	}
	int h=k%m;
	int q=(k-h)/m+1;
	if(k<=m){
		cout<<1<<' '<<k;
		return 0;
	}else{
		if(q%2==0){
			cout<<q<<' '<<n-(h-1);
			return 0;
		}
		if(q%2==1){
			cout<<q<<' '<<h;
			return 0;
		}
	}
	
	return 0;
} 
