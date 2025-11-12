#include<bits/stdc++.h>
using namespace std;
#define int long long
int T,a[500010],b[500010],c[500010],fmaxx[500010],smaxx[500010],tmaxx[500010];
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	while(T--){
		int n,cnt1=0,cnt2=0,cnt3=0,ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			cnt1+=b[i];
			cnt2+=c[i];
		}
		if(cnt1==0&&cnt2==0){
			sort(a+1,a+1+n,greater<int>());
			for(int i=1;i<=n/2;i++){
				ans+=a[i];
			}
			cout<<ans<<"\n";
		}
		if(cnt2==0&&cnt1!=0){
			sort(a+1,a+1+n,greater<int>());
			sort(b+1,b+1+n,greater<int>());
			for(int i=1;i<=n/2;i++){
				ans+=a[i];
			}
			for(int i=n/2+1;i<=n;i++){
				ans+=b[i];
			}
			int d1=ans;
			ans=0;
			for(int i=1;i<=n/2;i++){
				ans+=b[i];
			}
			for(int i=n/2+1;i<=n;i++){
				ans+=a[i];
			}
			int d2=ans;
			ans=0;
			cout<<max(d1,d2)<<"\n";
		}
		else{
			cnt1=0,cnt2=0;
			for(int i=1;i<=n;i++){
				fmaxx[i]=max(max(a[i],b[i]),c[i]);
				if(fmaxx[i]==a[i])smaxx[i]=max(b[i],c[i]);
				else if(fmaxx[i]==b[i])smaxx[i]=max(a[i],c[i]);
				else if(fmaxx[i]==c[i])smaxx[i]=max(a[i],b[i]);
				if(fmaxx[i]==a[i]&&smaxx[i]==b[i])tmaxx[i]=c[i];
				else if(fmaxx[i]==a[i]&&smaxx[i]==c[i])tmaxx[i]=b[i];
				else if(fmaxx[i]==b[i]&&smaxx[i]==a[i])tmaxx[i]=c[i];
				else if(fmaxx[i]==b[i]&&smaxx[i]==c[i])tmaxx[i]=a[i];
				else if(fmaxx[i]==c[i]&&smaxx[i]==a[i])tmaxx[i]=b[i];
				else if(fmaxx[i]==c[i]&&smaxx[i]==b[i])tmaxx[i]=a[i];
			}
			for(int i=1;i<=n;i++){
				if(a[i]==fmaxx[i]){
					cnt1++;
				}
				else if(b[i]==fmaxx[i]){
					cnt2++;
				}
				else if(c[i]==fmaxx[i]){
					cnt3++;
				}
			}
			if(cnt1<=n/2&&cnt2<=n/2&&cnt3<=n/2){
				for(int i=1;i<=n;i++){
					ans+=fmaxx[i];
				}
				cout<<ans<<"\n";
			}
			else if(cnt1>n/2||cnt2>n/2||cnt3>n/2){
				int tmp=0;
				sort(fmaxx+1,fmaxx+1+n,greater<int>());
				sort(smaxx+1,smaxx+1+n,greater<int>());
				sort(tmaxx+1,tmaxx+1+n,greater<int>());
				for(int i=1;i<=n/2;i++){
					tmp+=fmaxx[i];
				}
				for(int i=n/2+1;i<=n;i++){
					tmp+=smaxx[i];
				}
				int s1=tmp;
				tmp=0;
				for(int i=1;i<=n/2;i++){
					tmp+=smaxx[i];
				}
				for(int i=n/2+1;i<=n;i++){
					tmp+=fmaxx[i];
				}
				int s2=tmp;
				tmp=0;
				for(int i=1;i<=n/2;i++){
					tmp+=fmaxx[i];
				}
				for(int i=n/2+1;i<=n;i++){
					tmp+=tmaxx[i];
				}
				int s3=tmp;
				tmp=0;
				for(int i=1;i<=n/2;i++){
					tmp+=tmaxx[i];
				}
				for(int i=n/2+1;i<=n;i++){
					tmp+=fmaxx[i];
				}
				int s4=tmp;
				tmp=0;
				for(int i=1;i<=n/2;i++){
					tmp+=smaxx[i];
				}
				for(int i=n/2+1;i<=n;i++){
					tmp+=tmaxx[i];
				}
				int s5=tmp;
				tmp=0;
				for(int i=1;i<=n/2;i++){
					tmp+=tmaxx[i];
				}
				for(int i=n/2+1;i<=n;i++){
					tmp+=smaxx[i];
				}
				int s6=tmp;
				tmp=0;
				ans=max(max(s1,max(s2,max(s3,max(s4,s5)))),s6);
				cout<<ans<<"\n";
			}
		}
	}
	return 0;
}
