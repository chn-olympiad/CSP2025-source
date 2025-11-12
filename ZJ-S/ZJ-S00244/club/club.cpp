#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
long long T,i,n,j;
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	for(i=1; i<=T; i++) {
		cin>>n;
		int k=0,sum=0,ans1=0,ans2=0,ans3=0,a[n+1][5],q=0,p=0;
		for(j=1; j<=n; j++) {
			cin>>a[j][1]>>a[j][2]>>a[j][3];
			if(a[j][2]==0) q++;
			if(a[j][3]==0) p++;
			if(a[j][1]>=a[j][2]&&a[j][1]>=a[j][3])
				a[j][4]=1;
			if(a[j][2]>=a[j][1]&&a[j][2]>=a[j][3])
				a[j][4]=2;
			if(a[j][3]>=a[j][2]&&a[j][3]>=a[j][1])
				a[j][4]=3;
		}
		if(p==n&&q==n) {
			int paa[100001];
			for(j=1; j<=n; j++)
				paa[j]=a[j][1];
			sort(paa,paa+n+1);
			for(j=n; j>n/2; j--) sum+=paa[j];
		} else {
			int aa[10001],bb[100001],cc[100001];
			for(j=1; j<=100001; j++) aa[j]=bb[j]=cc[j]=0;
			for(j=1; j<=n; j++) {
				if(a[j][4]==1) {
					ans1++;
					sum+=a[j][1];
					aa[ans1]=j;
				} else if(a[j][4]==2) {
					ans2++;
					sum+=a[j][2];
					bb[ans2]=j;
				} else if(a[j][4]==3) {
					ans3++;
					sum+=a[j][3];
					cc[ans3]=j;
				}
			}
			if(ans1>n/2) {
				int x[10001];
				for(j=1; j<=ans1; j++) {
					k++;
					//cout<<a[aa[j]][1]-a[aa[j]][3]<<" "<<a[aa[j]][1]-a[aa[j]][2]<<endl;
					x[k]=min(a[aa[j]][1]-a[aa[j]][3],a[aa[j]][1]-a[aa[j]][2]);
				}
				sort(x,x+k+1);
				for(j=1; j<=ans1-(n/2); j++)
					sum-=x[j];
			}
			if(ans2>n/2) {
				int x[10001];
				for(j=1; j<=ans2; j++) {
					k++;
					x[k]=min(a[bb[j]][2]-a[bb[j]][3],a[bb[j]][2]-a[bb[j]][1]);
				}
				sort(x,x+k+1);
				for(j=1; j<=ans2-(n/2); j++) {
					sum-=x[j];
				}
			} else if(ans3>n/2) {
				int x[10001];
				for(j=1; j<=ans3; j++) {
					k++;
					x[k]=min(a[cc[j]][3]-a[cc[j]][1],a[cc[j]][3]-a[cc[j]][2]);
				}
				sort(x,x+k+1);
				for(j=1; j<=ans3-(n/2); j++)
					sum-=x[j];
			}
		}
		cout<<sum<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}