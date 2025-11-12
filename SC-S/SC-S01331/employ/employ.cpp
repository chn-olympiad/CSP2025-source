#include<bits/stdc++.h>

#define hyc_qcz_jmr_baoyouwo_AC
#define zty_AK_CSPS_2025

#define rep(i,s,e) for(long long i=s;i<=e;i++)
#define fep(i,s,e) for(long long i=s;i<e;i++)
#define per(i,s,e) for(long long i=s;i>=e;i--)
#define pef(i,s,e) for(long long i=s;i>e;i--)

namespace FastIO{
	template <typename T> inline void read(T &x){
		x=0;
		T f=1;
		T c=getchar();
		for(;!isdigit(c);c=getchar()){
			if(c=='-'){
				f=-1;
			}
		}
		for(;isdigit(c);c=getchar()){
			x=(x<<1)+(x<<3)+(c^48);
		}
		x*=f;
	}
	template <typename T> inline void print(T x){
		if(x<0){
			x=-x;
			putchar('-');
		}
		if(x>9){
			print(x/10);
		}
		putchar((x%10)^48);
	}
}

using namespace std;
using namespace FastIO;
string s;
long long n,m,id,c[505],ans,num;
bool flag,vis[505];
const long long mod=998244353;
void sp(){
	ans=1;
	rep(i,1,n){
		if(c[i]>0){
			num++;
		}
	}
	if(num<m){
		print(0);
	}
	else{
		rep(i,1,n){
			ans*=(n-i+1);
			ans%=mod;
		}
		print(ans);	
	}
}
void spp(){
	fep(i,0,n){
		if(s[i]=='1'){
			id=i+1;
			break;
		}
	}
	rep(i,1,n){
		if(c[i]>=id){
			ans++;
		}
	}
	fep(i,1,n){
		ans*=i;
		ans%=mod;
	}
	print(ans);
}
void dfs(long long now,long long jg){
	if(now==n+1){
		if(n-jg>=m){
			ans++;
		}
	}
	else{
		rep(i,1,n){
			if(vis[i]==1){
				continue;
			}
			vis[i]=1;
			if(s[now-1]=='0'){
//				cout<<now<<" "<<i<<" "<<jg+1<<endl;
				dfs(now+1,jg+1);
				vis[i]=0;
			}
			else{
				if(c[i]>jg){
//					cout<<now<<" "<<i<<" "<<jg<<endl;
					dfs(now+1,jg);
					vis[i]=0;
				}
				else{
					dfs(now+1,jg+1);
					vis[i]=0;
				}
			}
		}	
	}
}
int main(){
	hyc_qcz_jmr_baoyouwo_AC
	zty_AK_CSPS_2025
//	freopen("employ3.in","r",stdin);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	read(n);
	read(m);
	cin>>s;
	fep(i,0,n){
		if(s[i]=='0'){
			flag=1;
		}
		read(c[i+1]);
	}
	if(flag==0){
//		cout<<1<<endl;
		sp();
		return 0;
	}
	if(m==1){
		spp();
		return 0;
	}
	if(n<=10){
		dfs(1,0);
		print(ans);
		return 0;
	}
	dfs(1,0);
	print(ans);
	return 0;	
}