#include<bits/stdc++.h>
using namespace std;
int T,i,n,t,s,x,fl[1000010],ff[1000010];
struct node{
	int x;
	int i;
};
struct node2{
	node fx[10];
};
node f[1000010];
node2 a[1000010];
bool cmp(node t,node w){
	return t.x>w.x;
}
bool cmp2(node t,node w){
	return t.x<w.x;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	while(T--){
		s=t=0;
		ff[1]=ff[2]=ff[3]=0;
		cin>>n;
		for(i=1;i<=n;i++)
			fl[i]=0;
		for(i=1;i<=n;i++){
			a[i].fx[1].i=1;
			a[i].fx[2].i=2;
			a[i].fx[3].i=3;
			cin>>a[i].fx[1].x>>a[i].fx[2].x>>a[i].fx[3].x;
			sort(a[i].fx+1,a[i].fx+1+3,cmp);
		}
		for(i=1;i<=n;i++)
			ff[a[i].fx[1].i]++;
		if(ff[1]>n/2||ff[2]>n/2||ff[3]>n/2){
			if(ff[1]>n/2)
				x=1;
			if(ff[2]>n/2)
				x=2;
			if(ff[3]>n/2)
				x=3;
			for(i=1;i<=n;i++)
				if(!(a[i].fx[1].i-x)){
					f[++t].x=a[i].fx[1].x-a[i].fx[2].x;
					f[t].i=i;
				}
			sort(f+1,f+1+t,cmp2);
//			cout<<ff[x]<<endl;
			for(i=1;i<=ff[x]-n/2;i++)
				fl[f[i].i]++;
			for(i=1;i<=n;i++)
				if(fl[i])
					s=s+a[i].fx[2].x;
				else
					s=s+a[i].fx[1].x;
			cout<<s<<endl;
		}
		else{
			for(i=1;i<=n;i++)
				s=s+a[i].fx[1].x;
			cout<<s<<endl;
		}
	}
}
