#include<bits/stdc++.h>
using namespace std;
struct A{
	int a;
	int b;
	int c;
	int d;
}f[100005];
bool cnta(A s,A d){
	if(s.d==1&&d.d==1){
		return s.a-max(s.b,s.c)<d.a-max(d.b,d.c);
	}
	if(s.d!=1&&d.d==1){
		return true;
	}
	return false;
}
bool cntc(A s,A d){
	if(s.d==3&&d.d==3){
		return s.c-max(s.a,s.b)<d.c-max(d.a,d.b);
	}
	if(s.d!=3&&d.d==3){
		return true;
	}
	return false;
}
bool cntb(A s,A d){
	if(s.d==2&&d.d==2){
		return s.b-max(s.a,s.c)<d.b-max(d.a,d.c);
	}
	if(s.d!=2&&d.d==2){
		return true;
	}
	return false;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int n;
	cin>>n;
	for(int k=1;k<=n;k++){
		int m;
		cin>>m;
		A f[100005];
		int za=0,zb=0,zc=0;
		long long num=0;
		for(int i=1;i<=m;i++){
			int a1,b1,c1;
			cin>>a1>>b1>>c1;
			f[i].a=a1;
			f[i].b=b1;
			f[i].c=c1;
			if(a1>=b1&&a1>=c1){
				za++;
				f[i].d=1;
				num+=f[i].a;
			}
			else{
				if(b1>=a1&&b1>=c1){
					zb++;
					f[i].d=2;
					num+=f[i].b;
				}
				if(c1>=a1&&c1>=b1){
					zc++;
					f[i].d=3;
					num+=f[i].c;
				}
			}
		}
		while(2*za>m or 2*zb>m or 2*zc>m){
			if(2*za>m){
				sort(f+1,f+m,cnta);
				for(int i=1;i<=za-m/2;i++){
					num-=f[i].a;
					za--;
					if(2*zb<m&&2*zc<m){
						num+=max(f[i].b,f[i].c);
						if(f[i].b>f[i].c){
							zb++;
							f[i].d=2;
						}
						else{
							zc++;
							f[i].d=3;
						}
					}
					else{
						if(2*zb>m){
							num+=f[i].c;
							zc++;
							f[i].d=3;
						}
						if(2*zc>m){
							num+=f[i].b;
							zb++;
							f[i].d=2;
						}
					}
				}
			}
			if(2*zb>m){
				sort(f+1,f+m,cntb);
				for(int i=1;i<=zb-m/2;i++){
					num-=f[i].b;
					zb--;
					if(2*za<m&&2*zc<m){
						num+=max(f[i].a,f[i].c);
						if(f[i].a>f[i].c){
							za++;
							f[i].d=1;
						}
						else{
							zc++;
							f[i].d=3;
						}
					}
					else{
						if(2*za>m){
							num+=f[i].c;
							zc++;
							f[i].d=3;
						}
						if(2*zc>m){
							num+=f[i].a;
							za++;
							f[i].d=1;
						}
					}
				}
			}
			if(2*zc>m){
				sort(f+1,f+m,cntc);
				for(int i=1;i<=zc-m/2;i++){
					num-=f[i].c;
					zc--;
					if(2*zb<m&&2*za<m){
						num+=max(f[i].b,f[i].a);
						if(f[i].b>f[i].a){
							zb++;
							f[i].d=2;
						}
						else{
							za++;
							f[i].d=1;
						}
					}
					else{
						if(2*za>m){
							num+=f[i].b;
							zb++;
							f[i].d=2;
						}
						if(2*zb>m){
							num+=f[i].a;
							za++;
							f[i].d=1;
						}
					}
				}
			}
		}
		cout<<num<<endl;
	}
	
	return 0;
} 
