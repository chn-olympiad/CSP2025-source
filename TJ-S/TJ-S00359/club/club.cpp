#include<bits/stdc++.h> 
using namespace std;
int n;
struct node{
	int a1,b,c;
}a[2020];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	int ai=0;
	int bi=0;
	int ans;
	cin>>t;
	while(t--){
		ai=1;
		bi=0;
		ans=0;
		cin>>n;
		for(int i=1;i<=n;++i){
			cin>>a[i].a1>>a[i].b>>a[i].c;
			
			if(a[i].a1>a[i].b){
				if(ai<=n/2){
					ans+=a[i].a1;
					ai++;
				}
					
			}
			else{
				if(bi<=n/2){
					ans+=a[i].b;
					bi++;
				}
			}
			
		}
		
			
		cout<<ans;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

