#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=505;
const int mod=998244353;
int n,m;
string s;
int c[N],p[N];
ll ans;
void Bf1(){
	for(int i=1;i<=n;i++)p[i]=i;
	ans=0;
	do{
		int sum=0,cnt=0;
		for(int i=1;i<=n;i++){
			if(sum<c[p[i]]&&s[i-1]=='1')cnt++;
			else sum++;
		}	
		if(cnt>=m){
			ans++;
		}
	}while(next_permutation(p+1,p+n+1));
	cout<<ans;
}
void Bf2(){//m=n
	for(int i=1;i<=n;i++)
		if(s[i-1]=='0'){
			cout<<"0";
			return;
		}
	for(int i=1;i<=n;i++)
		if(c[i]==0){
			cout<<"0";
			return;
		}
	ll ans=1;
	for(int i=1;i<=n;i++)ans=ans*i%mod;
	cout<<ans;
}
void Bf3(){//FA and no 0
	ll ans=1;
	for(int i=1;i<=n;i++)ans=ans*i%mod;
	cout<<ans;
}
void Bf4(){//FA
	vector<int>v[2];
	for(int i=1;i<=n;i++)v[c[i]>0].push_back(i);
	if(v[0].size()>m){
		cout<<"0";return;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	int FA=1;
	cin>>s;
	for(int i=1;i<=n;i++)
		if(s[i-1]=='0')FA=0;
	int Min=c[1];
	for(int i=1;i<=n;i++)cin>>c[i];
	for(int i=2;i<=n;i++)Min=min(Min,c[i]);
	if(n<=10)Bf1();
	else if(n==m)Bf2();
	else if(Min&&FA)Bf3();
	else if(FA)Bf4();
	else cout<<"0";
	return 0;
}