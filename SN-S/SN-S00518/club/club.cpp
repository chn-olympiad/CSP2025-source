//SN-S00518 王者淳 西安辅轮中学
#include<bits/stdc++.h>
using namespace std;
int t,n,a[100001][3];
long long ans;
vector<int>x,y,z;
void qsortx(int l,int r){
	int k=x[(l+r)>>1];
	int i=l,j=r;
	while(i<=j){
		while(x[i]<k)i++;
		while(x[j]>k)j--;
		if(i<=j){
			swap(x[i],x[j]);
			i++;j--;
		}
	}
	if(l<j)qsortx(l,j);
	if(i<r)qsortx(i,r);
}
void qsorty(int l,int r){
	int k=y[(l+r)>>1];
	int i=l,j=r;
	while(i<=j){
		while(y[i]<k)i++;
		while(y[j]>k)j--;
		if(i<=j){
			swap(y[i],y[j]);
			i++;j--;
		}
	}
	if(l<j)qsorty(l,j);
	if(i<r)qsorty(i,r);
}
void qsortz(int l,int r){
	int k=z[(l+r)>>1];
	int i=l,j=r;
	while(i<=j){
		while(z[i]<k)i++;
		while(z[j]>k)j--;
		if(i<=j){
			swap(z[i],z[j]);
			i++;j--;
		}
	}
	if(l<j)qsortz(l,j);
	if(i<r)qsortz(i,r);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;ans=0;
		x.clear();y.clear();z.clear();
		for(int i=1;i<=n;i++){
			cin>>a[i][0]>>a[i][1]>>a[i][2];
			if(a[i][0]>=a[i][1]&&a[i][0]>=a[i][2]){
				ans+=a[i][0];
				x.push_back(min(a[i][0]-a[i][1],a[i][0]-a[i][2]));
			}
			else if(a[i][1]>=a[i][2]){
				ans+=a[i][1];
				y.push_back(min(a[i][1]-a[i][0],a[i][1]-a[i][2]));
			}
			else {
				ans+=a[i][2];
				z.push_back(min(a[i][2]-a[i][0],a[i][2]-a[i][1]));
			}
		}
		if(x.size()>n/2){
			qsortx(0,x.size()-1);
			for(int i=0;i<x.size()-n/2;i++)ans-=x[i];
		}
		else if(y.size()>n/2){
			qsorty(0,y.size()-1);
			for(int i=0;i<y.size()-n/2;i++)ans-=y[i];
		}
		else if(z.size()>n/2){
			qsortz(0,z.size()-1);
			for(int i=0;i<z.size()-n/2;i++)ans-=z[i];
		}
		cout<<ans<<"\n";
	}
	return 0;
}
