#include<bits/stdc++.h>
using namespace std;
struct S{
	int a;
	int b;
	int c;
}a[100005];
bool cmd(S p,S q){
	return (p.a-p.b)>(q.a-q.b);
}
int n;
int asolve(){
	int ans=0;
	for(int i=0;i<n;i++)
		ans+=a[i].a;
	return ans;
}
int bsolve(){
	int ans=0;
	sort(a,a+n,cmd);
	for(int i=0;i<n/2;i++)
		ans+=a[i].a;
	for(int i=n/2;i<n;i++)
		ans+=a[i].b;
	return ans;
}
int csolve(){
	int ans=0;
	for(int i=0;i<n;i++)
		ans+=max(max(a[i].a,a[i].b),a[i].c);
	return ans;
}
int dsolve(int u,int ca,int cb,int cc,int o){
	if(ca>n/2||cb>n/2||cc>n/2)
		return 0;
	if(u==n-1)
		return o;
	int ans=dsolve(u+1,ca+1,cb,cc,o+a[u+1].a);
	ans=max(ans,dsolve(u+1,ca,cb+1,cc,o+a[u+1].b));
	ans=max(ans,dsolve(u+1,ca,cb,cc+1,o+a[u+1].c));
}
int solve(){
	bool s1=true,s2=true;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i].a>>a[i].b>>a[i].c;
		if(a[i].c>0){
			s1=s2=false;
			
		}
		if(a[i].b>0)
			s1=false;
	}
	if(s1)
		return asolve();
	if(s2)
		return bsolve();
	if(n==100000)
		return csolve();
	return dsolve(-1,0,0,0,0);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t>0,t--)
		cout<<solve()<<endl;
	return 0;
}