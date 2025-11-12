#include<bits/stdc++.h>
using namespace std;
long long js_[25050025],n_,a_[5005],ans_,maxa_;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n_;
	if(n_<3){
		cout<<0;
		return 0;
	}
	for(int i=1; i<=n_; i++){
		cin>>a_[i];
	}
	sort(a_+1,a_+1+n_);
	js_[a_[1]+a_[2]]=1;
	maxa_=a_[1]+a_[2];
	for(int i=3; i<=n_; i++){
		for(int j=a_[i]+1; j<=maxa_; j++){
	        ans_=(ans_+js_[j])%998244353;
		}
		for(int j=maxa_; j>0; j--){
			if(js_[j]>0)js_[j+a_[i]]=(js_[j+a_[i]]+js_[j])%998244353;
		}
		for(int j=1; j<i; j++){
			js_[a_[j]+a_[i]]=(js_[a_[j]+a_[i]]+1)%998244353;
		}
		maxa_+=a_[i];
	}
	cout<<ans_;
	return 0;
}
