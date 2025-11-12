#include <bits/stdc++.h>
using namespace std;
const int N=500010;
int n,k,a[N],ans_,r,l,la_,jl_;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	double c=clock();
	cin>>n>>k;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	for(int i=1;i<=n;++i){
		if(a[i]==k){
			++ans_;
			jl_=i;
			continue;
		}
		r=i,l=i-1,la_=a[i];
		while(l>jl_){
			la_^=a[l];
			if(la_==k){
				jl_=i;
				++ans_;
				break;
			}
			--l;
			double d=clock();
			if((d-c)>=970){
				break;
			}
		}
		double d=clock();
		if((d-c)>=970){
			break;
		}
	}
	cout<<ans_;
	return 0;
}
