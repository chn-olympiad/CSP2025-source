#include<bits/stdc++.h>
#define forf(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
const int N=1e5+5;
bool cmp(int a,int b){
	return a>b;
}
void solve(){
	int n,a[N][4]={},cnt[4]={},exp[4][N]={};
	cin>>n;
	forf(i,1,n) forf(j,1,3) cin>>a[i][j];
	
	if (n==2){
		int mmm1=max((a[1][1]+a[2][2]),(a[1][1]+a[2][3]));
		int mmm2=max((a[1][2]+a[2][1]),(a[1][2]+a[2][3]));
		int mmm3=max((a[1][3]+a[2][1]),(a[1][3]+a[2][2]));
		int uuu=max(mmm1,max(mmm2,mmm3));
		cout<<uuu<<endl;
		return;
	}
	
	else if(a[1][2]==a[1][3]&&a[1][2]==0){
		forf(i,1,5) forf(j,1,2){
			if(a[i][2]>0||a[i][3]>0){
				break;
			}
		}
		int b[N];
		forf(i,1,n) b[i]=a[i][1];
		sort(b+1,b+n+1,cmp);
		int sumcnt=0;
		forf(i,1,n/2) sumcnt+=b[i];
		cout<<sumcnt<<endl;
		return;
	}
	
	
	else{
		long long ans=0;
		forf(i,1,n){
			int mx=max(a[i][1],max(a[i][2],a[i][3]));
			ans+=mx;
		}
		cout<<ans<<endl;
	}
	
	
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	forf(i,1,T) solve();
	return 0;
}

