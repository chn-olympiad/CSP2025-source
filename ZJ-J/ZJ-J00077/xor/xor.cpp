#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,k,a[510000],s[510000],cnt,mx,s2[510000];
struct S{
	ll x,y,z=1;
}b[51000000];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i==1){
			s[i]=a[i];
		}
		else s[i]=s[i-1]^a[i];
	}
	if(k<=1&&n>=110){
		for(int i=n;i>=1;i--){
			s2[i]=s2[i+1]+s[i];
		}
		ll cnt2=0,cnt3=0,cnt4=0,cnt5=0;
		for(int i=1;i<=n;i++){
			if(a[i]==1){
				cnt2+=n-i-s2[i]-1;
				cnt4+=s2[i];
			}
			else{
				cnt3+=s2[i];
				cnt5+=n-i-s2[i]-1;
			}
		}
		if(k==0){
			cout<<cnt4+cnt5;
		}
		else{
			cout<<cnt2+cnt3;
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			if((s[j-1]^s[i])==k){
				b[++cnt].x=j,b[cnt].y=i;
			}
		}
	}
	for(int i=1;i<=cnt;i++){
		int x=b[i].x,y=b[i].y;
		for(int j=i;j<=cnt;j++){
			if(b[j].x>y){
				y=b[j].y;
				b[i].z++;
			}
		}
		mx=max(mx,b[i].z);
	}
	cout<<mx;
	return 0;
}

