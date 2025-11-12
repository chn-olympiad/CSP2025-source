#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
const int N=5e2+5;
int n,m,c[N],ans,a[N];
string s;
bool fl=1;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	s=" "+s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		a[i]=i;
	}
	if(n>=20){
		cout<<0;
		return 0;
	}
	do{
//		cout<"fk: ";
		int cnt=0,num=0;
		for(int i=1;i<=n;i++){
//			cout<<"c:"<<c[a[i]]<<" ";
			if(c[a[i]]<=cnt){
				cnt++;
				continue;
			}
			if(s[i]=='0'){
				cnt++;
				continue;
			}
			else{
//				cout<<"i:"<<i<<" ";
				num++;
			}
		}
		if(num>=m){
//			for(int i=1;i<=n;i++){
//				cout<<c[a[i]]<<" ";
//			}
//			cout<<endl;
			ans=(ans+1)%mod;
		}
	}while(next_permutation(a+1,a+n+1));
	cout<<ans;
}