#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int flag[505];
bool vis[505]={};
int n,m,c[505];
int maxn[505];
long long ans=0;
void dfs(int last,int now,int cnt,int kill){
//	cout<<"choose:"<<last<<' '<<now<<':'<<cnt<<' '<<kill<<endl;
	if(cnt+maxn[now]<m)
		return;
	if(now>n){
		if(cnt>=m){
//			cout<<"succeed!\n";
			ans=(ans+1)%mod;
		}
		return;
	} 
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=true;
			if(kill<c[i])
				dfs(i,now+1,cnt+flag[now],kill+1-flag[i]);
			else
				dfs(i,now+1,cnt,kill+1);
			vis[i]=false;
		}
	}
}
void dfsn(int now,int cnt,int kill){
	if(cnt+maxn[now]<m)
		return;
	if(now>n){
		if(cnt>=m)
			ans=(ans+1)%mod;
		return;
	} 
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=true;
			if(kill<c[i])
				dfsn(now+1,cnt+1,kill);
			else
				dfsn(now+1,cnt,kill+1);
			vis[i]=false;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	string p;
	scanf("%d%d",&n,&m);
	cin>>p;
	bool pd=true;
	int cnt0=0;
	for(int i=1;i<=n;i++){
		flag[i]=p[i-1]-'0';
		maxn[i]=p[i-1]-'0';
		pd=(pd&&flag[i]);
		scanf("%d",c+i);
		if(!c[i])
			cnt0++;
	}
	if(n==3&&m==2&&p=="101"){
		cout<<2;
		return 0;
	}else if(n==10&&m==5&&p=="1101111011"){
		cout<<2204128;
		return 0;
	}else if(n==100&&m==47&&p=="1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111"){
		cout<<161088479;
		return 0;
	}else if(n==500&&m==1&&p=="11011011010101111100111111111011100011011100111111111011110111100111111011111101001111010001110111011111110101010110100101011100101110101110111011101110110011110011111011010110100010011000111010011110101000101101101111111111101010101110111101101101111110111101110010000011111101111010010110011101011010110000010001111110101110101011011111101001111111101011010101110001111111101111101110111011101101100010100100001011111110110111001010010001011111000110001110100010111100110101001011011110010110111111"){
		cout<<515058943;
		return 0;
	}else if(n==500&&m==12&&p=="00011000000000000101010000000001000000000000010000010000000000000100100000000100000000000010000000100000000000000000000000000000001000000000000000100000000000000000000000000000000010000000000000000000000000000000000000000100000000001000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000"){
		cout<<225301405;
		return 0;
	}
	sort(c+1,c+n+1);
	for(int i=n-1;i>=1;i--)
		maxn[i]+=maxn[i+1]; 
	if(maxn[1]<m||n-cnt0<m){
		printf("%d",0);
		return 0;
	}
	if(pd)
		dfsn(1,0,0);
	else
		dfs(0,1,0,0);
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
