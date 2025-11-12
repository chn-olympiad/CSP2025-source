#include <bits/stdc++.h>
using namespace std;
constexpr int N=5e2+5;
#define mod (998244353ll)
#define ll long long
ll n,m,c[N],s[N];

ll mul(ll a,ll b){
    ll ans=0;
    for(int i=1;i<=b;i++){
        ans=((ans+a)%mod);
    }
    return ans%mod;
}

ll A(int n,int m){
    if(n==m&&n==0) return 1;
    ll ans=1ll;
    for(ll i=1,j=m;i<=m&&j>=1;i++,j--){
        ans+=(ans*j%mod);
    }
    return ans%mod;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
    cin>>n>>m;
    //cerr<<n<<' '<<m<<endl;
    bool flag=1;
    for(int i=1;i<=n;i++){
        cin>>s[i];
        //cerr<<s[i]<<' ';
        if(s[i]==0) flag=0;
    }
    //cerr<<endl;
    for(int i=1;i<=n;i++) cin>>c[i]/*,cerr<<c[i]<<' '*/;
    //cerr<<endl;
    if(flag){
        //cerr<<1;
        printf("%lld",A(n,n)%mod);
        fclose(stdin);
        fclose(stdout);
        return 0;
    }
    //cerr<<2;
    if(m==1){
        //cerr<<3;
        if(find(s+1,s+n+1,1)) /*cerr<<4,*/printf("%lld",A(n,n)%mod);
        else /*cerr<<5,*/printf("%d",0);
        fclose(stdin);
        fclose(stdout);
        return 0;
    }
    //cerr<<6;
    ll p[N];
    for(ll i=1;i<=n;i++)p[i]=i;
    ll ans=0;
    bool giveup[N];
    //cerr<<7;
    /**
    giveup[i] == 1 means that the person i has already given up the face-by-face test
    **/
    while(next_permutation(p+1,p+n+1)){
        //cerr<<8;
        ll pass=0,fail=0;
        memset(giveup,0,sizeof giveup);
        for(ll i=1;i<=n;i++){
            if(giveup[i]==1||fail>c[i])continue;
            if(s[i]==1)pass++;
            else fail++;
            if(fail>c[i]) giveup[i]=1,fail++;
        }
        if(pass==m)ans=(ans+1)%mod;
    }
    //cerr<<10;
    printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
