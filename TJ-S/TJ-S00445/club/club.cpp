#include <bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		long long ans=0;
		int a[100005]={0},b[100005]={0},c[100005]={0},f1[20004]={0},f2[20004]={0},f3[20004]={0};
		int s1=0,s2=0,s3=0,s4=0,f[100005];
		//int j=0,k=0,a1[100005]={0},b1[100005]={0};
		//int j1=0,j2=0,j3=0,a2[100005]={0},b2[100005]={0},c2[100005]={0};
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			f1[a[i]]++;
			f2[b[i]]++;
			f3[c[i]]++;
			if(a[i]>b[i]&&a[i]>c[i]){
				s1++;
				f[i]=1;
			}else if(b[i]>a[i]&&b[i]>c[i]){
				s2++;
				f[i]=2;
			}else if(c[i]>b[i]&&a[i]<c[i]){
				s3++;
				f[i]=3;
			}
			else s4++;
		}
		if(s1<=n/2&&s2<=n/2&&s3<=n/2){
			for(int i=1;i<=n;i++){
				if(a[i]>=b[i]&&a[i]>=c[i]) ans+=a[i];
				else if(b[i]>=a[i]&&b[i]>=c[i]) ans+=b[i];
				else if(c[i]>=b[i]&&a[i]<=c[i]) ans+=c[i];
			}
			cout<<ans<<"\n";
			continue;
		}else if(s1==n){
			sort(a+1,a+1+n,cmp);
			for(int i=1;i<=(n+1)/2;i++){
				ans+=a[i];
			}
			cout<<ans<<"\n";
			continue;
		}/*else if(s1+s2==n){
			
			for(int i=1;i<=n;i++){
				if(f[i]==1){
					j++;
					a1[j]=a[i];
				}
				else{
					k++;
					b1[k]=b[i];
				}
			}
			sort(a1+1,a1+1+j,cmp);
			sort(b1+1,b1+1+k,cmp);
			for(int i=1;i<=(n+1)/2;i++){
				ans+=a1[i];
				ans+=b1[i]; 
			}
			cout<<ans<<"\n";
			continue; 
		}
		for(int i=1;i<=n;i++){
			if(f[i]==1){
				j1++;
				a2[j1]=a[i];
			}else if(f[i]==2){
				j2++;
				b2[j2]=b[i];
			}else{
				j3++;
				c2[j3]=c[i];
			}
		}
		sort(a2+1,a2+1+j1,cmp);
		sort(b2+1,b2+1+j2,cmp);
		sort(c2+1,c2+1+j3,cmp);
		for(int i=1;i<=(n+1)/2;i++){
			ans+=a2[i];
			ans+=b2[i];
			ans+=c2[i]; 
		}
		cout<<ans<<"\n";*/
	}
	return 0;
}
