#include<bits/stdc++.h>
using namespace std;
int n,a[5010],l,q,cnt;
vector<int> v_2,v;
const int mod=998244353;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	if(a[n]==1){
		for(int i=3;i<=n;i++){
			int k1=1,k2=1;
			for(int j=0;j<i;j++){
				k1*=(n-j);
				k1%=mod;
			}
			for(int j=1;j<=i;j++){
				k2*=j;
				k2%=mod;
			}
			cnt+=k1/k2;
		}
		cout<<cnt<<endl;
		return 0;
	}
	for(int i=1;i<=n;i++){
		q=v.size(),l=v.size();
		for(int j=0;j<l;j++) v.push_back(v[j]+a[i]);
		l=v_2.size();
		for(int j=0;j<l;j++) v.push_back(v_2[j]+a[i]);
		for(int j=1;j<i;j++) v_2.push_back(a[j]+a[i]);
		l=v.size();
		for(int j=q;j<l;j++){
			if(v[j]>a[i]*2) cnt++;
			cnt%=mod; 
		}
	}
	cout<<cnt<<endl;
	return 0;
}

