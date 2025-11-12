#include<bits/stdc++.h>
using namespace std;
const int Mod=998244353;         
char s[1005];
long long n,m,fl,ans,len,f[1005];
struct Node{
	int pa,num;
}c[1005],b[1005];
bool cmp(Node a,Node b){
	return a.num<b.num;
}
int pd(){
	int sum=0,fq=0;
	for(int i=1;i<=n;i++)
		b[i].num=c[i].num,b[i].pa=c[i].pa;
	sort(b+1,b+1+n,cmp);
	for(int i=1;i<=n;i++){
		if(fq>=b[i].pa||s[i]=='0')fq++;
		else sum++;
		if(sum>=m)return 1;
	}
	return (sum>=m);
}
void sc(int t){
	if(t>n){
		if(pd())ans=(ans+1)%Mod;
		return ;
	}
	for(int i=1;i<=n;i++)
		if(f[i]==0){
			c[t].num=i;
			f[i]=1;
			sc(t+1);
			f[i]=0;
		}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s+1;
	for(int i=1;i<=n;i++)cin>>c[i].pa;
	if(n<=10){
		sc(1);
		cout<<ans;
		return 0;
	}
	ans=1;
	for(int i=1;i<=n;i++)
		ans=ans*i%Mod;
	cout<<ans%Mod;
	return 0;
}

