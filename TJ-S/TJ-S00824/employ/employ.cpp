#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
bool s[505]={},x[505]={};
int c[505]={},n,m;
ll dfs(int i,int z,int y){
	//cout << i << z << y << endl;
	if(i==n){
		if(y>=m){
			return 1;
		}else{
			return 0;
		}
	}
	ll sum=0;
	for(int k=0;k<n;k++){
		if(!x[k]){
			x[k]=true;
			//cout << "* " << k << endl;
			sum+=dfs(i+1,(c[k]<=z || (!s[i])?1:0)+z,(c[k]<=z||(!s[i])?0:1)+y);
			sum%=998244353;
			x[k]=false;
			//cout << "# " << k << endl;
		}
	}
	return sum;
}
#define cin in
#define cout out
int main(){
	fstream in,out;
	in.open("employ.in",ios::in);
	out.open("employ.out",ios::out);
	cin >> n >> m;
	bool ta=true,h=false;
	string ss="";
	cin >> ss;
	for(int i=0;i<n;i++){
		int a=ss[i]-'0';
		if(a==0){
			s[i]=false;
			ta=false;
		}else{
			s[i]=true;
			h=true;
		}
	}
	bool z=false;
	for(int i=0;i<n;i++){
		cin >> c[i];
		if(c[i]!=0){
			z=true;
		}
	}
	if(ta){
		ll ans=1;
		for(int i=1;i<=n;i++){
			ans*=i;
			ans%=998244353;
		}
		cout << ans <<endl;
	}else if(m==1){
		if(h && z){
			ll ans=1;
			for(int i=1;i<=n;i++){
				ans*=i;
				ans%=998244353;
			}
			cout << ans <<endl;
		}else{
			cout << 0 << endl;
		}
	}else{
		cout << dfs(0,0,0) << endl;
	}
	return 0;
}