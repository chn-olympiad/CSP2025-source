#include<bits/stdc++.h>//¶à×é²âÊÔ 
using namespace std;
int t,n;
int a[100005][5],b[100005];
int ju[5];
int min2=0x3f3f3f3f;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		memset(a,0,sizeof a);
		memset(b,0,sizeof b);
		int ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		if(a[1][2]==0&&a[1][3]==0){
			for(int i=1;i<=n;i++){
				for(int i=1;i<=n;i++){
					b[i]=a[i][1];
				}
				sort(b+1,b+n+1,greater<int>());
				for(int i=1;i*2<=n;i++){
					ans+=b[i];
				}
				cout<<ans<<"\n";
				break;
			}
		}else if(n==2){
			int c=a[1][1],d=a[1][2],e=a[1][3],f=a[2][1],g=a[2][2],h=a[2][3];
			if(c>d&&c>e&&f>g&&f>h){
				ans=c+f;
				if(min(abs(c-d),abs(c-e))<min(abs(f-g),abs(f-h))){
					ans-=min(abs(c-d),abs(c-e));
				}else if(min(abs(c-d),abs(c-e))>min(abs(f-g),abs(f-h))){
					ans-=min(abs(f-g),abs(f-h));
				}
			}else if(d>c&&d>e&&g>f&&g>h){
				ans=d+g;
				if(min(abs(c-d),abs(d-e))<min(abs(f-g),abs(g-h))){
					ans-=min(abs(c-d),abs(d-e));
				}else if(min(abs(c-d),abs(d-e))>min(abs(f-g),abs(g-h))){
					ans-=min(abs(f-g),abs(g-h));
				}
			}else if(e>d&&e>c&&h>g&&h>f){
				ans=e+h;
				if(min(abs(e-d),abs(c-e))<min(abs(h-g),abs(f-h))){
					ans-=min(abs(e-d),abs(c-e));
				}else if(min(abs(e-d),abs(c-e))>min(abs(h-g),abs(f-h))){
					ans-=min(abs(h-g),abs(f-h));
				}
			}else{
				ans=max(max(max(c,d),e),max(max(f,h),g));
			}
			cout<<ans<<"\n";
		}else{
			for(int i=1;i<=n;i++){
				ans+=max(max(a[i][1],a[i][2]),a[i][3]);
			}
			cout<<ans<<"\n";
		}
	}
	return 0;
}
