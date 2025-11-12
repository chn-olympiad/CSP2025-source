#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
long long n,a[100005][4],ans,b[100005],m[4],o[4],fc[100005];
int flaga=1,flagb=1; 
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
				if(j==2&&a[i][j]!=0){
					 flaga=0;
				}
				if(j==3&&a[i][j]!=0){
					flaga=0;
					flagb=0;
				}
			}
		}
		if(flaga){
			for(int i=1;i<=n;i++){
				b[i]=a[i][1];
			}
			sort(b+1,b+n+1);
			for(int i=n;i>n/2;i--){
				ans+=b[i];
			}
			cout<<ans;
			return 0;
		}
		if(n==2){
			long long x,y,maxa,maxb;
			for(int i=1;i<=3;i++){
				m[i]=a[1][i];
				o[i]=a[2][i];
			}
			for(int i=1;i<=3;i++){
				if(m[i]==max(m[1],max(m[2],m[3]))) maxa=i;
				if(o[i]==max(o[1],max(o[2],o[3]))) maxb=i;
			}
			
			if(maxa!=maxb){
				ans+=m[maxa];
				ans+=o[maxb];
			}else{
				sort(m+1,m+4);
				sort(o+1,o+4);
				if((m[3]-m[2])>(o[3]-o[2])){
					ans+=m[3];
					ans+=o[2];
				}else{
					ans+=o[3];
					ans+=m[2];
				}
			}
			cout<<ans;
			return 0;
		}
	}
	if(flagb){
		for(int i=1;i<=n;i++){
			fc[i]=a[i][1]-a[i][2];
		}
		
		long long maxfc=-1e18,flag;
		for(int j=1;j<=n/2;j++){
			maxfc=-1e18;
			for(int i=1;i<=n;i++){
				if(maxfc<=fc[i]){
					maxfc=fc[i];
					flag=i;
				}
				
			}
//			cout<<fc[flag]<<" "<<a[flag][1]<<" "<<flag<<endl;
			ans+=a[flag][1];
			fc[flag]=-1e18;
		}
		for(int i=1;i<=n;i++){
			if(fc[i]!=-1e18){
				ans+=a[i][2];
			}
			
		}
		cout<<ans;
		return 0;
	} 
	cout<<0;
	
	return 0;
}