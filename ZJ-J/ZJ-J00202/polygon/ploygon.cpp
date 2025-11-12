#include<bits/stdc++.h>
using namespace std;
int n,cnt=0,a[5000];vector<int>_;
int jc(int a){int temp=1;for(int i=1;i<=a;i++)temp*=i;return temp;}
int C(int n,int m){return jc(n)/jc(m)/jc(n-m);}
void nextglm(int n){
	for(int i=0;i<(1<<n);i+=8){
		_.push_back(i+0),_.push_back(i+1),_.push_back(i+3),_.push_back(i+2),
		_.push_back(i+6),_.push_back(i+7),_.push_back(i+5),_.push_back(i+4);
	}
}
int low_bit(int x){return x&-x;}
int _LOW_BIT(int x){return (int)(log2(x&-x));}
int main(){
	freopen("ploygon.in","r",stdin);
	freopen("ploygon.out","w",stdout);
	std::ios::sync_with_stdio(0);
	cin>>n;for(int i=0;i<n;i++)cin>>a[i];
	if(n==3){if((a[0]+a[1]+a[2])>(max(max(a[0],a[1]),a[2])*2)){cout<<1;}
		else cout<<0;return 0;}
	if(a[0]==a[(n-1)/3]==a[(n-1)/3*2]==a[n-1]==1){
		int t=0;for(int i=3;i<=n;i++)t+=C(n,i);
		cout<<t;return 0;}nextglm(n);
	for(int i=1;i<=(1<<n);i++){
		int temp=_[i];
		temp-=low_bit(temp),
		temp-=low_bit(temp);
		if(temp>0){int _max=-1,_sum=0,te=_[i];for(;te;){
				int id=_LOW_BIT(te);
				_sum+=a[id],_max=max(_max,a[id]),te-=low_bit(te);
			}
			if(_sum>_max*2)cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
