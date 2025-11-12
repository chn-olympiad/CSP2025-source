#include<bits/stdc++.h>
using namespace std;
const int N=5e2+5,Mod=998244353;
int n,m,T;
string s;
int jc[N],sum[N],x[N];
int c[N],out,in,in_d,out_d;
priority_queue<int,vector<int>,greater<int>>q;

int ksm(int a,int b){
	if(b==0)return 1;
	if(b==1)return a;
	int j=a,t=1;
	int ans=1;
	while(t<=b){
		j=(j*j)%Mod;
		t*=2;
		if(t*2>b)break;
	}
	ans=(ans*j*ksm(a,b-t))%Mod;
	return ans;
}

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>m>>s;
	T=s.size();
	for(int i=0;i<T;++i)sum[i+1]=s[i]-'0';
	for(int i=1;i<=n;++i)cin>>c[i],q.push(c[i]);
	jc[0]=1;
	for(int i=1;i<=n;++i)jc[i]=(jc[i-1]*i)%Mod;
	for(int i=1;i<=n;++i)sum[i]+=sum[i-1];
	for(int i=1;i<=n;++i)
		for(int i=1;i<=n;++i){
			if(sum[i]<=c[i])x[i]++;
		}
	int ans=1;
	for(int i=1;i<=n;++i)ans*=x[i];
	cout<<ans;
}
