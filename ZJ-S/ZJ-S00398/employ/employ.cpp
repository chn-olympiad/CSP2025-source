#include<bits/stdc++.h>
using namespace std;
long long n,m,c[1000],q[1000],anss;
bool b[1000],l[1000];
void f(int s,int x){
	if(s>n){
		if(x>=m){
			anss++;
			//cout<<"eee"<<anss<<endl;
			anss=anss%998224353;
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(l[i]==0){
			l[i]=1;
			//cout<<i<<' ';
			if(q[s]>=c[i]||b[s]==0) f(s+1,x);
			else f(s+1,x+1);
			l[i]=0;
		}
	}
	return;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	string s;
	cin>>s;
	bool u=1;
	for(int i=0;i<s.size();i++){
		b[i+1]=s[i]-'0',u=u*b[i+1],q[i+1]=q[i]+1-b[i+1];
	}
	for(int i=1;i<=n;i++) scanf("%d",&c[i]);
	if(u==1){
		long long ans=1;
		for(int i=1;i<=n;i++) ans=(ans*i)%998244353;
		printf("%d",ans);
	}
	else if(n==m){
		printf("0");
	}
	else{
		f(1,0);
		cout<<anss;
	}
	return 0;
}
//s-00398
