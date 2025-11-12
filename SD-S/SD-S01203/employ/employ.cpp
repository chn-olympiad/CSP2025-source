#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const long long N=1e6+10;
const long long M=1e3+10;
const long long Mod=998244353;
long long n,m;
bool s[N];
string S;
long long c[N];
bool pd[N];
long long ans=0;
long long A(long long k){
	if(k==0) return 1;
	if(k==1) return 1;
	long long num=1;
	for(long long i=2;i<=k;i++){
		num=((num%Mod)*i)%Mod;
	} 
	return num;
}
void dfs(long long k,long long bad,long long num){
	//cout<<k<<' '<<bad<<' '<<num;
	if(num==m){
		//cout<<" good"<<'\n';
		//ans+=A(n-k+1);
		ans=((ans%Mod)+(A(n-k+1)%Mod))%Mod;
		return ;
	}
	//cout<<'\n';
	if(k==n+1){
		return ;
	}
	for(long long i=1;i<=n;i++){
		if(!pd[i]){
			pd[i]=true;
			//cout<<'['<<i<<']'<<' ';
			if(c[i]<=bad||!s[k]){
				dfs(k+1,bad+1,num);
			}else{
				dfs(k+1,bad,num+1);
			}
			pd[i]=false;
		}
	}
}
int main(){
	cin.tie(0)->sync_with_stdio(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>S;
	long long number=0;
	for(long long i=1;i<=n;i++){
		if(S[i-1]=='1'){
			s[i]=true;
			number++;
		} 
	}
	m=min(number,m);
	for(long long i=1;i<=n;i++){
		cin>>c[i];
	}
	dfs(1,0,0);
	cout<<ans;
	return 0;
}
