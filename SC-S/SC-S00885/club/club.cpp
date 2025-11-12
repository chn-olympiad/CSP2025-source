#include<bits/stdc++.h>
using namespace std;
struct xs{
	int k,id;
}d[100010];
int n,a[100010][5],s[10],ans,M=0x7fffff;
priority_queue <int> b1,b2,b3;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		cin>>n;
		ans=0;
		s[1]=s[2]=s[3]=0;
		while(b1.size()){
			b1.pop();
		}
		while(b2.size()){
			b2.pop();
		}
		while(b3.size()){
			b3.pop();
		}
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			int t=max(max(a[i][1],a[i][2]),a[i][3]);
			if(t==a[i][1]){
				d[i].id=1;
			}
			else if(t==a[i][2]){
				d[i].id=2;
			}
			else{
				d[i].id=3;
			}
		}
		for(int i=1;i<=n;i++){
			if(s[d[i].id]<n/2){
				ans+=a[i][d[i].id];
				s[d[i].id]++;
				if(d[i].id==1){
					d[i].k=a[i][1]-max(a[i][2],a[i][3]);
					b1.push(M-d[i].k);
				}
				else if(d[i].id==2){
					d[i].k=a[i][2]-max(a[i][1],a[i][3]);
					b2.push(M-d[i].k);
				}
				else{
					d[i].k=a[i][3]-max(a[i][1],a[i][2]);
					b3.push(M-d[i].k);
				}
			}
			else{
				if(d[i].id==1){
					int t=M-b1.top();
					d[i].k=a[i][1]-max(a[i][2],a[i][3]);
					if(t<d[i].k){
						ans+=a[i][1]-t;
						b1.pop();
						b1.push(M-d[i].k);
					}
					else{
						ans+=max(a[i][2],a[i][3]);
					}
				}
				if(d[i].id==2){
					int t=M-b2.top();
					d[i].k=a[i][2]-max(a[i][1],a[i][3]);
					if(t<d[i].k){
						ans+=a[i][2]-t;
						b2.pop();
						b2.push(M-d[i].k);
					}
					else{
						ans+=max(a[i][1],a[i][3]);
					}
				}
				if(d[i].id==3){
					int t=M-b3.top();
					d[i].k=a[i][3]-max(a[i][1],a[i][2]);
					if(t<d[i].k){
						ans+=a[i][3]-t;
						b3.pop();
						b3.push(M-d[i].k);
					}
					else{
						ans+=max(a[i][1],a[i][2]);
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}