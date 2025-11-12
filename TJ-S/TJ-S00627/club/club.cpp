#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	struct P{
		int f,g,h; 
	};
	while(t--){
		int n,ans=0;
		cin>>n;
		int a[n];
		P b;
		for(int i=0;i<n;i++)
		{
			int x,y,z;
			cin>>x>>y>>z;
			if(x>y&&x>z){
				a[i]=x;
				b.f++;
			}
			else if(y>x&&y>z){
				a[i]=y;
				b.g++;
			}
			else if(z>x&&z>y){
				a[i]=z;
				b.h++;
			}
		}
		for(int i=0;i<n;i++){
			ans+=a[i];
		}
		cout<<ans;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
