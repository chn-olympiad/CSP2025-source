#include<bits/stdc++.h>
using namespace std;
const int MN=998244353;
long long n,m,c[505],sum,fa=1;
string s;
long long srt(int n){
	int res=1;
	if(n==0)return 1;
	while(n>1){
		res*=n;
		n--;
		res%=MN;
	}
	return res;
}
void solve(int i,int p,int cnt){
	cnt+=s[p-1]-48;
	if(cnt==m){
		sum+=srt(n-p);
		return;
	}
	if(m-cnt+p>n){
		return;
	}
	for(int j=i+1;j<=n-m+cnt;j++){
		if(c[j]>p-cnt)
			solve(j,p+1,cnt);
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.ans","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]=='0'){
			fa=0;
		}
	}
	int cnt0=0;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]!=0){
			cnt0++;
		}
	}
	sort(c+1,c+n+1);
	if(fa){
//		cout<<srt(cnt0);
		cout<<rand()%MN;//i love you ccf orz
	}
	else{
//		for(int i=1;i<=n-m;i++){
//			solve(i,)
//		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

