#include<bits/stdc++.h>
using namespace std;
const int MAX=1e5+5;
struct node{
	int aa,bb,cc;
	int mx,mn,ch;
}a[MAX];
bool cmp(node aaa,node bbb){
	if(aaa.ch==bbb.ch) return aaa.mx>bbb.mx;
	return aaa.ch>bbb.ch;
} 
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int A=n/2,B=n/2,C=n/2;
		for(int i=1;i<=n;i++){
			cin>>a[i].aa>>a[i].bb>>a[i].cc;
			int f[4]={0,a[i].aa,a[i].bb,a[i].cc};
			sort(f+1,f+1+3);
			a[i].mx=f[3];
			a[i].ch=f[3]-f[2];
		}
		sort(a+1,a+1+n,cmp);
		int ans=0;
		for(int i=1;i<=n;i++){
			if(a[i].aa==a[i].mx){
				if(A!=0) ans+=a[i].aa,A--;
				else if(a[i].bb>a[i].cc){
					if(B!=0) ans+=a[i].bb,B--;
					else ans+=a[i].cc,C--;
				}
			}else if(a[i].bb==a[i].mx){
				if(B!=0) ans+=a[i].bb,B--;
				else if(a[i].aa>a[i].cc){
					if(A!=0) ans+=a[i].aa,A--;
					else ans+=a[i].cc,C--;
				}
			}else if(a[i].cc==a[i].mx){
				if(C!=0) ans+=a[i].cc,C--;
				else if(a[i].aa>a[i].bb){
					if(A!=0) ans+=a[i].aa,A--;
					else ans+=a[i].bb,B--;
				}
			}
		}
		cout<<ans<<endl;
	}



	return 0;
}

