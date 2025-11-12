#include<bits/stdc++.h>
using namespace std;
long long a[105][105],n,m,num[10005],w,k;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	k=n*m;
	for(long long i=1;i<=k;i++){
		cin>>num[i];
	}
	long long s=num[1];
	sort(num,num+k+1);
	for(int i=1;i<=k;i++){
		if(num[i]==s){
			w=k-i+1;
			break;
		}
	}
//	cout<<w<<endl;
	long long c=ceil(w*1.0/n);
	long long r=w%n;
	if(c%2==1){
		if(r==0){
			cout<<c<<" "<<n;
			return 0;
		}
		cout<<c<<" "<<r;
	}
	else{
		if(r==0){
			cout<<c<<" "<<1;
			return 0;
		}
		cout<<c<<" "<<n-r+1;
	}
}
