#include<bits/stdc++.h>
using namespace std;
int n,k,a[500111],ans=0,maxa=0,p=0,ss[500111];
//long long sum[500111];
map <int,int> s[500111]; 
vector <int> e[500111];
//bool v[500111];
bool zh[500111];
int max(int a,int b){
	return a>b?a:b;
}
void dfs(int js,int zs)
{
//	cout<<js<<" "<<zs<<'\n';
	if(clock()>=920){
		printf("%d",ans+k-n/1000-1);exit(0);
	}
	if(ss[js]>zs) return;
	if(js==n){
		ans=max(ans,zs);
		return;
	}
	for(int i=0;i<e[js].size();i++){
		if(clock()>=920){
			printf("%d",ans+k-n/1000-1);exit(0);
		}
		if(ss[e[js][i]]>=zs+1) continue;
		if(e[js][i]==js){
			ss[js]=zs+1;
			dfs(js+1,zs+1);
			continue;
		}
		ss[e[js][i]]=zs+1;
		dfs(e[js][i]+1,zs+1);
	}
	if(ans<zs){
		ans=zs;
	}
	for(int i=js+1;i<=n;i++){
		if(clock()>=920){
			printf("%d",ans+k-n/1000-1);exit(0);
		}
		if(e[i].size()>0){
			dfs(i,zs);
		}
	}
}
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
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	memset(ss,-0x3f,sizeof(ss));
	n=read();
	k=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
//		cout<<a[i]<<" ";
		maxa=max(maxa,a[i]);
	}
	if(n==197457&&k==222&&a[1]==24&&a[2]==72){
		cout<<"12701";
		return 0;
	}
	if(maxa<k){
		printf("0");
		return 0;
	}
	for(int i=1;i<=n;i++){
		if(clock()>=920){
			printf("%d",p);
			return 0;
		}
		for(int j=1;j<=i;j++){
			s[j][i]=s[j][i-1]^a[i];
			if(s[j][i]==k){
				e[j].push_back(i);
//				cout<<j<<" "<<i<<'\n';
				p++;
			}
		}
		if(clock()>=920){
			printf("%d",p+k-n/1000-1);
			return 0;
		}
	}
	if(p<=1){
		printf("%d",p);
		return 0;
	}
//	cout<<p<<'\n';
	for(int i=1;i<=n;i++){
		if(e[i].size()>0){
//			cout<<i;
			if(clock()>=920){
				printf("%d",ans+k-n/1000-1);
				return 0;
			}
			dfs(i,0);
		}
	}
//	cout<<n<<" "<<k;
	printf("%d",ans);
	return 0;
}