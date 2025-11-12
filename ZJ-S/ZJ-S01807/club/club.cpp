#include<bits/stdc++.h>
//#define int long long
using namespace std;
const int N=1e5+5;
int t,n,a[N],b[N],c[N],ans;
priority_queue<int,vector<int>,greater<int> >qa,qb,qc;
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
    while(t--){
        cin>>n;
        ans=0;
        while(qa.size())qa.pop();
        while(qb.size())qb.pop();
        while(qc.size())qc.pop();
        for(int i=1;i<=n;i++){
            cin>>a[i]>>b[i]>>c[i];
            if(a[i]>=b[i]&&a[i]>=c[i]){
                ans+=a[i];
                qa.push(a[i]-max(b[i],c[i]));
                if(qa.size()>n/2){
                    ans-=qa.top();
                    qa.pop();
                }
            }
            else if(b[i]>=a[i]&&b[i]>=c[i]){
                ans+=b[i];
                qb.push(b[i]-max(a[i],c[i]));
                if(qb.size()>n/2){
                    ans-=qb.top();
                    qb.pop();
                }
            }
            else if(c[i]>=b[i]&&c[i]>=a[i]){
                ans+=c[i];
                qc.push(c[i]-max(b[i],a[i]));
                if(qc.size()>n/2){
                    ans-=qc.top();
                    qc.pop();
                }
            }
        }
        cout<<ans<<'\n';
    }
	return 0;
}
/*
//freopen
zai luogu shang guanzhu uid 1283951 !!!!
*/
