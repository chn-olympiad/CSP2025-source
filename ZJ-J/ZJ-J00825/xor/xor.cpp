#include<bits/stdc++.h>
using namespace std;
map<int,int> mp;
int n,k,sum;
int a[1005];
int xor_1(int a,int b){
	if(a==b)return a;
	if(a==0)return b;
	if(b==0)return a;
	int c1=0,c=0;
	while(a>0||b>0){
		c1*=2;
		bool ai=a%2;
		bool bi=b%2;
		if(ai!=bi)c1++;
		a/=2;
		b/=2;
	}
	while(c1>0){
		c*=2;
		c+=c1%2;
		c1/=2;
	}
	return c;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	for(int i=1;i<=n;i++){
		int num_xor=i;
		int j=i+1;
		while(j<=n&&(xor_1(num_xor,a[j])!=k)){
			num_xor=xor_1(num_xor,a[j]);
			j++;
		}
		if(a[i]==k){
			mp[i]=i;
		}else{
			if(j<=n){
				mp[i]=j;
			}else{
				mp[i]=0;
			}
		}
	}
	int i=1;
	while(i<=n){
		if(mp[i]!=0){
			sum++;
			i=mp[i]+1;
		}else{
			i++;
		}
	}
	cout << sum;
	return 0;
}
