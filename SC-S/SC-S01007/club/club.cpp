#include<bits/stdc++.h>
using namespace std;
int t,a[100000],b[100000],c[100000],d[1000000];
map<int,int>m[100000];
map<int,int>p;
map<int,int>u;
bool dfg(int a,int b){
	return a>b;
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		int n,h=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			int y,f;
			cin>>a[i]>>b[i]>>c[i];
			y=max(a[i],max(b[i],c[i]));
			f=a[i]+b[i]+c[i]-max(a[i],max(b[i],c[i]))-min(a[i],min(b[i],c[i]));
			d[i]=y-f;
			p[y-f]++;
			m[y-f][p[y-f]]=i;
		}
		sort(d+1,d+n+1,dfg);
		int x=0,y=0,z=0;
		for(int i=1;i<=n;i++){
			u[d[i]]++;
			int q=m[d[i]][u[d[i]]],mx=max(a[q],max(b[q],c[q]));
			if(a[q]>=b[q]&&a[q]>=c[q]){
				x++;
				if(x>n/2){
					h+=max(b[q],c[q]);
				}else{
					h+=mx;
				}
			}else if(b[q]>a[q]&&b[q]>=c[q]){
				y++;
				if(y>n/2){
					h+=max(a[q],c[q]);
				}else{
					h+=mx;
				}
			}else if(c[q]>a[q]&&c[q]>b[q]){
				z++;
				if(z>n/2){
					h+=max(a[q],b[q]);
				}else{
					h+=mx;
				}
			}
		}
		cout<<h<<endl;
	}
	return 0;
}
