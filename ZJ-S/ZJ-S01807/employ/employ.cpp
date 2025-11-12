#include<bits/stdc++.h>
using namespace std;
#define int long long
string s;
const int P=998244353;
int m,n,c[555],cnt;
bool b[555],all1=1;
int p[11];
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
    for(int i=1;i<=n;i++){
        b[i]=s[i-1]=='1';
        all1&=b[i];
        cin>>c[i];
        if(!c[i])cnt++;
    }
    if(n-cnt<m){
        cout<<0;
        return 0;
    }
    if(all1){
        int res=1;
        for(int i=1;i<=n;i++)
            res=(res*i)%P;
        cout<<res;
        return 0;
    }
    if(n>20){cout<<0;return 0;}
    for(int i=1;i<=n;i++)p[i]=i;
    int ans=0;
    do{
        int cnt=0,success=0;
        for(int i=1;i<=n;i++){
        	int j=p[i];
            if(cnt>=c[j]||!b[i])cnt++;
            else {
            	success++;
            	//cout<<"³É¹¦£¡cnt,ci,i="<<cnt<<','<<c[j]<<','<<j<<'\n'; 
			}
        }
        //cout<<success<<'\n';
        //for(int i=1;i<=n;i++)cout<<p[i]<<" \n"[i==n];
        if(success>=m)ans++;
    }while(next_permutation(p+1,p+n+1));
    cout<<ans;
	return 0;
}
//freopen
/*
3 2
101
1 1 2
*/
