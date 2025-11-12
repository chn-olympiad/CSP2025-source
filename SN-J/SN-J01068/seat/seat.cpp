#include <bits/stdc++.h>
using namespace std;
int s[9999];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>s[i];
	}
	int r=s[1];
	sort(s+1,s+1+n*m);
	int q[9999];
	for(int i=n*m;i>=1;i--){
		q[i]=s[i];
		if(r==q[i]){
			r=i+1;
		}
	}
	int num=1;
	for(int i=1;i<=r/n+1;i++){
		if(num%2==1){
			r-=n;
			num++;
		if(r<n){
			break;
		}	
		if(num%2==0){
			r=n;
			num++;
		}
		}
	}
	if(r==0){
		r+=1;
	}
	cout<<num<<' '<<r;
}
