#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+10;
ll n,k,a[N];
ll l[N],r[N];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	int cnt=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==k) l[++cnt]=i,r[cnt]=i;
	}
	for(int i=1;i<=n;i++){
		ll he=a[i];
		for(int j=i+1;j<=n;j++){
			he^=a[j];
			if(he==k) l[++cnt]=i,r[cnt]=j;
		}
	}
	int ans[cnt+10];
	for(int i=1;i<=cnt;i++){
		ans[i]=1;
	}
	for(int i=1;i<=cnt;i++){
		for(int j=i;j<=cnt;j++){
			if(l[j]>r[i]) ans[i]++;
		}
	}
	int Max=0;
	for(int i=1;i<=cnt;i++){
		if(ans[i]>Max){
			Max=ans[i];
		}
	}
	cout<<Max;
	return 0;
}
