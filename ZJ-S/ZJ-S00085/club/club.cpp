#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
int t,n,ans,cnt;
vector<int>a,b,c;
signed main(){
    ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
        ans=0;
        a.clear();
        b.clear();
        c.clear();
        cin>>n;
        for(int i=0;i<n;i++){
            int x,y,z;
            cin>>x>>y>>z;
            int sub=max(x,max(y,z));
            if(x==sub){
                a.push_back(min(x-y,x-z));
            }
            else if(y==sub){
                b.push_back(min(y-x,y-z));
            }
            else if(z==sub){
                c.push_back(min(z-y,z-x));
            }
            ans+=sub;
        }
        n>>=1;
        cnt=(int)(a.size());
        if(cnt>n){
            sort(a.begin(),a.end());
            for(int i=0;i<cnt-n;i++){
                ans-=a[i];
            }
            cout<<ans<<endl;
            continue;
        }
        cnt=(int)(b.size());
        if(cnt>n){
            sort(b.begin(),b.end());
            for(int i=0;i<cnt-n;i++){
                ans-=b[i];
            }
            cout<<ans<<endl;
            continue;
        }
        cnt=(int)(c.size());
        if(cnt>n){
            sort(c.begin(),c.end());
            for(int i=0;i<cnt-n;i++){
                ans-=c[i];
            }
            cout<<ans<<endl;
            continue;
        }
        cout<<ans<<endl;
        continue;
	}
	return 0;
}