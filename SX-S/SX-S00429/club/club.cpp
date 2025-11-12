#include<bits/stdc++.h>
using namespace std;
struct d{
	int a1,a2,a3;
}b[100005];
inline bool cmp(d p,d q){
	return max(p.a1,max(p.a2,p.a3))>max(q.a1,max(q.a2,q.a3));
}
int main(){
	freopen("clud.in","r",stdin);
	freopen("clud.out","w",stdout);
	cin.tie(0),cout.tie(0);
	int t,n;
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>b[i].a1>>b[i].a2>>b[i].a3;
		}
		sort(b+1,b+n+1,cmp);
		long long s=0,mmax,mmax2,s1=1,s2=1,s3=1;
		for(int i=1;i<=n;i++){
			mmax=max(b[i].a1,max(b[i].a2,b[i].a3));
			mmax2=max(b[i+1].a1,max(b[i+1].a2,b[i+1].a3));
			if(mmax==b[i].a1){
				if(s1<=n/2){
					s1++;
					if(max(b[i].a2,b[i].a3)+mmax2>mmax&&b[i+1].a2==0&&b[i+1].a3==0)
						s+=max(b[i].a2,b[i].a3)+mmax2;
					else s+=mmax;
				}
				else s+=max(b[i].a2,b[i].a3);
			}
			if(mmax==b[i].a2){
				if(s2<=n/2){
					s2++;
					if(max(b[i].a1,b[i].a3)+mmax2>mmax&&b[i+1].a1==0&&b[i+1].a3==0)
						s+=max(b[i].a1,b[i].a3)+mmax2;
					else s+=mmax;
				}
				else s+=max(b[i].a1,b[i].a3);
			}
			if(mmax==b[i].a3){
				if(s3<=n/2){
					s3++;
					if(max(b[i].a1,b[i].a2)+mmax2>mmax&&b[i+1].a1==0&&b[i+1].a2==0)
						s+=max(b[i].a1,b[i].a2)+mmax2;
					else s+=mmax;
				}
				else s+=max(b[i].a1,b[i].a2);
			}
		}
		cout<<s<<"\n";
	}
	return 0;
}