#include <bits/stdc++.h>
using namespace std;
int t,n;
int a[100001],b[100001],c[100001];
int sa[100001],sb[100001],sc[100001],ans,bns,cns;
long long sum;
int main(){
	freopen("club.in ","r",stdin);
	freopen("club.out ","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		sum=ans=bns=cns=0;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			if(a[i]>=b[i]&&a[i]>=c[i]){
				sum+=a[i];
				if(b[i]>=c[i]){
					sa[++ans]=a[i]-b[i];
				}else{
					sa[++ans]=a[i]-c[i];
				}
			}else if(b[i]>=c[i]&&b[i]>=a[i]){
				sum+=b[i];
				if(a[i]>=c[i]){
					sb[++bns]=b[i]-a[i];
				}else{
					sb[++bns]=b[i]-c[i];
				}
			}else{
				sum+=c[i];
				if(b[i]>=a[i]){
					sc[++cns]=c[i]-b[i];
				}else{
					sc[++cns]=c[i]-a[i];
				}
			}
		}
		if(ans>=n/2){
			sort(sa+1,sa+1+ans);
			for(int i=1;i<=ans-n/2;i++){
				sum-=sa[i];
			}
		}else if(bns>=n/2){
			sort(sb+1,sb+1+bns);
			for(int i=1;i<=bns-n/2;i++){
				sum-=sb[i];
			}
		}else if(cns>=n/2){
			sort(sc+1,sc+1+cns);
			for(int i=1;i<=cns-n/2;i++){
				sum-=sc[i];
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}
