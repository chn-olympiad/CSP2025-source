#include<bits/stdc++.h>
using namespace std;
int t,n;
struct node{
	int bm1,bm2,bm3;
	int cz1,cz2;
	int z1,z2,z3;
}a[100010];
struct h{
	int id,sx;
}b1[100010],b2[100010],b3[100010];
int ant1,ant2,ant3;
bool cmp(h x,h y){
	if(a[x.id].cz1==a[y.id].cz1) return a[x.id].cz2>a[y.id].cz2;
	return a[x.id].cz1>a[y.id].cz1;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--){
		memset(a,0,sizeof(a));
		ant1=0;
		ant2=0;
		ant3=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].bm1>>a[i].bm2>>a[i].bm3;
			int maxx=max(a[i].bm1,max(a[i].bm2,a[i].bm3));
			if(a[i].bm1==maxx){
				if(a[i].bm2>a[i].bm3) {
					a[i].cz1=maxx-a[i].bm2;
					a[i].cz2=a[i].bm2-a[i].bm3;
					a[i].z2=2;
					a[i].z3=3;
				}
				else{
					a[i].cz1=maxx-a[i].bm3;
					a[i].cz2=a[i].bm3-a[i].bm2;
					a[i].z2=3;
					a[i].z3=2;
				}
				b1[++ant1]={i,1};
				a[i].z1=1;
			}
			else if(a[i].bm2==maxx){
				if(a[i].bm1>a[i].bm3) {
					a[i].cz1=maxx-a[i].bm1;
					a[i].cz2=a[i].bm1-a[i].bm3;
					a[i].z2=1;
					a[i].z3=3;
				}
				else{
					a[i].cz1=maxx-a[i].bm3;
					a[i].cz2=a[i].bm3-a[i].bm1;
					a[i].z2=3;
					a[i].z3=1;
				}
				b2[++ant2]={i,1};
				a[i].z1=2;
			}
			else if(a[i].bm3==maxx){
				if(a[i].bm2>a[i].bm1) {
					a[i].cz1=maxx-a[i].bm2;
					a[i].cz2=a[i].bm2-a[i].bm1;
					a[i].z2=2;
					a[i].z3=1;
				}
				else{
					a[i].cz1=maxx-a[i].bm1;
					a[i].cz2=a[i].bm1-a[i].bm2;
					a[i].z2=1;
					a[i].z3=2;
				}
				b3[++ant3]={i,1};
				a[i].z1=3;
			}
		}
//		sort(a+1,a+n+1,cmp);
		if(ant1<=n/2&&ant2<=n/2&&ant3<=n/2){
			long long sum=0;
//			cout<<ant1<<" "<<ant2<<" "<<ant3<<endl;
			for(int i=1;i<=ant1;i++){
				if(a[b1[i].id].z1==1) sum+=a[b1[i].id].bm1;
				if(a[b1[i].id].z1==2) sum+=a[b1[i].id].bm2;
				if(a[b1[i].id].z1==3) sum+=a[b1[i].id].bm3;
			}
//			cout<<sum<<"\n";
			for(int i=1;i<=ant2;i++){
				if(a[b2[i].id].z1==1) sum+=a[b2[i].id].bm1;
				if(a[b2[i].id].z1==2) sum+=a[b2[i].id].bm2;
				if(a[b2[i].id].z1==3) sum+=a[b2[i].id].bm3;
			}
//			cout<<sum<<"\n";
			for(int i=1;i<=ant3;i++){
				if(a[b3[i].id].z1==1) sum+=a[b3[i].id].bm1;
				if(a[b3[i].id].z1==2) sum+=a[b3[i].id].bm2;
				if(a[b3[i].id].z1==3) sum+=a[b3[i].id].bm3;
			}
			cout<<sum<<"\n";
			continue;
		}
		sort(b1+1,b1+ant1+1,cmp);
		sort(b2+1,b2+ant2+1,cmp);
		sort(b3+1,b3+ant3+1,cmp);
//			cout<<ant1<<" "<<ant2<<" "<<ant3<<endl;
		int f=0;
		if(ant1>n/2){
			int k=n/2;
			while(ant1>k){
				if(a[b1[ant1].id].z2==2&&(ant2+1)<=(n/2)) b2[++ant2]={b1[ant1].id,2};
				else if(a[b1[ant1].id].z2==3) b3[++ant3]={b1[ant1].id,2};
				else b3[++ant3]={b1[ant1].id,3};
				ant1--;
			}
		}
		
//			cout<<ant1<<" "<<ant2<<" "<<ant3<<endl;
		if(ant2>n/2){
			int k=n/2;
			while(ant2>k){
				if(a[b2[ant2].id].z2==1&&(ant1+1)<=(n/2)) b1[++ant1]={b2[ant2].id,2};
				else if(a[b2[ant2].id].z2==3)b3[++ant3]={b2[ant2].id,2};
				else b3[++ant3]={b2[ant2].id,3};
				ant2--;
			}
		}
		
//			cout<<ant1<<" "<<ant2<<" "<<ant3<<endl;
		if(ant3>n/2){
			int k=n/2;
			while(ant3>k){
				if(a[b3[ant3].id].z2==1&&(ant1+1)<=(n/2)) b1[++ant1]={b3[ant3].id,2};
				else if(a[b3[ant3].id].z2==2)b2[++ant2]={b3[ant3].id,2};
				else b2[++ant3]={b2[ant3].id,3};
				ant3--;
			}
		}
		long long sum=0;
//			cout<<ant1<<" "<<ant2<<" "<<ant3<<endl;
		for(int i=1;i<=ant1;i++){
			if(b1[i].sx==1){
				if(a[b1[i].id].z1==1) sum+=a[b1[i].id].bm1;
				if(a[b1[i].id].z1==2) sum+=a[b1[i].id].bm2;
				if(a[b1[i].id].z1==3) sum+=a[b1[i].id].bm3;
			}
			else if(b1[i].sx==2){
				if(a[b1[i].id].z2==1) sum+=a[b1[i].id].bm1;
				if(a[b1[i].id].z2==2) sum+=a[b1[i].id].bm2;
				if(a[b1[i].id].z2==3) sum+=a[b1[i].id].bm3;
			}
			else if(b1[i].sx==3){
				if(a[b1[i].id].z3==1) sum+=a[b1[i].id].bm1;
				if(a[b1[i].id].z3==2) sum+=a[b1[i].id].bm2;
				if(a[b1[i].id].z3==3) sum+=a[b1[i].id].bm3;
			}
		}
//		cout<<sum<<"\n";
		for(int i=1;i<=ant2;i++){
			if(b2[i].sx==1){
				if(a[b2[i].id].z1==1) sum+=a[b2[i].id].bm1;
				if(a[b2[i].id].z1==2) sum+=a[b2[i].id].bm2;
				if(a[b2[i].id].z1==3) sum+=a[b2[i].id].bm3;
			}
			else if(b2[i].sx==2){
				if(a[b2[i].id].z2==1) sum+=a[b2[i].id].bm1;
				if(a[b2[i].id].z2==2) sum+=a[b2[i].id].bm2;
				if(a[b2[i].id].z2==3) sum+=a[b2[i].id].bm3;
			}
			else if(b2[i].sx==3){
				if(a[b2[i].id].z3==1) sum+=a[b2[i].id].bm1;
				if(a[b2[i].id].z3==2) sum+=a[b2[i].id].bm2;
				if(a[b2[i].id].z3==3) sum+=a[b2[i].id].bm3;
			}
		}
//		cout<<sum<<"\n";
		for(int i=1;i<=ant3;i++){
			if(b3[i].sx==1){
				if(a[b3[i].id].z1==1) sum+=a[b3[i].id].bm1;
				if(a[b3[i].id].z1==2) sum+=a[b3[i].id].bm2;
				if(a[b3[i].id].z1==3) sum+=a[b3[i].id].bm3;
			}
			else if(b3[i].sx==2){
				if(a[b3[i].id].z2==1) sum+=a[b3[i].id].bm1;
				if(a[b3[i].id].z2==2) sum+=a[b3[i].id].bm2;
				if(a[b3[i].id].z2==3) sum+=a[b3[i].id].bm3;
			}
			else if(b3[i].sx==3){
				if(a[b3[i].id].z3==1) sum+=a[b3[i].id].bm1;
				if(a[b3[i].id].z3==2) sum+=a[b3[i].id].bm2;
				if(a[b3[i].id].z3==3) sum+=a[b3[i].id].bm3;
			}
		}
		cout<<sum<<"\n";
	}
	return 0;
}
