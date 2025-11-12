#include<bits/stdc++.h>
using namespace std;
int t,n,a,b,c,p[5][100010],ans;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		ans=0;
		int cnt[5]={0};
		for(int i=1;i<=n;i++){
			cin>>a>>b>>c;
			if(a>=b&&a>=c){
				ans+=a;
				cnt[1]++;
				if(b>=c){
					p[1][cnt[1]]=a-b;
				}else{
					p[1][cnt[1]]=a-c;
				}
			}
			else if(b>=a&&b>=c){
				ans+=b;
				cnt[2]++;
				if(a>=c){
					p[2][cnt[2]]=b-a;
				}else{
					p[2][cnt[2]]=b-c;
				}
			}
			else{
				ans+=c;
				cnt[3]++;
				if(b>=a){
					p[3][cnt[3]]=c-b;
				}else{
					p[3][cnt[3]]=c-a;
				}
			}
		}
		if(cnt[1]>(n/2)){
			sort(p[1]+1,p[1]+1+cnt[1]);
			for(int i=1;i<=(cnt[1]-(n/2));i++){
				ans-=p[1][i];
			}
		}
		if(cnt[2]>(n/2)){
			sort(p[2]+1,p[2]+1+cnt[2]);
			for(int i=1;i<=(cnt[2]-(n/2));i++){
				ans-=p[2][i];
			}
		}
		if(cnt[3]>(n/2)){
			sort(p[3]+1,p[3]+1+cnt[3]);
			for(int i=1;i<=(cnt[3]-(n/2));i++){
				ans-=p[3][i];
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
