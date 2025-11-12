#include<bits/stdc++.h>
using namespace std;
int a[100000][2],b[100000];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		int n,b1=0,b2=0,b3=0;
		long long sum=0;
		cin>>n;
		for(int j=0;j<n;j++){
		int z,x,c;
		cin>>z>>x>>c;	
		if(z>=x&&x>=c){
			a[j][0]=1;
			a[j][1]=z-x;
			b1++;
			sum+=z;
		} else if(z>=c&&c>=x){
			a[j][0]=1;
			a[j][1]=z-c;
			b1++;
			sum+=z;
		} else if(x>=z&&z>=c){
			a[j][0]=2;
			a[j][1]=x-z;
			b2++;
			sum+=x;
		} else if(x>=c&&c>=z){
			a[j][0]=2;
			a[j][1]=x-c;
			b2++;
			sum+=x;
		} else if(c>=z&&z>=x){
			a[j][0]=3;
			a[j][1]=c-z;
			b3++;
			sum+=c;
		} else if(c>=x&&x>=z){
			a[j][0]=3;
			a[j][1]=c-x;
			b3++;
			sum+=c;
		}
		}
		if(b1>(n/2)){
			int k=0,g=0;
			for(int j=0;j<n;j++)
			if(a[j][0]==1){
				b[k]=a[j][1];
				k++;
			}
			sort(b,b+k);
			for(int j=b1-(n/2);j>0;j--){
				sum-=b[g];
				g++;
			}
		} else if(b2>(n/2)){
			int k=0,g=0;
			for(int j=0;j<n;j++)
			if(a[j][0]==2){
				b[k]=a[j][1];
				k++;
			}
			sort(b,b+k);
			for(int j=b2-(n/2);j>0;j--){
				sum-=b[g];
				g++;
			}
		} else if(b3>(n/2)){
			int k=0,g=0;
			for(int j=0;j<n;j++)
			if(a[j][0]==3){
				b[k]=a[j][1];
				k++;
			}
			sort(b,b+k);
			for(int j=b3-(n/2);j>0;j--){
				sum-=b[g];
				g++;
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}
