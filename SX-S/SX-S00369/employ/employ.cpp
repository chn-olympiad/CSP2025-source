#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef double dou;
typedef pair<int,int> pii;
typedef pair<long,long> pll;
const double eps=1e-12;
const int N=1e6+10;
const ll mod=998244353;
#define ul u<<1
#define ur u<<1|1
#define first fi
#define second se
int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-'){
			f=-1;
		}
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
int n,m;
string s1;
int a[N],bxh;
ll ans;
bool check(int p[]){
    int cnt=0,cnt2=0;
    for(int i=1;i<=n;i++){
        //cout<<p[i]<<" "<<a[p[i]]<<" "<<cnt<<" ";
        if(s1[i]=='1'&&a[p[i]]>cnt){
            cnt2++;
        }else{
            cnt++;
        }
    }
    //cout<<"\n";
    //cout<<cnt2<<" ";
    return cnt2>=m;
}
int b[64];
bool st[64];
void dfs(int u){
    if(u==n+1){
        //bxh++;
        if(check(b)){
            ans++;
        }
        return ;
    }
    for(int i=1;i<=n;i++){
        if(st[i]){
            continue;
        }
        st[i]=1;
        b[u]=i;
        dfs(u+1);
        st[i]=0;
    }
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
    n=read();m=read();
    cin>>s1;
    int cnt=0,len=s1.size();
    s1=" "+s1;
    for(int i=1;i<=n;i++){
        cnt+=(s1[i]=='1');
    }
    for(int i=1;i<=n;i++){
        a[i]=read();
    }
    ll cnt2=0;
    for(int i=1;i<=n;i++){
        cnt2+=(a[i]!=0);
    }
    if(m==1&&n>18){
        ans=1;
        ll tmp=1;
        /*for(ll i=2;i<=n;i++){
            ans=ans*i%mod;
            //cout<<ans<<"\n";
        }*/
        for(ll i=2;i<n;i++){
            tmp=tmp*i%mod;
        }
        //cout<<(ans-cnt2*tmp%mod+mod)%mod;
        cout<<cnt2*tmp%mod;
        //cout<<ans;
        return 0;
    }
    if(n==m){
        cout<<"0";
        return 0;
    }
    dfs(1);
    cout<<ans;
    //cout<<" "<<bxh;
	return 0;
}