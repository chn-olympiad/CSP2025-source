#include<bits/stdc++.h>
#define int long long
#define debug printf("!!!\n")
using namespace std;
int read(){
	char c=getchar();
	int x=0,f=1;
	for(;c<'0'||c>'9';c=getchar()){
		if(c=='-') f=-1;
	}
	for(;c>='0'&&c<='9';c=getchar()) x=x*10+c-'0';
	return x*f;
}
void write(int x){
	if(x<0) putchar('-'),x=-x;
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
void write(int x,char c){
	write(x);putchar(c);
}
const int N=1e5+5;
int n;
struct node{
	int a,b,c;
}a[N];
vector<int> v1,v2,v3,v;
void solve(){
	v1.clear();v2.clear();v3.clear();v.clear();
	n=read();
	int ans=0;
	for(int i=1;i<=n;i++){
		int x=read(),y=read(),z=read();
		a[i]=(node){x,y,z};
		int t=max(x,max(y,z));
		ans+=t;
		if(t==x) v1.push_back(i);
		else if(t==y) v2.push_back(i);
		else if(t==z) v3.push_back(i);
	}
	int l1=v1.size(),l2=v2.size(),l3=v3.size();
	if(l1<=n/2&&l2<=n/2&&l3<=n/2) return write(ans,'\n');
	if(l1>n/2){
		for(int i=0;i<l1;i++){
			int x=v1[i];
			v.push_back(-a[x].a+max(a[x].b,a[x].c));
		}
		sort(v.begin(),v.end(),greater<int>());
		for(int i=0;i<l1-n/2;i++) ans+=v[i];
		write(ans,'\n');
	}
	if(l2>n/2){
		for(int i=0;i<l2;i++){
			int x=v2[i];
			v.push_back(-a[x].b+max(a[x].a,a[x].c));
		}
		sort(v.begin(),v.end(),greater<int>());
		for(int i=0;i<l2-n/2;i++) ans+=v[i];
		write(ans,'\n');
	}
	if(l3>n/2){
		for(int i=0;i<l3;i++){
			int x=v3[i];
			v.push_back(-a[x].c+max(a[x].a,a[x].b));
		}
		sort(v.begin(),v.end(),greater<int>());
		for(int i=0;i<l3-n/2;i++) ans+=v[i];
		write(ans,'\n');
	}
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	for(int t=read();t--;solve());
	return 0;
}
/*
1
2
10 9 8
4 0 0
*/
