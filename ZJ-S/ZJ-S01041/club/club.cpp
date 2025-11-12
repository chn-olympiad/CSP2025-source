#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e5+10;
struct node {
	int ta1,ta2,ta3;
	int ti;
	int tnu;
};
node a[maxn];

bool cnp(node x,node y){
	return x.tnu>y.tnu;
}

int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	
	int T;
	cin>>T;
	while(T--){
		
		int n;
		cin>>n;
//		cout<<n<<' ';
		for(int i=1; i<=n; i++) {
			cin>>a[i].ta1>>a[i].ta2>>a[i].ta3;
		}
		for(int i=1;i<=n;i++){
			if(a[i].ta1<=a[i].ta2&&a[i].ta1<=a[i].ta3){
				a[i].ti=1;
				a[i].tnu=abs(a[i].ta2-a[i].ta3);
			}
			else if(a[i].ta2<=a[i].ta3&&a[i].ta2<=a[i].ta1){
				a[i].ti=2;
				a[i].tnu=abs(a[i].ta1-a[i].ta3);
			}
			else{
				a[i].ti=3;
				a[i].tnu=abs(a[i].ta1-a[i].ta2);
			}
		}
		sort(a+1,a+1+n,cnp);
		int s1=0,s2=0,s3=0;
		int ans=0;
		for(int i=1;i<=n;i++){
			if(a[i].ti==1){
				if(a[i].ta2>a[i].ta3){
					if(s2<n/2){
						s2++;
						ans+=a[i].ta2;
					}
					else{
						s3++;
						ans+=a[i].ta3;
					}
				}
				else{
					if(s3<n/2){
						s3++;
						ans+=a[i].ta3;
					}
					else{
						s2++;
						ans+=a[i].ta2;
					}
				}
			}
			else if(a[i].ti==2){
				if(a[i].ta1>a[i].ta3){
					if(s1<n/2){
						s1++;
						ans+=a[i].ta1;
					}
					else{
						s3++;
						ans+=a[i].ta3;
					}
				}
				else{
					if(s3<n/2){
						s3++;
						ans+=a[i].ta3;
					}
					else{
						s1++;
						ans+=a[i].ta1;
					}
				}
			}
			else{
				if(a[i].ta1>a[i].ta2){
					if(s1<n/2){
						s1++;
						ans+=a[i].ta1;
					}
					else{
						s2++;
						ans+=a[i].ta2;
					}
				}
				else{
					if(s2<n/2){
						s2++;
						ans+=a[i].ta2;
					}
					else{
						s1++;
						ans+=a[i].ta1;
					}
				}
			}
		}
		cout<<ans<<"\n";

	}

	return 0;
}

