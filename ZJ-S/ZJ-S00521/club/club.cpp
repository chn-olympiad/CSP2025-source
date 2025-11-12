#include<bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'
int t; 
int main(){
	fast;
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		long long sum=0;
		int a[n+10],b[n+10],c[n+10],t[n+10],t1[n+10],t2=0,t3=0,t4=0;
		bool f[n+10],f1[n+10],f2[n+10];
		for(int i=1;i<=n;i++){
			int mx=-1,mn=20010,p=0;
			cin>>a[i]>>b[i]>>c[i];
			mx=max(a[i],max(b[i],c[i]));
			if(mx==a[i]&&mx!=b[i]&&mx!=c[i]){
				t2++;
				f[i]=true;
			}
			if(mx==b[i]&&mx!=a[i]&&mx!=c[i]){
				t3++;
				f1[i]=true;
			}
			if(mx==c[i]&&mx!=b[i]&&mx!=a[i]){
				t4++;
				f2[i]=true;
			}
			if(mx==a[i]&&mx==b[i]&&mx!=c[i]){
				if(t2<t3){
					t2++;
					f[i]=true;
				}
				else{
					t3++;
					f1[i]=true;
				}
			}
			if(mx==b[i]&&mx==c[i]&&mx!=a[i]){
				if(t3<t4){
					t3++;
					f1[i]=true;
				}
				else{
					t4++;
					f2[i]=true;
				}
			}
			if(mx==a[i]&&mx==c[i]&&mx!=b[i]){
				if(t2<t4){
					t2++;
					f[i]=true;
				}
				else{
					t4++;
					f2[i]=true;
				}
			}
			if(mx==a[i]&&mx==b[i]&&mx==c[i]){
				if(t2<min(t3,t4)){
					t2++;
					f[i]=true;
				}
				else if(t3<min(t2,t4)){
					t3++;
					f1[i]=true;
				}
				else{
					t4++;
					f2[i]=true;
				}
			}
		}
		if(t2<=(n/2)&&t3<=(n/2)&&t4<=(n/2)){
			for(int i=1;i<=n;i++){
				int mx=-1;
				mx=max(a[i],max(b[i],c[i]));
				sum+=mx;
			}
			cout<<sum<<endl;
		}
		else{
				for(int i=1;i<=n;i++){
				long long mx=0,p=0;
				mx=max(a[i],max(b[i],c[i]));
				if(a[i]>min(b[i],c[i])&&a[i]!=mx){
					p=a[i];
				}
				else if(b[i]>min(a[i],c[i])&&b[i]!=mx){
					p=b[i];
				}
				else{
					p=c[i];
				}
				t[i]=mx-p;
				t1[i]=p;
			}
			sort(t+1,t+1+n);
			for(int i=n;i>(n/2);i--){
				sum+=t[i];
			}
			for(int i=1;i<=n;i++){
				sum+=t1[i];
			}
			cout<<sum<<endl;
		}
	}
	return 0;
} 
