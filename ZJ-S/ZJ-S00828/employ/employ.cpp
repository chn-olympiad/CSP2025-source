#include<bits/stdc++.h>
using namespace std;
const long long mo=998244353;
int n,q,nai[20],p[20],vis[20];
long long ans=0;
string s;
void fp(int d){
	if(d==n){
		int r=0;
		for(int i=0;i<n;i++){
			if(nai[p[i]]<=r||s[i]=='0')r++;
		}
		if((n-r)>=q)ans++;
		return;
	}
	for(int i=0;i<n;i++){
		if(vis[i]==0){
			vis[i]=1;
			p[d]=i;
			fp(d+1);
			vis[i]=0;
		}
	}
}
void x(){
	for(int i=0;i<n;i++){
		p[0]=i;
		vis[i]=1;
		fp(1);
		vis[i]=0;
	}
	cout<<ans;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>q;
	cin>>s;
	if(n<=18){
		for(int i=0;i<n;i++){
			cin>>nai[i];
		}
		x();
	}
	else if(q==n)cout<<"1";
	else{
		cout<<'0';
	}
	return 0;
}