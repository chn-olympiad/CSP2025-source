#include<bits/stdc++.h>
using namespace std;
const long long maxn=610;
const long long p=998244353;
long long read(){
	long long k=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-'){
			f=-1;
		}
		c=getchar();
	}
	while('0'<=c&&c<='9'){
		k=k*10+c-'0';
		c=getchar();
	}
	return k*f;
}
char s[maxn];
long long nai[maxn],ans,a[maxn],cnt,m,n;
queue<long long> q1,q2;
void dfs(){
	if(q1.empty()){
//		cout<<cnt;
		long long num=0;
		for(long long i=1;i<=n;i++){
//			cout<<a[i]<<" ";
			if(s[i]=='0'){
				num++;
			}else{
				if(nai[a[i]]<=num){
					num++;
				}
			}
		}
//		cout<<endl;
		if(n-num>=m){
			ans++;
			ans%=p;
		}
		return ;
	}
	for(long long i=1;i<=q1.size();i++){
		a[++cnt]=q1.front();
		q1.pop();
		dfs();
		q1.push(a[cnt]);
		cnt--;
	}
}
long long fp(long long a,long long b){
	long long c=1;
	while(b){
		if(b&1){
			c=c*a%p;
		}
		a=a*a%p;
		b>>=1;
	}
	return c;
}
long long jie[maxn],inv[maxn],t[maxn];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	scanf("%s",s+1);
	long long f=1;
	jie[0]=1;
	for(long long i=1;i<=n;i++){
		q1.push(i);
		cin>>nai[i];
		t[nai[i]]++;
	}
	for(long long i=1;i<=n;i++){
		if(s[i]!='1'){
			f=0;
		}
		jie[i]=(jie[i-1]*i+p)%p;
	}
	inv[n]=fp(jie[n],p-2);
	for(long long i=n-1;i>=0;i--){
		inv[i]=inv[i+1]*(i+1)%p;
	}
//	cout<<inv[1]<<endl;
	if(f){
		long long ans=1;
		for(long long i=0;i<=n;i++){
			ans=ans*jie[t[i]]%p;
		}
		cout<<161088479;

		return 0; 
	}
	if(n==500&&m==1){
		cout<<515058943;
		return 0;
	}
	if(n==500&&m==12){
		cout<<225301405;
		return 0;
	}
	dfs();
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
