#include<bits/stdc++.h>
using namespace std;
long long t,n;
vector <int> q1;
vector <int> q2;
vector <int> q3;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		long long p=0,q=0,r=0,ans=0;
		for(int i=1;i<=n;i++){
			int a,b,c;
			cin>>a>>b>>c;
			q1.push_back(a);
			q2.push_back(b);
			q3.push_back(c);
		}
		for(int i=1;i<=n;i++){
			int a=q1.back();
			int b=q2.back();
			int c=q3.back();
			if(a>=b&&a>=c){
				if(p<(n/2)){
					p++;
					ans+=a;
					q1.pop_back();
					continue;
				}else if(b>=c){
					if(q<(n/2)){
						q++;
						ans+=b;
						q2.pop_back();
						continue;
					}else{
						r++;
						ans+=c;
						q3.pop_back();
						continue;
					}
				}else{
					if(r<(n/2)){
						r++;
						ans+=c;
						q3.pop_back();
						continue;
					}else{
						q++;
						ans+=b;
						q2.pop_back();
						continue;
					}
				}
			}
			if(b>=a&&b>=c){
				if(q<(n/2)){
					q++;
					ans+=b;
					q2.pop_back();
					continue;
				}else if(a>=c){
					if(p<(n/2)){
						p++;
						ans+=a;
						q1.pop_back();
						continue;
					}else{
						r++;
						ans+=c;
						q3.pop_back();
						continue;
					}
				}else{
					if(r<(n/2)){
						r++;
						ans+=c;
						q3.pop_back();
						continue;
					}else{
						p++;
						ans+=a;
						q1.pop_back();
						continue;
					}
				}
			}
			if(c>=b&&c>=a){
				if(r<(n/2)){
					r++;
					ans+=c;
					q3.pop_back();
					continue;
				}else if(b>=a){
					if(q<(n/2)){
						q++;
						ans+=b;
						q2.pop_back();
						continue;
					}else{
						p++;
						ans+=a;
						q1.pop_back();
						continue;
					}
				}else{
					if(p<(n/2)){
						p++;
						ans+=a;
						q1.pop_back();
						continue;
					}else{
						q++;
						ans+=b;
						q2.pop_back();
						continue;
					}
				}
			}
		}
		cout<<ans<<endl;
		while(!q1.empty()){
			q1.pop_back();
		}
		while(!q2.empty()){
			q2.pop_back();
		}
		while(!q3.empty()){
			q3.pop_back();
		}
	}
	return 0;
}
