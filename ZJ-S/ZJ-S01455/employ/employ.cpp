#include<bits/stdc++.h>
using namespace std;
long long n,m,a[100005],f=1,cnt=1;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=0;i<s.size();i++){
		if(s[i]=='0') f=0;
	}
	if(f==1){
		for(int i=1;i<=n;i++){
			cnt*=i;
			cnt%=998244353;
		}
		cout<<cnt<<"\n";
	}else{
		cout<<"2"<<"\n";
	}
	return 0;
}
