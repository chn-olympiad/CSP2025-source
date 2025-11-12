#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int n,m,jxj,sum=0;
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		int t;
		cin>>t;
		if(i==1){
			jxj=t;	
		}else if(t>jxj){
			sum++;
		}
	}
	sum+=1;
	int t1=(sum+n-1)/n;
	int t2=sum%n;
	cout<<t1<<" ";
	if(t1%2){
		if(t2==0) cout<<n;
		else cout<<t2;
	}else{
		if(t2==0) cout<<1;
		else cout<<n-t2+1;
	}
	
	return 0;
}