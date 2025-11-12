#include<bits/stdc++.h>
using namespace std;
#include<bits/stdc++.h>
using namespace std;
int a[100005][5];
int A,B,C,x;
long long sum;
int ra[100005],xa;
int rb[100005],xb;
int rc[100005],xc;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while (T--){
		int n,maxN;
		sum=0;
		A=0;
		B=0;
		C=0;
		xa=0;
		xb=0;
		xc=0;
		for (int i=0;i<n;i++){
			ra[i]=0;
			rb[i]=0;
			rc[i]=0;
		}
		cin>>n;
		for (int i=0;i<n;i++){
			maxN=0;
			for (int j=0;j<3;j++){
				cin>>a[i][j];
				maxN=max(maxN,a[i][j]);
			}if (maxN==a[i][0]){
				A++;
				ra[xa++]=min(a[i][0]-a[i][1],a[i][0]-a[i][2]);
			}else if (maxN==a[i][1]){
				B++;
				rb[xb++]=min(a[i][1]-a[i][0],a[i][1]-a[i][2]);
			}else{
				C++;
				rc[xc++]=min(a[i][2]-a[i][1],a[i][2]-a[i][0]);
			}sum+=maxN;
		}if (A>n/2){
			sort(ra,ra+xa);
			x=0;
			while (A>n/2){
				sum-=ra[x++];
				A--;
			}
		}else if (B>n/2){
			sort(rb,rb+xb);
			x=0;
			while (B>n/2){
				sum-=rb[x++];
				B--;
			}
		}else{
			sort(rc,rc+xc);
			x=0;
			while (C>n/2){
				sum-=rc[x++];
				C--;
			}
		}cout<<sum<<endl;
	}
	
	return 0;
} 





