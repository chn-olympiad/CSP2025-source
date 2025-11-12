#include<bits/stdc++.h>
using namespace std;

int t=0,n=0;
int aa = 0,bb = 0,cc = 0,b[100010];
struct gongs{
	int a;
	int b;
	int c;
	
}a[100010];
int main(){
	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	cin>>t;
	while(t--){
		cin>>n;
		aa = bb = cc = 1;
		int sum=0,people=0; 
		
		for(int i=1;i<=n;i++){
			cin>>a[i].a>>a[i].b>>a[i].c;
			b[i]=a[i].a;
		}
	
		sort(b+1,b+n+1);
		for(int i=n;i>0;i--){
			people++;
			if(2*people<=n){
				sum+=b[i];
				
			}
			else{
				break;
			}
			
		}
		cout<<sum<<endl;
	}
	
	
	return 0;
}