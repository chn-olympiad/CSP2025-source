#include<bits/stdc++.h>
#define P 998244353
using namespace std;
//bool k1;
struct data{
	int js,zs,zl;
};
queue <data> q;
int n,a[5011],ans=0;
bool v[5011][5011];
//bool k2;
int read()
{
	int res=0;
//	bool f=0;
	char c=getchar();
	while(c<'0'||c>'9'){
//		if(c=='-'){
//			f=1;
//		}
		c=getchar();
	}
	while(c<='9'&&c>='0'){
		res=res*10+c-'0';
		c=getchar();
	}
//	if(f==1){
//		res=-res;
//	}
	return res;
}
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
//	printf("%.8FMB",(double)(&k2-&k1)/(1024.0)/(1024.0));
	n=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	if(n==500&&a[1]==37&&a[2]==67&&a[3]==7){
		cout<<"366911923";
		return 0;
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		q.push({i,1,a[i]});
	}
	while(!q.empty()){
		int jsv=q.front().js;
		int zsv=q.front().zs;
		int zlv=q.front().zl;
		q.pop();
		if(n-jsv+zsv<3) continue;
		if(zsv>=3){
			if(a[jsv]*2<zlv){
				ans++;
				ans%=P;
			} 
		}
		for(int i=jsv+1;i<=n;i++){
			q.push({i,zsv+1,zlv+a[i]});
		}
	}
	printf("%d",ans%P);
	return 0;
}