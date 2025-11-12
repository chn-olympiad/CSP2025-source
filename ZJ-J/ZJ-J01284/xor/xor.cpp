#include<bits/stdc++.h>
using namespace std;
long long n,k,a[200005],ans;
long long cut(long long x,long long y){
	if(x==y&&a[x]==k) return k;
	string j,k;
	long long cnt11=a[x];
	while(cnt11>0){
		j+=(cnt11%2+'0');
		cnt11/=2;
	}
	for(int i=x+1;i<=y;i++){
		long long cnt=a[i];
		while(cnt>0){
			k+=(cnt%2+'0');
			cnt/=2;
		}
		int len=max(j.size(),k.size());
		for(int i=0;i<len;i++){
			if(j[i]==k[i]) j[i]='0';
			else j[i]='1';
		}
	}
	long long sum1=0;
	for(int i=0;i<j.size();i++){
		if(j[i]=='1') sum1+=pow(2,i);
	}
	return sum1;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(cut(i,j)==k){	
				ans++;
				cout<<i<<" "<<j<<endl;	
			}
		}
	}
	cout<<ans;
}