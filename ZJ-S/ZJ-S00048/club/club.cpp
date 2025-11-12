#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
long long a[N],b[N],c[N];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	long long t;
	cin>>t;
	while(t--){
		long long n;
		cin>>n;
		long long c1=0,c2=0,c3=0,s=0;
		bool cc1=false,cc2=false;
		long long cns=0;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			if(b[i]!=0){
				cc1=true;
			}
			else if(c[i]!=0){
				cc2=true;
			}
		}
		if(!cc1&&!cc2){
			sort(a+1,a+n+1,cmp);
			for(int i=n;i>=n/2+1;i--){
				cns+=a[i];
			}
			cout<<cns<<'\n';
			continue;
		}
		else if(!c2){
			for(int i=1;i<=n;i++){
				if(max(a[i],b[i])==a[i]){
					c1++;
				}
				else{
					c2++;
				}
				s+=max(a[i],max(b[i],c[i]));
			}
			if(max(c3,max(c2,c1))<=n/2){
				cout<<s<<'\n';
			}
		}
		else{
			for(int i=1;i<=n;i++){
				if(max(a[i],b[i])==a[i]){
					if(max(b[i],c[i])==b[i]){
						c1++;
					}
					else if(max(a[i],c[i])==c[i]){
						c3++;
					}
					else{
						c1++;
					}
				}
				else{
					if(max(b[i],c[i])==b[i]){
						c2++;
					}
					else{
						if(max(a[i],c[i])==c[i]){
							c3++;
						}
						else{
							c2++;
						}
					}
				}
				s+=max(a[i],max(b[i],c[i]));
			}
			if(max(c3,max(c2,c1))<=n/2){
				cout<<s<<'\n';
			}
			else{
				if(c1>c2+c3){
					
				}
				else if(c1+c2>c3){
					
				}
				else{
					
				}
			}
		}
	}
	return 0;
}
