#include<bits/stdc++.h>
using namespace std;
int n,k,ans=0;
int my_xor(int a, int b){
	if (a==-1) return b;
	if (b==-1) return a;
	int n1[11],n2[11],n3[11],t=1;
	while(a>0){
		n1[t]=a%2;
		a/=2;
		t++;
	}
	int t2=1,ans=0;
	while(b>0){
		n2[t2]=a%2;
		b/=2;
		t2++;
	}
	int maxn=max(t,t2);
	for (int i=1;i<=maxn;i++){
		if (n1[i]==n2[i]) n3[i]=0;
		else n3[i]=1;
	}
	for(int i=1;i<=maxn;i++) ans += n3[i]*pow(2,i-1);
	return ans;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	int a[n+11],t=-1;
	for (int i=1;i<=n;i++){
		cin >> a[i];
		if (my_xor(t,a[i])==k){
			ans++;
			t=-1;
			continue;
		} 
		if (my_xor(-1,a[i])==k){
			ans++;
			t=-1;
			continue;
		} 
		t=a[i];
	} 
	cout << ans;
	return 0;
}
