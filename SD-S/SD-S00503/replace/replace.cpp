#include<bits/stdc++.h>
using namespace std;
int n,q,cnt;
struct ap{
	string a,b;
}a[2000005];
ap b;
int main(){
	cin.tie(0);
	cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=0;i<n;i++){
		cin>>a[i].a>>a[i].b;
	}
	while(q--){
		cnt=0;
		cin>>b.a>>b.b;
		for(int i=0;i<n;i++){
			if(a[i].a==b.a&&a[i].b==b.b){
				cnt++; 
			}
			for(int l=0,r=a[i].a.size()-1;l<=r;){
				if(r-l>b.a.size()){
					l++;
				}
				else{
					cnt++;
					break;
				}
			}
		}
		cout<<cnt-3<<endl;
	}
	
	return 0;
}

