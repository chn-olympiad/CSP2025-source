#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,t;
bool cc;
int cnt=1;
int a[N],c[N];
int ans;
int main(){
	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		int p=n/2;
		int f=0,s=0,l=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[j];
				c[i]=a[1];
				if(a[2]!=0||a[3]!=0){
					cc=1;
				}
			}
			if(f==p){
				if(s==p) ans+=a[3];
				if(l==p) ans+=a[2];
				else {
					if(max(a[2],a[3])==a[2]) s++;
					else l++;
					ans+=max(a[2],a[3]);
				}
			}
			else if(s==p){
				if(max(a[1],a[3])==a[1]) f++;
					else l++;
					ans+=max(a[1],a[3]);
			}else if(l==p){
				if(max(a[1],a[2])==a[1]) f++;
					else s++;
					ans+=max(a[1],a[2]);
			}else{
				if(max(a[1],max(a[2],a[3]))==a[1]) f++;
				if(max(a[1],max(a[2],a[3]))==a[2]) s++;
				if(max(a[1],max(a[2],a[3]))==a[3]) l++;
				ans+=max(a[1],max(a[2],a[3]));
			}
		//	cout<<ans<<endl;
		}if(cc==0){
			sort(c+1,c+n+1);
				int ans1=0;
					for(int i=n;i>=n/2+1;i--){
						ans1+=c[i]; 
					}
					cout<<ans1<<endl;
				}
		else cout<<ans<<endl;
		ans=0;
	}
	return 0;
}
/*

*/
