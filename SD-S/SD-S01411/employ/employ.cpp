#include<bits/stdc++.h>
#define F(i,a,b) for(int i=a;i<=b;i++)
#define R(i,a,b) for(int i=a;i>=b;i--)
using namespace std;
typedef long long ll;
const ll N=1e6+7;
const ll mod=998244353;
ll n,m,c[N],p[N],f[N][20];
string s;
inline ll fr(){
	ll s=0,k=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') k=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		s=(s<<3)+(s<<1)+ch-'0';
		ch=getchar();
	}
	return s*k;
}
inline void fw(int x){
	if(x>9) fw(x/10);
	putchar((x%10)+'0');
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);	
	cin>>n>>m;
	cin>>s;
	s=" "+s;
	F(i,1,n) cin>>c[i];
	if(n<=10){
		F(i,1,n){
			p[i]=i;
		}
		int ans=0;
		do{
			int sum=0,cnt=0;
			F(i,1,n){
				if(sum>=c[p[i]]||s[i]=='0'){
					sum++;
				}
				else cnt++;
			}
			if(cnt>=m){
//				cout<<sum<<" "<<cnt<<"\n";
//				F(i,1,n){
//					cout<<p[i]<<" ";
//				}
//				cout<<"\n";
				ans++;
			}
		}while(next_permutation(p+1,p+n+1));
		cout<<ans<<"\n";
	}
	else if(n<=18){
		f[0][0]=1;
		F(i,1,(1<<n)-1){
			int sum=0;
			F(j,1,n){
				if(((i>>(j-1))&1)==1){
					sum++;
				}
			}
			int pik=sum;
			F(j,1,sum){
				if(s[j]=='0'){
					pik--;
				}
			}
			F(j,0,pik){
				F(k,1,n){
					if(((i>>(k-1))&1)==1){
						int ls=i-(1<<(k-1));
						int can=1;
						if(s[sum]=='0'||sum-j>=c[k]){
							can=0;
						}
//						if(i==7&&j==2) cout<<ls<<" "<<can<<" "<<j-can<<" "<<sum<<" "<<j<<" "<<sum-j<<" "<<s[sum]<<" "<<can<<"\n";
						if(can>j) continue;
						f[i][j]+=f[ls][j-can];
						f[i][j]%=mod;
					}
				}
//				cout<<"i:"<<i<<" j:"<<j<<" "<<f[i][j]<<"\n";
			}
		}
		ll ans=0;
		F(i,m,n){
			ans+=f[(1<<n)-1][i];
			ans%=mod;
		}
		cout<<ans<<"\n";
	}
	return 0;
}
/*
3 2
101
1 1 2

*/
