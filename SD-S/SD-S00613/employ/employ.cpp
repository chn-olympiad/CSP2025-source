#include<bits/stdc++.h>
using namespace std;
const int M=998244353;
int n,m,a[510],c[510],p[510],vis[510];
long long ans;
string s;
bool f=true;
bool check(){
	int cnt=0,tot=0;
	for(int i=1;i<=n;i++){
		if(!a[p[i]]||cnt>=c[p[i]])
			cnt++;
		else
			tot++;
	}
	if(tot>=m)
		return true;
	return false;
}
void work(int dep){
	if(dep==n){
		if(check()){
			ans++;
			ans%=M;
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			p[dep]=i;
			work(dep+1);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d %d",&n,&m);
	cin>>s;
	for(int i=1;i<=n;i++){
		a[i]=(s[i-1]-'0');
		if(!a[i])
			f=false;
	}
	for(int i=1;i<=n;i++)
		scanf("%d",&c[i]);
	if(f){
		int num=0;
		ans=1;
		sort(c+1,c+n+1);
		for(int i=1;i<=n;i++){
			if(c[i])
				break;
			num++;
		}
		for(int i=1;i<=c[num+1];i++){
			ans*=i;
			ans%=M;
		}
		for(int i=num+1;i<=n;i++){
			ans*=(i-num);
			ans%=M;
		}
		for(int i=c[num+1];i<=num+1;i++){
			ans*=(i-c[num+1]);
			ans%=M;
		}
		printf("%d",ans);
		return 0;
	}
	if(m==n){
		printf("0");
		return 0;
	}
	if(m==1){
		bool fc=true;
		for(int i=1;i<=n;i++)
			if(c[i])
				fc=false;
		if(fc&&!a[1]){
			printf("0");
			return 0;
		}
		if(fc&&a[1]){
			ans=1;
			for(int i=1;i<=n;i++){
				ans*=i;
				ans%=M;
			}
			printf("%d",ans);
			return 0;
		}
	}
	work(1);
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

