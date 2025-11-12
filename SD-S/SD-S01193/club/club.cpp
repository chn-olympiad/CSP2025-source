#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+10;
int t,n,p,a[N],b[N],c[N],s1[N],s2[N],s3[N];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		p=n/2;
		int ans=0,sum1=0,sum2=0,sum3=0,cnt1=0,cnt2=0,cnt3=0;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			s1[i]=a[i];
			s2[i]=b[i];
			s3[i]=c[i];
			sum1+=s1[i];
			sum2+=s2[i];
			sum3+=s3[i];
		}
		sort(s1+1,s1+1+n,cmp);
		sort(s2+1,s2+1+n,cmp);
		sort(s3+1,s3+1+n,cmp);
		if(!sum3){
			if(!sum2){
				for(int i=1;i<=p;i++){
					ans+=s1[i];
				}
			}else{
				for(int i=1;i<=n;i++){
					if(s2[i]>s1[i]){
						if(cnt2==p){
							ans+=s1[i];
							continue;
						}
						ans+=s2[i];
						cnt2++;
					}else{
						if(cnt1==p){
							ans+=s2[i];
							continue;
						}
						ans+=s1[i];
						cnt1++;
					}
				}
			}
			cout<<ans<<endl;
			continue;
		}
		if(!sum2){
			if(!sum1){
				for(int i=1;i<=p;i++){
					ans+=s3[i];
				}
			}else{
				for(int i=1;i<=n;i++){
					if(s1[i]>s3[i]){
						if(cnt1==p){
							ans+=s3[i];
							continue;
						}
						ans+=s1[i];
						cnt1++;
					}else{
						if(cnt3==p){
							ans+=s1[i];
							continue;
						}
						ans+=s3[i];
						cnt3++;
					}
				}
			}
		}else{
			if(!sum3){
				for(int i=1;i<=n;i++){
					if(s1[i]>s2[i]){
						if(cnt1==p){
							ans+=s2[i];
							continue;
						}
						ans+=s1[i];
						cnt1++;
					}else{
						if(cnt2==p){
							ans+=s1[i];
							continue;
						}
						ans+=s2[i];
						cnt2++;
					}
				}
			}else{
				for(int i=1;i<=n;i++){
					ans+=max(max(s1[i],s2[i]),s3[i]);
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
/*
1
10
10 0 0
20 0 0
30 0 0
40 0 0
50 0 0
60 0 0
70 0 0
80 0 0
90 0 0
10 0 0
*/
