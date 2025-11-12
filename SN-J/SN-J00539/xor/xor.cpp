#include <bits/stdc++.h>

using namespace std;
int n,k;
int mx[500001];
int ans;
struct Area{
	int head_;
	int bail_;
	int quan;
};
int xor_;
Area t[1000001];
int m=1;
int mx_;
Area tf;
int pff(Area td,int way,Area* pp,int ans_){
	for(int i=way;i<=m-1;i++){
		if(td.bail_<pp[i].head_){
			return max(ans_,pff(pp[i],i,pp,ans_+1));
		}
	}
	return ans_;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i=1;i<=n;i++){
		cin >> mx[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<=n-i;j++){
			xor_=mx[i];
			for(int k=i+1;k<=i+j;k++){
				xor_=(xor_^mx[k]);
			}
			if(xor_==k){
				t[m].head_=i;
				t[m].bail_=i+j;
				t[m].quan=xor_;
				m++;
			}
		}
	}	
	for(int i=1;i<=m-1;i++){
		mx_=max(mx_,pff(t[i],i,t,1));
	}
	cout<<mx_;
	return 0;
}
