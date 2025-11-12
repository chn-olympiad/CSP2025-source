#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		long long ans=0,n,x,y,z;
		long long a=0,b=0,c=0;
		cin>>n;
		if(n==2){
			cin>>x>>y>>z;
			int s=max(max(x,y),z);
			int g=0;
			if(x>y>z){
				g=y;
				b++;
			}
			else if(x>z>y){
				g=z;
				c++;
			}
			else if(y>z>x){
				g=z;
				c++;
			}
			else if(y>x>z){
				g=x;
				a++;
			}
			else if(z>x>y){
				g=x;
				a++;
			}
			else if(z>y>x){
				g=y;
				y++;
			}
			cin>>x>>y>>z;
			int p=max(max(x,y),z);
			if(p==x&&a<n/2){
				int o=p+s;
				int f=p+g;
				ans+=max(o,f);
				cout<<ans<<endl;
				break;
			}
			else if(p==y&&b<n/2){
				int o=p+s;
				int f=p+g;
				ans+=max(o,f);
				cout<<ans<<endl;
				break;
			}
			else if(p==z&&c<n/2){
				int o=p+s;
				int f=p+g;
				ans+=max(o,f);
				cout<<ans<<endl;
				break;
			}
			else if(p==x&&a>=n/2){
				p=max(z,y);
				int o=p+s;
				int f=p+g;
				ans+=max(o,f);
				cout<<ans<<endl;
				break;
			}
			else if(p==y&&b>=n/2){
				p=max(z,x);
				int o=p+s;
				int f=p+g;
				ans+=max(o,f);
				cout<<ans<<endl;
				break;
			}
			else if(p==z&&c>=n/2){
				p=max(x,y);
				int o=p+s;
				int f=p+g;
				ans+=max(o,f);
				cout<<ans<<endl;
				break;
			}
		}
		for(int i=1;i<=n;i++){
			cin>>x>>y>>z;
			if(x>y&&x>z&&a<n/2){
				ans+=x;
				a++;
			}
			else if(y>x&&y>z&&b<n/2){
				ans+=y;
				b++; 
			}
			else if(z>x&&z>y&&c<n/2){
				ans+=z;
				c++; 
			}
			else if(x>y&&x>z&&a>=n/2){
				ans+=max(y,z);
				a++; 
			}
			else if(y>x&&y>z&&b>=n/2){
				ans+=max(x,z);
				b++;
			}
			else if(z>x&&z>y&&c>=n/2){
				ans+=max(x,y);
				c++;
			}
			else if(x==y&&y==z&&a<n/2){
				ans+=x;
				a++;
			} 
			else if(x==y&&y==z&&b<n/2){
				ans+=x;
				b++;
			} 
			else if(x==y&&y==z&&c<n/2){
				ans+=x;
				c++;
			} 
			else if(x==y&&z<x&&b>=n/2&&a>=n/2&&c<n/2){
				ans+=z;
				c++;
			} 
			else if(x==z&&y<x&&a>=n/2&&c>=n/2&&b<n/2){
				ans+=y;
				b++;
			} 
			else if(y==z&&x<y&&b>=n/2&&c>=n/2&&a<n/2){
				ans+=x;
				a++;
			} 
			else if(x==y&&z>x&&b>=n/2&&a>=n/2&&c<n/2){
				ans+=z;
				c++;
			} 
			else if(x==z&&y>x&&a>=n/2&&c>=n/2&&b<n/2){
				ans+=y;
				b++;
			} 
			else if(y==z&&x>y&&b>=n/2&&c>=n/2&&a<n/2){
				ans+=x;
				a++;
			} 
		}
		cout<<ans<<endl;
	} 
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
