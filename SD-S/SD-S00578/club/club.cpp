#include<bits/stdc++.h>
using namespace std;
#define int long long
int T;
int n;
struct node{
	int a,b,c,d;
}e[100005];

inline bool cmp(node x,node y){
	return x.d<y.d;
}
int ans;

inline void solve(){
	int suma=0;
	int sumb=0;
	int sumc=0;
	int tag1=0;
	int tag2=0;
	int tag3=0;
	int tag4=0;
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>e[i].a>>e[i].b>>e[i].c;
		suma+=e[i].a;
		sumb+=e[i].b;
		sumc+=e[i].c;
	}
	if (suma>sumb && suma>sumc){
		ans=suma;	
	}
	else if (sumb>suma && sumb>sumc){
		ans=sumb;
		for (int i=1;i<=n;i++){
			swap(e[i].a,e[i].b);
		}
	}
	else{
		ans=sumc;
		for (int i=1;i<=n;i++){
			swap(e[i].a,e[i].c);
		}	
	}
	
	for (int i=1;i<=n;i++){
		e[i].d=e[i].a-max(e[i].b,e[i].c);
	}
	sort(e+1,e+n+1,cmp);
	for (int i=1;i<=n/2;i++){
		ans-=e[i].d;
		if (e[i].a-e[i].b==e[i].a-e[i].c){
			if (tag1>tag2){
				tag4++;
			}
			else{
				tag3++;
			}
		}
		else if (e[i].a-e[i].b==e[i].d){
			tag1++; 
		}
		else{
			tag2++;
		}
	}
	for (int i=n/2+1;i<=n;i++){
		if (e[i].d>=0) break;
		if (e[i].b==e[i].c){
			if (tag1+tag3>tag2+tag4){
				if (tag2+tag4<n/2){
					tag4++;
					ans-=e[i].d;
				}
				else if (n/2-(tag3+tag1)>0 && tag4){
					tag3++;
					ans-=e[i].d;
				}
				else{
					continue;
				}
			}
			else{
				if (tag1+tag3<n/2){
					tag3++;
					ans-=e[i].d;
				}
				else if (n/2-(tag3+tag1)>0 && tag3){
					tag4++;
					ans-=e[i].d;
				}
				else{
					continue;
				}
			}
		}
		else{
			if (e[i].d==e[i].a-e[i].b){
				if (tag1+tag3<n/2){
					tag1++;
					ans-=e[i].d;
				}
				else if (n/2-(tag3+tag1)>0 && tag3){
					tag4++;
					tag3--;
					ans-=e[i].d;
				}
				else{
					continue;
				}
			}
			else{
				if (tag2+tag4<n/2){
					tag2++;
					ans-=e[i].d;
				}
				else if (n/2-(tag3+tag1)>0 && tag4){
					tag3++;
					tag4--;
					ans-=e[i].d;
				}
				else{
					continue;
				}
			}
		}
	}
	cout<<ans<<"\n";
	
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while (T--){
		solve();
	}
	return 0;
} 
