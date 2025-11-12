#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define endl '\n'
#define int long long
using namespace std;
const int mod=998244353;
const int N=5005;
int a[N];
bool cmp(int x,int y){
    return x>y;
}
int n;
int b2[N];
int ans;
vector<int>v;
void dfs(int x,int sum,int ma){
	if(sum>ma*2&&ma!=-1&&x==n+1){
		ans++;
		return ;
	}
	if(x==n+1)return ;
	dfs(x+1,sum,ma);
	dfs(x+1,sum+a[x],max(ma,a[x]));
}
signed main(void){
    IOS;
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
//    b2[0]=1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
//        b2[i]=(b2[i-1]*2)%mod;
    }
    dfs(1,0,-1);
    cout<<ans<<endl;
//    sort(a+1,a+1+n,cmp);
//    for(int i=1;i<n;i++){
//        int sum=a[i]+a[i+1];
//        int l=i+1,r=i+1;
//        while(l<=r&&r<n){
//            while(r-l+1+1<3&&r<n){
//                r++;
//                sum+=a[r];
//            }
//            while(sum<=a[i]*2&&r<n){
//                r++;
//                sum+=a[r];
//            }
//            while(sum>a[i]*2&&l<r){
//                ans=(ans+b2[n-r])%mod;
//                sum-=a[l];
//            }
//        }
//    }
//    int cnt=a[1];
//    for(int j=1;j<=n;j++){
//		cnt+=a[j+1];
//	    for(int i=1;i<n-(j+1);i++){
//	        int sum=cnt+a[j+3];
//	        int l=i+3,r=i+3;
//	        while(l<=r&&r<n){
//	            while(r-l+1+2<3&&r<n){
//	                r++;
//	                sum+=a[r];
//	            }
//	            while(sum<=a[i]*2&&r<n){
//	                r++;
//	                sum+=a[r];
//	            }
//	            while(sum>a[i]*2&&l<=r){
//	                ans=(ans+b2[n-r])%mod;
//	                sum-=a[l];
//	                if(l<r)
//	                l++;
//	            }
//	        	if(r==l&&r<n){
//	        		r++;
//	                sum+=a[r];
//				}
// 	       }
//	    }
//	}
//    cout<<ans<<endl;
	
    return 0;
}