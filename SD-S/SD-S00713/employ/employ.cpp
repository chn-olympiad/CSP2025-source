#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=1e5+9,MOD=998244353;
LL n,nn,m,c[N],ans=0,vis[N],b[N],cc[N],c2[N],f[N];
string str;
LL A(LL x){
	if(x==0)return 1;
	LL s=1;
	for(int i=1;i<=x;i++){
		s*=i;
		s%=MOD;
	}
	return s;
}
bool check(){
	LL gu=0;
	for(int i=1;i<=n;i++){
		if(str[i]=='0')gu++;
		else if(gu>=b[i])gu++;
	}
	return m+gu<=n;
}
void fi(LL ce){
	if(ce==n){
		if(check()){//printf("%lld %lld %lld",b[1],b[2],b[3]);
			LL sum=1;
			for(int i=0;i<=n;i++){//printf("%lld %lld %lld\n",sum,cc[i],A(cc[i]));
				sum*=A(c2[i]);
				sum%=MOD;
			}
			ans+=sum;
			ans%=MOD;
		}
		return ;
	}
	for(int i=0;i<=n;i++){
		if(cc[i]==0)continue;
		cc[i]--;
		b[ce+1]=i;
		fi(ce+1);
		cc[i]++;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld%lld",&n,&m);nn=n;
	cin>>str;
	str=' '+str;//cout<<"q"<<str<<"q"; 
	for(int i=1;i<=n;i++){
		scanf("%lld",&c[i]);
		cc[c[i]]++;
		if(!c[i])nn--;
	}
	for(int i=0;i<=n;i++)c2[i]=cc[i];
	//printf("%lld %lld %lld\n",cc[1],cc[2],A(2));
	bool a1=1,a0=1,n1=0;
	for(int i=1;i<=n;i++){
		if(!(a1|a0))break;
		if(str[i]=='1'){a0=0;n1++;}
		else a1=0;
	}
	if(n1<m){
		printf("0");
		return 0;
	}
	if(m==n){
		if(nn==n&&a1)ans=A(n);
		printf("%lld",ans);
		return 0;
	}
	if(a1){
		if(nn==n){
			ans=A(n);
			printf("%lld",ans);
			return 0;
		}
	}
	if(m==1){
		LL t=0;
		for(int i=1;i<=n;i++){
			if(f1<=c[i])t++;
		} 
		//printf("%lld\n",t);
		ans=t*A(n-1);
		ans%=MOD;
		printf("%lld",ans);
		return 0;
	}
	fi(0);
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
