#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
const int N=1e5+10;
int t;
int n;
int ar[N][5];
struct node{
	int x,id;
}br[N];
int a[N],b[N],c[N];
int sum[N];
int ans;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>t;
	while(t--){
		int cnt1=0,cnt2=0,cnt3=0;
		memset(br,0,sizeof br);
		cin>>n;
		int res=n/2;
		ans=0;
		for(int i=1;i<=n;i++){	
			sum[i]=1e9;
		}
		for(int i=1;i<=n;i++){
			int id=1;
			for(int j=1;j<=3;j++){
				cin>>ar[i][j];
				if(br[i].x<ar[i][j]){
					br[i].x=ar[i][j];
					id=j;
				}
			}
			ans+=br[i].x;
			br[i].id=id;
			for(int j=1;j<=3;j++){
				if(j!=id) {
					sum[i]=min(br[i].x-ar[i][j],sum[i]);
				}
			}
		}
		for(int i=1;i<=n;i++){
			if(br[i].id==1){
				a[++cnt1]=sum[i];
			} 
			else if(br[i].id==2){
				b[++cnt2]=sum[i];
			}
			else{
				c[++cnt3]=sum[i];
			}
		}
		//cout<<cnt1<<' '<<cnt2<<' '<<cnt3<<endl;
		if(cnt1>res){
			sort(a+1,a+cnt1+1);
			int i=1;
			while(cnt1-i+1>res){
				ans-=a[i];
				i++;
			}
		}
		else if(cnt2>res){
			sort(b+1,b+cnt2+1);
			int i=1;
			while(cnt2-i+1>res){
				ans-=b[i];
				i++;
			}
		}
		else{
			sort(c+1,c+cnt3+1);
			int i=1;
			while(cnt3-i+1>res){
				ans-=c[i];
				i++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
/*
3
4 
5 3 4
3 2 4
4 2 1
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
