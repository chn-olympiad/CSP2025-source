#include<bits/stdc++.h>
using namespace std;
const int MS=505,p=998244353;
int n,m,c[MS];
char s[MS];
int pos[MS],ch[MS];
bool flagA=1,flagB=1;
bool cmp(int a,int b){
	return a>b;
}
int res=0;
int flag[MS];
void solve(int t,int cnt,int fail){
	if(t==n+1&&cnt>=m){
		res++;
		return;
	}
	for(int i=1;i<=n;i++){
		if(flag[i])continue;
		if(s[t]=='0'){
			flag[i]=1;
			solve(t+1,cnt,fail+1);
			flag[i]=0;
		}else{
			flag[i]=1;
			if(fail>=c[i])solve(t+1,cnt,fail+1);
			else solve(t+1,cnt+1,0);
			flag[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
//	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("\n%s\n",s+1);
	for(int i=1;i<=n;i++)
		scanf("%d",&c[i]);
	sort(c+1,c+n+1,cmp);
	int cnt=0,fai=0,cnt0=0;
	for(int i=1;i<=n;i++){
		if(c[i]==0)cnt0++;
		if(s[i]=='1'){
			cnt++;
			pos[cnt-1]=fai;
			fai=0;
		}else{
			flagA=0;
			fai++;
		}
	}
	if(n<=10){
		solve(1,0,0);
		printf("%lld\n",res);
		return 0;
	}
	if(cnt<m||n-cnt0<m){
		printf("0");
		return 0;
	}
	if(m==1&&cnt0>=cnt){
		long long ans=1;
		for(int i=1;i<=n-cnt;i++)
			ans=(ans*i)%p;
		long long sum=0,tem=1;
		for(int i=0;i<cnt;i++)
			tem=(tem*(cnt0-i))%p;
		int temm=1;
		for(int i=0;i<cnt;i++)
			temm=(temm*(n-i))%p;
		sum=(sum-tem+temm)%p;
		ans=(ans*sum)%p;
		printf("%lld\n",ans);
		return 0;
	}
	if((m==0&&cnt0<cnt)||flagA||m==n){
		long long ans=1;
		for(int i=1;i<=n;i++)
			ans=(ans*i)%p;
		printf("%lld\n",ans);
		return 0;
	}
	long long ans=1;
	sort(pos,pos+cnt,cmp);//qian mian si le ji ge
	int j=0;
	for(int i=0;i<cnt;i++){
		while(c[j+1]>pos[i])j++;
		ch[i]=j;//qian j ge neng huo xia lai
	}
	for(int i=1;i<=n;i++)cout<<c[i]<<' ';
	cout<<endl;
	for(int i=0;i<cnt;i++)cout<<pos[i]<<' ';
	cout<<endl;
	for(int i=0;i<cnt;i++)cout<<ch[i]<<' ';
	cout<<endl;
	for(int i=1;i<=n-cnt;i++)
		ans=(ans*i)%p;
	long long sum=0;
	for(int i=0;i<(1<<cnt);i++){
		int num=0,nnum=0,can=1;
		long long tem=1;
		for(int k=0;k<cnt;k++){
			if(i&(1<<k)){
				if(ch[k]-num<=0){
					can=0; break;
				}
				tem=(tem*(ch[k]-num))%p;
				num++;
			}else{
				if(n-ch[k]<=nnum){
					can=0; break;
				}
				tem=(tem*(n-ch[k]-(k-num)))%p;
				nnum++;
			}
		}
		if(num>=m&&can){
			sum=(sum+tem)%p;
		}
	}
	ans=(ans*sum)%p;
	printf("%lld\n",ans);
	return 0;
}
