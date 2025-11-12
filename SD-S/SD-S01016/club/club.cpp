#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+100;
struct man{
	int name; 
	int w[4];
	int b[4][4];
}a[maxn],y;
bool cmp1(const man& b1,const man& b2){
	int manx1=max(b1.b[0][1],b1.b[0][2]);
	int manx2=max(b2.b[0][1],b2.b[0][2]);
	return manx1>manx2;
}
bool cmp2(const man& b1,const man& b2){
	int manx1=max(b1.b[1][0],b1.b[1][2]);
	int manx2=max(b2.b[1][0],b2.b[1][2]);
	return manx1>manx2;
}
bool cmp3(const man& b1,const man& b2){
	int manx1=max(b1.b[2][0],b1.b[2][1]);
	int manx2=max(b2.b[2][0],b2.b[2][1]);
	return manx1>manx2;
}
int n,t,b[maxn][4][4];
int x,maxm,p;
long long ac; 
int cnt1,cnt2,cnt3;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		cnt1=0;cnt2=0;cnt3=0;ac=0,p=0;
		for(int i=1;i<=n;i++)for(int j=0;j<3;j++)cin>>a[i].w[j],a[i].name=i;
		for(int i=1;i<=n;i++)for(int j=0;j<3;j++)for(int k=0;k<3;k++)a[i].b[j][k]=a[i].w[k]-a[i].w[j];
		vector<man> f,s,th;
		for(int i=1;i<=n;i++){
			if(a[i].w[0]>a[i].w[1]){
				if(a[i].w[1]>a[i].w[2]){
					f.push_back(a[i]);
					cnt1++;
					ac+=a[i].w[0];
				}
				else {
					if(a[i].w[0]>a[i].w[2]){
						f.push_back(a[i]);
						cnt1++;
						ac+=a[i].w[0];
					}
					else {
						th.push_back(a[i]);
						cnt3++;
						ac+=a[i].w[2];
					}
				}
			}
			else {
				if(a[i].w[1]>a[i].w[2]){
					s.push_back(a[i]);
					cnt2++;
					ac+=a[i].w[1];
				}
				else {
					th.push_back(a[i]);
					cnt3++;
					ac+=a[i].w[2];
				}
			}
		}
		//cout<<ac<<"\n";
		if(cnt1>n/2){
			x=cnt1-n/2;
			//for(auto exc:f)cout<<exc.name<<endl;
			sort(f.begin(),f.end(),cmp1);
			//for(auto exc:f)cout<<exc.name<<endl;
			for(int i=0;i<x;i++){
				y=f[i];
				maxm=max(y.b[0][1],y.b[0][2]);
				ac+=maxm;
			}
		}
		if(cnt2>n/2){
			x=cnt2-n/2;
			
			//for(auto exc:s)cout<<exc.name<<endl;
			
			sort(s.begin(),s.end(),cmp2);
			//for(auto exc:s)cout<<exc.name<<endl;
			for(int i=0;i<x;i++){
				y=s[i];
				maxm=max(y.b[1][0],y.b[1][2]);
				ac+=maxm;
			}
		}
		if(cnt3>n/2){
			x=cnt3-n/2;
			//for(auto exc:th)cout<<exc.name<<endl;
			sort(th.begin(),th.end(),cmp3);
			//for(auto exc:th)cout<<exc.name<<endl;
			for(int i=0;i<x;i++){
				y=th[i];
				maxm=max(y.b[2][0],y.b[2][1]);
				ac+=maxm;
			}
		}
		cout<<ac<<"\n";
	}
	return 0;
}
