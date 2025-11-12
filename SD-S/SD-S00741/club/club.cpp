#include<bits/stdc++.h>
using namespace std;
int t,a1[100010],a2[100010],a3[100010];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin>>t;
	while(t--){
		int n,t1=0,t2=0,t3=0,s=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			int x,y,z;
			cin>>x>>y>>z;
			if(x==max(x,max(y,z))){
				a1[++t1]=x-max(y,z);
			}else if(y==max(x,max(y,z))){
				a2[++t2]=y-max(x,z);
			}else if(z==max(x,max(y,z))){
				a3[++t3]=z-max(x,y);
			}
			s+=max(x,max(y,z));
		}
		if(t1>(n/2)){
			sort(a1+1,a1+t1+1);
			for(int i=1;i<=t1-(n/2);i++){
				s-=a1[i];
			}
		}else if(t2>(n/2)){
			sort(a2+1,a2+t2+1);
			for(int i=1;i<=t2-(n/2);i++){
				s-=a2[i];
			}
		}else if(t3>(n/2)){
			sort(a3+1,a3+t3+1);
			for(int i=1;i<=t3-(n/2);i++){
				s-=a3[i];
			}
		}
		cout<<s<<"\n";
	}
	return 0;
} 
