#include<bits/stdc++.h>
using namespace std;
bool isa=1;
long long n,m,scs,cnt;
string s;
bool vis[541];
long long a[541];
long long c[548];
long long fac[551];
void rst(){
	fac[0]=1;
	for(long long i=1;i<=500;i++)fac[i]=(fac[i-1]*i)%998244353;
	return;
}
void chk(){
	scs=0;
	for(long long i=1;i<=n;i++){
		if((i-scs-1)>=c[a[i]])continue;
		if(s[i]==49)scs++;
	}
	if(scs>=m){
		cnt++;
		cnt%=998244353;
	}
	return;
}
void dfs(long long x){
	if(x>n){
		chk();
		return;
	}
	for(long long i=1;i<=n;i++){
		if(vis[i])continue;
		a[x]=i;
		vis[i]=1;
		dfs(x+1);
		vis[i]=0;
	}
	return;
}
void svn10(){
	dfs(1);
	cout<<cnt<<endl;
	return;
}
void svn18(){
	svn10();
	return;
}
void svn100(){
	return;
}
void svm1(){
	return;
}
void svmn(){
	return;
}
void sva(){
	//什么？还有人压根就不想来面试？
	cout<<fac[n]<<endl;
	return;
}
void svb(){
	return;
}
void svall(){
	return;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	rst();
	cin>>n>>m;
	cin>>s;
	s=" "+s;
	for(long long i=1;i<=n;i++)if(s[i]==48)isa=0;
	for(long long i=1;i<=n;i++)cin>>c[i];
	if(n<=10)svn10();
	else if(n<=18)svn18();
	else if(isa)sva();
	else if(n<=100)svn100();
	else if(m==1)svm1();
	else if(m==n)svmn();
	else svall();
	return 0;
}
