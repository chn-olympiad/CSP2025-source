#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
int n,k,a[500010],b[500010],x,y,z,f1,f2,sum,maxx;
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1){
			f1=1;
			break;
		}
	}
	if(n==1){
		if(a[1]==k){
			cout<<1;
		}else{
			cout<<0;
		}
		return 0;
	}
	if(n==2){
		if(a[1]==k){
			x++;
		}
		if(a[2]==k){
			y++;
		}
		if(a[1]^a[2]==k){
			z++;
		}
		cout<<max(x+y,z);
		return 0;
	}
	if(f1==0){
		if(k!=1){
			cout<<0;
		}else{
			cout<<n;
		}	
		return 0;	
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			x=a[i];
			for(int l=i+1;l<=j;l++){
				x=x^a[l];
				if(x==k){
					sum++;
					cout<<i<<" "<<j<<endl;
				}
				if(a[l]==k){
					sum++;
				}
			}
			maxx=max(maxx,sum);
			sum=0;
		}
	}
	cout<<maxx;
	return 0;
}