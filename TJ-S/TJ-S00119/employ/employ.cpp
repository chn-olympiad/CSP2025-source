#include<iostream>
#include<algorithm>
using namespace std;
const int N=510;
string s;
int n,m;
const int mod=998244353;
int a[N];//patient
int get(){
	int pre,cur;
	pre=a[1];
	for(int i=2;i<=n;i++){
		cur=a[i];
		if(cur-pre!=1) return (pre+1);
		pre=cur;
	}
}int fact(int x){
	int ans=1;
	for(int i=2;i<=x;i++){
		ans=(ans*i)%mod;
	}return ans;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	cin>>s;
	bool have_zero=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0) have_zero=1;
	}sort(a+1,a+1+n);
	int ma=get();
	if(have_zero==0||n-ma>=m){
		cout<<fact(n);
		return 0;
	}else{
		cout<<0;
	}
	return 0;
}
