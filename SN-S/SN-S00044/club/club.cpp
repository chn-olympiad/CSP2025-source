#include<bits/stdc++.h>
using namespace std;
long long a,s,d[1000005],f[1000005],g[1000005],ch[1000005];
struct ll{
	long long u1,u2,u3,ca;
};
ll h[1000005];
bool lk(ll aa,ll bb){
	return aa.ca>bb.ca;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>a;
	for(int z=1; z<=a; z++){
		cin>>s;
		for(int x=1; x<=s; x++){
			cin>>d[x]>>f[x]>>g[x];
			if(d[x]>=f[x]&&d[x]>=g[x]){
				if(f[x]>=g[x])ch[x]=d[x]-f[x];
				if(f[x]<=g[x])ch[x]=d[x]-g[x];
			}
			if(f[x]>=d[x]&&f[x]>=g[x]){
				if(d[x]>=g[x])ch[x]=f[x]-d[x];
				if(g[x]>=d[x])ch[x]=f[x]-g[x];
			}
			if(g[x]>=f[x]&&g[x]>=d[x]){
				if(d[x]>=f[x])ch[x]=g[x]-d[x];
				if(f[x]>=d[x])ch[x]=g[x]-f[x];
			}
		}
		for(int x=1; x<=s; x++){
			h[x].u1=d[x];
			h[x].u2=f[x];
			h[x].u3=g[x];
			h[x].ca=ch[x];
		}
		sort(h+1,h+1+s,lk);
//		for(int x=1; x<=s; x++){
//			cout<<d[x]<<" "<<f[x]<<" "<<g[x]<<endl;
//		}
//		for(int x=1; x<=s; x++){
//			cout<<h[x].u1<<" "<<h[x].u2<<" "<<h[x].u3<<" "<<h[x].ca<<endl;
//		}
		long long y1=0,y2=0,y3=0;
		long long h1=0,h2=0,h3=0;
		for(int x=1; x<=s; x++){
			if(h[x].u1>=h[x].u2&&h[x].u1>=h[x].u3){
				if(y1>=s/2){
					h[x].u1=-1;
					x--;
					continue;
				}
				else{
					//cout<<x<<" "<<h[x].u1<<endl;
					y1++;
					h1+=h[x].u1;
				}
			}
			else if(h[x].u2>=h[x].u1&&h[x].u2>=h[x].u3){
				if(y2>=s/2){
					h[x].u2=-1;
					x--;
					continue;
				}
				else{
					//cout<<x<<" "<<h[x].u2<<endl;
					y2++;
					h2+=h[x].u2;
				}
			}
			else if(h[x].u3>=h[x].u1&&h[x].u3>=h[x].u2){
				if(y3>=s/2){
					h[x].u3=-1;
					x--;
					continue;
				}
				else{
					//cout<<x<<" "<<h[x].u3<<endl;
					y3++;
					h3+=h[x].u3;
				}
			}
		}
		cout<<h1+h2+h3<<endl;
	}
	return 0;
}
