#include<bits/stdc++.h>
using namespace std;
struct node{
	long long c,i;
};
bool cmp(node x,node y){
	return x.c>y.c;
}
long long n,t,h[4],sum;
node l[100005],a[100005][4];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		sum=0;h[0]=0;h[1]=0;h[2]=0;
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>a[i][0].c>>a[i][1].c>>a[i][2].c;
			a[i][0].i=0;
			a[i][1].i=1;
			a[i][2].i=2;
			sort(a[i],a[i]+3,cmp);
			l[i].c=a[i][0].c-a[i][1].c;
			l[i].i=i;
		}
		sort(l,l+n,cmp);
		for(int i=0;i<n;i++){
			if(h[a[l[i].i][0].i]==n/2){
				sum+=a[l[i].i][1].c;
				h[a[l[i].i][1].i]++;
			}else{
				sum+=a[l[i].i][0].c;
				h[a[l[i].i][0].i]++;
			}
		}
		cout<<sum<<"\n";
	}
	return 0;
}
