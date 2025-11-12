#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a[5007],ans,sum[5007],ta;
void cycle(ll s,int t){
	if(t>0&&s<=n){
		for(ll i=s;i<=n;i++){
			ans+=a[i];
			cycle(i+1,t-1);
			ans-=a[i];
		}
	}else{
		if(ans>2*a[s-1]) ta++;
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=sum[i-1]+a[i];
	}
	sort(a+1,a+n+1);
	if(n==3){
		sort(a+1,a+n+1);
		if(a[1]+a[2]>a[3]) cout<<1;
		else cout<<0;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	for(int i=3;i<=n;i++){
		ans=0;
		cycle(1,i);
	}
	cout<<(ta+1)/2;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
