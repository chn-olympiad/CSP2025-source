//100 pts
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define PI pair<int,int>
#define ls rt*2
#define rs rt*2+1
const int N=2e5;
int t;
int n;
struct Student{
	int id;
	int x,y,z; 
}s[N];
struct Club{
	int w;
	int id;
}x[N],y[N],z[N];
int tot1,tot2,tot3;
void Pushclub(Student a){
	if(a.x>=a.y&&a.x>=a.z){
		tot1++;
		x[tot1].w=a.x;
		x[tot1].id=a.id;
	}
	else if(a.y>=a.x&&a.y>=a.z){
		tot2++;
		y[tot2].w=a.y;
		y[tot2].id=a.id;
	}
	else{
		tot3++;
		z[tot3].w=a.z;
		z[tot3].id=a.id;
	}
	return;
}
bool cmpx(Club a,Club b){
	int maxa=max(s[a.id].y-s[a.id].x,s[a.id].z-s[a.id].x);
	int maxb=max(s[b.id].y-s[b.id].x,s[b.id].z-s[b.id].x);
	return maxa<maxb;
}
bool cmpy(Club a,Club b){
	int maxa=max(s[a.id].x-s[a.id].y,s[a.id].z-s[a.id].y);
	int maxb=max(s[b.id].x-s[b.id].y,s[b.id].z-s[b.id].y);
	return maxa<maxb;
}
bool cmpz(Club a,Club b){
	int maxa=max(s[a.id].x-s[a.id].z,s[a.id].y-s[a.id].z);
	int maxb=max(s[b.id].x-s[b.id].z,s[b.id].y-s[b.id].z);
	return maxa<maxb;
}
void solve(){
	if(tot1>n/2){
		sort(x+1,x+tot1+1,cmpx);
		for(tot1;tot1>n/2;tot1--){
			if(s[x[tot1].id].y>s[x[tot1].id].z){
				tot2++;
				y[tot2].w=s[x[tot1].id].y;
			}
			else{
				tot3++;
				z[tot3].w=s[x[tot1].id].z;
			}
		}
	}
	if(tot2>n/2){
		sort(y+1,y+tot2+1,cmpy);
		for(tot2;tot2>n/2;tot2--){
			if(s[y[tot2].id].x>s[y[tot2].id].z){
				tot1++;
				x[tot1].w=s[y[tot2].id].x;
			}
			else{
				tot3++;
				z[tot3].w=s[y[tot2].id].z;
			}
		}
	}
	if(tot3>n/2){
		sort(z+1,z+tot3+1,cmpz);
		for(tot3;tot3>n/2;tot3--){
			if(s[z[tot3].id].x>s[z[tot3].id].y){
				tot1++;
				x[tot1].w=s[z[tot3].id].x;
			}
			else{
				tot2++;
				y[tot2].w=s[z[tot3].id].y;
			}
		}
	}
	return;
}
int calc(){
	int res=0;
	for(int i=1;i<=tot1;i++){
		res+=x[i].w;
	}
	for(int i=1;i<=tot2;i++){
		res+=y[i].w;
	}
	for(int i=1;i<=tot3;i++){
		res+=z[i].w;
	}
	return res;
}
void Clear(){
	tot1=0;
	tot2=0;
	tot3=0;
	return;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--){
		Clear();
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>s[i].x>>s[i].y>>s[i].z;
			s[i].id=i;
			Pushclub(s[i]);
		}
		solve();
		cout<<calc()<<"\n";
	}
	return 0;
} 
/*

*/
