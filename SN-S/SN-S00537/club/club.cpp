#include<bits/stdc++.h>
using namespace std;

long long n,j[3],c1,ans;
struct node{
	long long t[3];
	long long z1;
	long long z2;
	long long z3;
	void cmp(){
		if(t[0]>=t[1] &&t[0]>=t[2]){
			z1=0;
			if(t[1]>=t[2]){
				z2=1;
				z3=2;
			}else if(t[2]>=t[1]){
				z2=2;
				z3=1;
			}
		}else if(t[1]>=t[0] &&t[1]>=t[2]){
			z1=1;
			if(t[0]>=t[2]){
				z2=0;
				z3=2;
			}else if(t[2]>=t[0]){
				z2=2;
				z3=0;
			}
		}else if(t[2]>=t[0] &&t[2]>=t[1]){
			z1=2;
			if(t[1]>=t[0]){
				z2=1;
				z3=0;
			}else if(t[0]>=t[1]){
				z2=0;
				z3=1;
			}
		}
	}
}a[100010];
bool cmp1(const node& l,const node& r){
	return l.t[l.z1]+r.t[r.z2]>r.t[r.z1]+l.t[l.z2];
	
}
void solve(){
	for(int i=0;i<3;i++){
		j[i]=0;
	}
	ans=0;
	cin>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<3;j++){
			cin>>a[i].t[j];
		}
		a[i].cmp();
	}
	sort(a,a+n,cmp1);
	for(int i=0;i<n;i++){
		if(j[a[i].z1]<n/2){
			ans+=a[i].t[a[i].z1];
			j[a[i].z1]++;
		}else if(j[a[i].z1]>=n/2 &&j[a[i].z2]<n/2){
			ans+=a[i].t[a[i].z2];
			j[a[i].z2]++;
		}/*else if(j[a[i].z1]>=n/2 &&j[a[i].z2]>=n/2){
			ans+=a[i].t[a[i].z3];
			j[a[i].z3]++;
		}*/
	}
	cout<<ans<<endl;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>c1;
	while(c1--){
		solve();
	}
	return 0;
}

