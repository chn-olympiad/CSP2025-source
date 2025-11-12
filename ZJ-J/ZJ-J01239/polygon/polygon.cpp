#include<bits/stdc++.h>
using namespace std;
long long n,a[5001],s[5001],ans,m=998244353,sum;
map<int ,int> mp;
int low(int x){
	if(x==0) return 1;
	return x & -x;
}
void xg(int l,int w){
	for(int i=l;i<=sum;i+=low(i)){
		mp[i]+=w;
	}
}
long long cx(int x){
	long long sum=0;
	for(int i=x;i;i-=low(i)){
		sum+=mp[i];
		sum%=m;
	}
	return sum;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
		xg(s[i],mp[s[i]]+1);
		xg(s[i-1],mp[s[i-1]]+1);
		if(s[i]>2*a[i]){
			ans+=cx(s[i]-2*a[i]-1);
			ans%=m;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdin);
	return 0;
}
