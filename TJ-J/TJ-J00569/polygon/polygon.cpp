#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	int j=0,k=0,a=0,b=0,a_[100002],b_[100002],j_,k_;
	cin>>n;
	for(int i=1; i<=n; i++) {
		int s;
		cin>>s;
		if(s<3) {
			a++;
			a_[j++]=s;
		} else {
			b++;
			b_[k++]=s;
		}
	}
	j_=j;
	k_=k;
	sort(a_,a_+j);
	sort(b_,b_+k);
	for(int i=2; i<=j; i++) {
		if(a_[i]==a_[i-1]) {
			a_[i-1]=0;
			j_--;
		}
	}
	for(int i=2; i<=k; i++) {
		if(b_[i]==b_[i-1]) {
			b_[i-1]=0;
			k_--;
		}
	}
	j_++;
	cout<<(pow(j_,j_)*pow(k_,k_))%998244353;
	return 0;
}
