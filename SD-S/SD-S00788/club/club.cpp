#include<bits/stdc++.h>
using namespace std;
int n,t;//100010,20010
int a[100010][4],c[4];
long long s[4];
int main(){
	freopen("club.in","r",stdin); 
	freopen("club.out","w",stdout);
	cin>>t;
	for(int o=1;o<=t;o++){
		for(int i=1;i<=3;i++){
			s[i]=c[i]=0;
		}
		
		cin>>n;
		int mid=n/2;
		if(n==4||n==2){
			for(int i=1;i<=n;i++)cin>>a[i][1]>>a[i][2]>>a[i][3];
			int mm=0;
			if(n==2){
				for(int i=1;i<=3;i++){
					for(int j=1;j<=3;j++){
					if(j!=i)mm=max(mm,a[1][i]+a[2][j]);
				}
				}
				
			}
			else{int h[4];
				for(int i=1;i<=3;i++)
					for(int j=1;j<=3;j++)
					for(int k=1;k<=3;k++)
					for(int p=1;p<=3;p++){
						
						h[1]=h[2]=h[3]=0;
						h[i]++;h[j]++;
						h[p]++;h[k]++;
						if(h[1]<3&&h[2]<3&&h[3]<3)
						mm=max(mm,a[1][i]+a[2][j]+a[3][k]+a[4][p]);
					//cout<<mm<<" ";
					}
				
			}
			cout<<mm<<endl;
		}
		
		else{
			int p1=0,p2=0;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			p1=max(a[i][2],p1);
			p2=max(a[i][3],p2);
			a[i][0]=1;
			if(a[i][2]>a[i][1])a[i][0]=2;
			if(a[i][3]>a[i][ a[i][0] ])a[i][0]=3;
		}
		if(p1==0&&p2==0){
				int u[100010],mm=0;
				for(int i=1;i<=n;i++)u[i]=a[i][1];
				sort(u+1,u+1+n);
				for(int i=n;i>mid;i--)mm+=a[i][1];
				cout<<mm<<endl;
		}
		
		else{
			for(int i=1;i<=n;i++){
			
			if(c[a[i][0]]<mid){
				s[ a[i][0] ]+=a[i][ a[i][0] ];
			    c[a[i][0]]++;
				
			}
			else {
				int k1=0,k2=0;
				for(int y=1;y<=3;y++)if(c[y]<mid&&k1<a[i][y]){
					k1=a[i][y];
					k2=y;
				}
				s[k2]+=k1;
				c[k2]++;
			}
			
		}
	    cout<<s[1]+s[2]+s[3];
	    cout<<endl;	
			
		}
		
		}
	}
} 


