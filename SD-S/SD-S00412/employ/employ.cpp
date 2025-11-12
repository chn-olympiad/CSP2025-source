#include<bits/stdc++.h>
using namespace std;
int nn[505];
int ren[505];
int mod=998244353;
int xu[20];
int n,m;
int ans=0;
void cz(){
	//我己经找到合规的序列了
	int lu=0;//录取人数 
	int meiguo=0;//没有过的人 
	for(int i=1;i<=n;i++){
		int qukao=0;
		if(ren[xu[i]]>meiguo){
			if(nn[i]==1) lu++;
			qukao=1;
		}
		if((nn[i]==0&&qukao==1)||qukao==0) meiguo++;
	}
	if(lu>=m) ans++;
	ans%=mod;
}
int vis[25];
void dfs(int x){
	if(x==n) cz();
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			xu[x+1]=i;
			vis[i]=1;
			dfs(x+1);
			xu[x+1]=0;
			vis[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int flag=1;//1表示性质1满足 
	cin>>n>>m;
	string s;
	cin>>s;
	for(int i=1;i<=n;i++) cin>>ren[i];
	for(int i=0;i<s.size();i++){
		nn[i+1]=(int)(s[i]-'0');
	}
	for(int i=1;i<=n;i++){
		if(nn[i]==0) flag=0;
	}
	if(flag==1){
		//这时检验一定走的人是否超过走人上限即可
		int no=0;
		for(int i=1;i<=n;i++){
			if(ren[i]==0) no++;
		} 
		int maxx=n-no;//去除之后，剩余的就是一定参加的 
		if(maxx<m){//撑到爆也凑不够 
			cout<<0;
		}
		else{
			int lcq=1;
			for(int i=1;i<=n;i++){
				lcq*=i;
				lcq%=mod;
			}
			cout<<lcq;
		}
	}
	else{
		dfs(0);//我已经选好x个人了，要选只得从第i个人开始选
		cout<<ans<<endl; 
	}
	return 0;
}
