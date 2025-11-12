#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int t;
int n;
struct Node{
	int x;
	int y;
	int z;
	int ma1;
	int ma2;
	int ma3;
	int idx1;
	int idx2;
	int idx3;
	bool operator < (Node t) const{
		if(ma1<t.ma1) return 1;
		else if(ma1>t.ma1) return 0;
		else{
			if(ma2<t.ma2) return 1;
			else if(ma2>t.ma2) return 0;
			else{
				if(ma3<t.ma3) return 1;
				else return 0;
			} 
		}
	}
}a[N];
void getma(int x){
	a[x].ma1=a[x].x;
	a[x].ma2=a[x].y;
	a[x].ma3=a[x].z;
	int mat=max(a[x].ma2,a[x].ma3);
	if(mat>a[x].ma1){
		if(a[x].ma2==mat) swap(a[x].ma1,a[x].ma2);
		else swap(a[x].ma1,a[x].ma3);
	}
	if(a[x].ma2<a[x].ma3) swap(a[x].ma2,a[x].ma3);
	if(a[x].ma1==a[x].x){
		a[x].idx1=1;
		if(a[x].ma2==a[x].y){
			a[x].idx2=2;
			a[x].idx3=3;
		}else{
			a[x].idx2=3;
			a[x].idx2=2;
		}
	}else if(a[x].ma1==a[x].y){
		a[x].idx1=2;
		if(a[x].ma2==a[x].x){
			a[x].idx2=1;
			a[x].idx3=3;
		}else{
			a[x].idx2=3;
			a[x].idx3=1;
		}
	}else if(a[x].ma1==a[x].z){
		a[x].idx1=3;
		if(a[x].ma2==a[x].x){
			a[x].idx2=1;
			a[x].idx3=2;
		}else{
			a[x].idx2=2;
			a[x].idx3=1;
		}
	}
//	cout << t.ma1 << ' ' << t.ma2 << ' ' << t.ma3 << endl;
}
int getval(int x,int t){
	if(t==1) return a[x].x;
	if(t==2) return a[x].y;
	if(t==3) return a[x].z;
}
priority_queue<int,vector<int>,greater<int> > pq;
int cha(int p,int k){
	while(pq.size()) pq.pop();
	for(int i=1;i<=n;i++){
		if(a[i].idx1==p){
			pq.push(getval(i,a[i].idx1)-getval(i,a[i].idx2));
		}
	} 
	int ret=0;
	while(k--){
		if(pq.size()){
			ret+=pq.top();
			pq.pop();
		}
	}
	return ret;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
			getma(i);
		}
		int lim=n/2;
		int p1=0,p2=0,p3=0;
		int ans=0;
		for(int i=1;i<=n;i++){
			if(a[i].idx1==1){
				p1++;
				ans+=a[i].x;
			}else if(a[i].idx1==2){
				p2++;
				ans+=a[i].y;
			}else if(a[i].idx1==3){
				p3++;
				ans+=a[i].z;
			}
		}
		if(p1<=lim&&p2<=lim&&p3<=lim){
			printf("%d\n",ans);
		}else{
			if(p1>lim){
				ans-=cha(1,p1-lim);
			}else if(p2>lim){
				ans-=cha(2,p2-lim);
			}else if(p3>lim){
				ans-=cha(3,p3-lim);
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}
