#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll k;
ll n;
ll a[500005];
int num[500005];
int vis[500005];
int ans;
string zh(int x){
	string s;
	while(x){
		if(x%2==0){
			s="0"+s;
		}
		else{
			s="1"+s;
		}
		x/=2;
	}
	return s;
}
string yh(string x,string y){
	string yhh="";
	int lenx=x.size();
	int leny=y.size();
	if(lenx<leny){
		for(int i=1;i<=leny-lenx;i++){
			x=" "+x;
		}
		lenx=leny;
	}
	else if(lenx>leny){
		for(int i=1;i<=lenx-leny;i++){
			y=" "+y;
		}
		leny=lenx;
	}
	for(int i=lenx-1;i>=0;i--){
		if(x[i]!=y[i]){
			yhh="1"+yhh;
		}
		else{
			yhh="0"+yhh;
		}
	}
	return yhh;
}
int zh2_10(string s){
	int len=s.size(),z=0;
	int x=1;
	for(int i=len-1;i>=0;i--){
		if(s[i]=='1'){
			z+=x;
			x*=2;
		}
	}
	return z;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==1&&k==0){
		if(a[1]!=0){
			cout<<0;
			return 0;
		}
		else{
			cout<<1;
			return 0;
		}
	}
	else if(n==0&&k==0){
		if(a[1]==a[2]&&a[1]!=0){
			cout<<1;
			return 0;
		}
		else if(a[1]==a[2]&&a[1]==0){
			cout<<3;
			return 0;
		}
		else{
			if(a[1]==0||a[2]==0){
				cout<<1;
				return 0;
			}
			else{
				cout<<0;
				return 0;
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(a[i]==0){
			ans++;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n+1-i;j++){
			string za=zh(a[i]);
			for(int k=i+1;k<=i+j-1;k++){
				string zk=zh(a[k]);
				za=yh(za,zk);
			}
			if(zh2_10(za)==k){
				ans++;
				vis[i]++;
				vis[i+j-1]++;
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(vis[i]>1){
			ans-=(vis[i]-1);
		}
	}
	cout<<ans;
	return 0;
}
