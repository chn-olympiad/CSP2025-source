#include<bits/stdc++.h>
using namespace std;
int t,n,maxh,maxl,ans,l2,l3,p;
int a[100009];
bool flag;
int main(){
//	freopen("club.in","r",stdin);
//	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		long long l1[3]={};
		for(int i=0;i<n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
			}
		}
		for(int i=0;i<n;i++){
			for(int j=1;j<=3;j++){
			    l[j]+=a[i][j];
		    }
		}
		if(l[0]==0&&l[1]==0){
			flag=false;
			p=2;
		}else if(l[0]=0&&l[2]=0){
			flag=false;
			p=1;
		}else if(l[1]==0&&l[2]==0){
			flag=false;
			p=0;
		}
		if(flag==false){
			cout<<max(a[0][p],max(a[1][p],a[2][p]))<<'\n';
			continue;
		}else{
			for(int i=0;i<n;i++){
				ans+=a[i][j];
			}
			cout<<ans<<'\n';
			continue;
		}
    }
	return 0;
}
