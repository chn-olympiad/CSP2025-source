#include<bits/stdc++.h>
#define pll pair <int,int> 
using namespace std;
const int N=2e5+10;
struct node {
	int cnt[5]={0},id[5]={0},yesid;
}a[N];
bool cmp (node h,node i){
	if (h.cnt[1]>i.cnt[1]){
		return 1; 
	} else if (h.cnt[1]==i.cnt[1]){
		if (h.cnt[2]>i.cnt[2]){
			return 1;
		} else if (h.cnt[2]==i.cnt[2]){
			if (h.cnt[3]>i.cnt[3]){
				return 1;
			}
		}
	}
	return 0;
}
int T,n,x,y,z,cl_[5];
pll p;
void in_sor_ (int i){
	scanf ("%d %d %d",&x,&y,&z);
	if (x>y){
		if (x>z){
			a[i].cnt[1]=x;
			a[i].id[1]=1;
			if (y>z){
				a[i].cnt[2]=y; a[i].cnt[3]=z;
				a[i].id[2]=2; a[i].id[3]=3;
			} else {
				a[i].cnt[2]=z; a[i].cnt[3]=y;
				a[i].id[2]=3; a[i].id[3]=2;
			}
		} else {
			a[i].cnt[1]=z; a[i].cnt[2]=x; a[i].cnt[3]=y;
			a[i].id[1]=3; a[i].id[2]=1; a[i].id[3]=2;
		}
	} else if (x>z){
		a[i].cnt[1]=y; a[i].cnt[2]=x; a[i].cnt[3]=z;
		a[i].id[1]=2; a[i].id[2]=1; a[i].id[3]=3;
	} else {
		a[i].cnt[3]=x;
		a[i].id[3]=1;
		if (y>z){
			a[i].cnt[1]=y; a[i].cnt[2]=z;
			a[i].id[1]=2; a[i].id[2]=3;
		} else {
			a[i].cnt[1]=z; a[i].cnt[2]=y;
			a[i].id[1]=3; a[i].id[2]=2;
		}
	}
}
void solve (){
	scanf ("%d",&n);
	for (int i=1; i<=n; i++){
		in_sor_ (i);
	}
	sort (a+1,a+1+n,cmp);
	memset (cl_,0,sizeof cl_);
	for (int i=1; i<=n; i++){
		if (cl_[a[i].id[1]]==n/2){
			if (cl_[a[i].id[2]]==n/2){
				p.first=a[i].cnt[1]-a[i].cnt[3]; p.second=3;
			} else {
				p.first=a[i].cnt[1]-a[i].cnt[2]; p.second=2;
			}
			int index=i;
			for (int j=1; j<i; j++){
				if (a[j].id[a[j].yesid]!=a[1].id[1] || a[j].yesid==3){
					continue;
				}
				int sum=0;
				if (cl_[a[j].id[a[j].yesid+1]]==n/2){
					if (a[j].yesid==1){
						if (cl_[a[j].id[3]]==n/2){
							continue;
						}
						sum=a[j].cnt[1]-a[j].cnt[3];
					} else continue;
				} else sum=a[j].cnt[a[j].yesid]-a[j].cnt[a[j].yesid+1];
				if (sum<p.first){
					p.first=sum;
					if (cl_[a[j].id[a[j].yesid+1]]==n/2){
						p.second=a[j].yesid+2;
					} else p.second=a[j].yesid+1;
					index=j;
				}
			}
			if (index==i){
				a[i].yesid=p.second;
				cl_[a[i].id[a[i].yesid]]++;
			} else {
				a[i].yesid=1;
				a[index].yesid=p.second;
				cl_[a[index].id[p.second]]++;
			}
		} else {
			a[i].yesid=1; cl_[a[i].id[1]]++;
		}
	}
	int ans=0;
	for (int i=1; i<=n; i++){
		ans+=a[i].cnt[a[i].yesid];
	}
	printf ("%d\n",ans);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while (T--){
		solve ();
	}
	return 0;
}
