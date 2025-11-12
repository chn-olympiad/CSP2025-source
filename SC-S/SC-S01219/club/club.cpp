#include<bits/stdc++.h>
using namespace std;

bool cmp(int a,int b){
	if(abs(a)<abs(b)) return false;
	return true;
}

const int N=1e+5;
int a[N+10][5];
int b[N+10];
int c[N+10];
int num[5];

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","r",stdout);
	
	int t;
	cin>>t;
	
	int n;
	while(t--){
		cin>>n;
		bool f1=0;
		bool f2=0;
		for(int i=1; i<=n; i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(a[i][2]!=0) f1=1;
			if(a[i][3]!=0) f2=1;
		}
		
		if(f1==0 && f2==0){
			for(int i=1; i<=n; i++){
				b[i]=a[i][1];
			}
			sort(b+1,b+n+1);
			int sum=0;
			for(int i=n/2; i<=n; i++){
				sum+=b[i];
			}
			cout<<sum<<endl;
		}else if(f2==0){
			int sum=0;
			for(int i=1; i<=n; i++){
				sum+=a[i][1];
			}
			for(int i=1; i<=n; i++){
				b[i]=a[i][1]-a[i][2];
			}
			sort(b+1,b+n+1,cmp);
			num[1]=0,num[2]=0;
			for(int i=1; i<=n; i++){
				if(b[i]>0 && num[1]<n/2){
					num[1]++;
				}else if(b[i]<0 && num[2]<n/2){
					sum-=b[i];
					num[2]++;
				}else if(b[i]==0){
					continue;
				}else if(b[i]>0){
					sum-=b[i];
					num[2]++;
				}else{
					num[1]++;
				}
			}
			cout<<sum<<endl;
		}else{
			int sum=0;
			for(int i=1; i<=n; i++){
				if(a[i][1]>=a[i][2] && a[i][1]>=a[i][3]){
					b[i]=1; 
					c[i]=a[i][1]-max(a[i][2],a[i][3]);
				}else if(a[i][2]>=a[i][1] && a[i][2]>=a[i][3]){
					b[i]=2;
					c[i]=a[i][2]-max(a[i][1],a[i][3]);
				}else{
					b[i]=3;
					c[i]=a[i][3]-max(a[i][1],a[i][2]);
				}
				sum+=a[i][b[i]];
			}
			int t[5]={0};
			for(int i=1; i<=n; i++){
				t[b[i]]++;
			}
			if(t[1]<=n/2&&t[2]<=n/2&&t[3]<=n/2){
				cout<<sum<<endl;
			}else{
				int g;
				if(t[1]>n/2) g=1;
				else if(t[2]>n/2) g=2;
				else g=3;
				
				int p=0;
				for(int i=1; i<=n; i++){
					if(b[i]==g){
						p++;
						c[p]=c[i];
						
					}
				}
				
				sort(c+1,c+p+1);
				t[g]-=n/2;
				
				p=1;
				while(t[g]>0){
					sum-=c[p];
					p++;
					t[g]--;
				}
				
				cout<<sum<<endl;
			}
		}
	}
	
	return 0;
}
