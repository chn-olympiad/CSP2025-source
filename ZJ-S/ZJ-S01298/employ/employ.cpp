#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
long long rej,flag[1000010],fx[1000010],n,s2,q,i,m,s,f[1000010];
char a[1000010];
void sc(int t,int rej){
	int i;
	if(rej>n-m)
		return ;
//	cout<<t<<" "<<endl;
	if(t>n){
		s++;
//		rej=0;
//		for(i=1;i<=n;i++)
//			cout<<fx[i]<<" ";
//		cout<<endl;
//		for(i=1;i<=n;i++)
//			if(a[i]-'1'||rej>=f[fx[i]])
//				rej++;
//		cout<<rej<<endl;
//		s=s+(rej<=n-m);
		return ;
	}
	for(i=1;i<=n;i++)
		if(!flag[i]){
			flag[i]=1;
			fx[t]=i;
			if(a[t]-'1'||rej>=f[i])
				sc(t+1,rej+1);
			else
				sc(t+1,rej);
			flag[i]=0;
		}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>a+1;
	for(i=1;i<=n;i++)
		cin>>f[i];
	if(n-m){
		sc(1,0);
		cout<<s;
	}
	else{
		s=1;
		for(i=1;i<=n;i++)
			if(!f[i]){
				cout<<0;
				return 0;
			}
		for(i=1;i<=n;i++)
			if(a[i]-'1'){
				cout<<0;
				return 0;
			}
		for(i=1;i<=n;i++)
			s=s*i%mod;
		cout<<s;
	}
}
