#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5;
struct node{
	int x,y,z;
	int cha,fl;
}a[N+5];
int n,k,p,flag;
ll ans;
bool cmp(node x,node y){
	return x.cha>y.cha;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		k=n/2;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
		}
		ll ans1=0;
		flag=0;
		for(int i=1;i<=n;i++){
			ans1+=a[i].x;
			a[i].cha=max(a[i].y-a[i].x,a[i].z-a[i].x);
			if(a[i].y-a[i].x>a[i].z-a[i].x) a[i].fl=1;
			else if(a[i].z-a[i].x>a[i].y-a[i].x) a[i].fl=2;
		}
		sort(a+1,a+1+n,cmp);
		for(int i=1;i<=k;i++){
			ans1+=a[i].cha;
			if(a[i].fl==1) flag++;
		} 
		p=k+1;
		while(a[p].cha>0&&(n-p)>=(n/3)+1&&flag<k&&(n-p+1-flag)<k){
			ans1+=a[p].cha;
			if(a[p].fl==1) flag++;
			p++;
		}
		
		ll ans2=0;
		flag=0;
		for(int i=1;i<=n;i++){
			ans2+=a[i].y;
			a[i].cha=max(a[i].x-a[i].y,a[i].z-a[i].y);
			if(a[i].x-a[i].y>a[i].z-a[i].y) a[i].fl=1;
			else if(a[i].z-a[i].y>a[i].x-a[i].y) a[i].fl=2;
		}
		sort(a+1,a+1+n,cmp);
		for(int i=1;i<=k;i++){
			ans2+=a[i].cha;
			if(a[i].fl==1) flag++;
		} 
		p=k+1;
		while(a[p].cha>0&&(n-p)>=(n/3)+1&&flag<k&&(n-p+1-flag)<k){
			ans2+=a[p].cha;
			if(a[p].fl==1) flag++;
			p++;
		}
		
		ll ans3=0;
		flag=0;
		for(int i=1;i<=n;i++){
			ans3+=a[i].z;
			a[i].cha=max(a[i].y-a[i].z,a[i].x-a[i].z);
			if(a[i].y-a[i].z>a[i].x-a[i].z) a[i].fl=1;
			else if(a[i].x-a[i].z>a[i].y-a[i].z) a[i].fl=2;
		}
		sort(a+1,a+1+n,cmp);
		for(int i=1;i<=k;i++){
			ans3+=a[i].cha;
			if(a[i].fl==1) flag++;
		} 
		p=k+1;
		while(a[p].cha>0&&(n-p)>=(n/3)+1&&flag<k&&(n-p+1-flag)<k){
			ans3+=a[p].cha;
			if(a[p].fl==1) flag++;
			p++;
		}
		ans=max(ans1,max(ans2,ans3));
		printf("%lld\n",ans);
		ans=0;
	}
	
	
	return 0;
}
/*
1
30
9478 19118 8151
13734 12377 2590
17271 16865 12064
18865 15914 6583
17881 2606 1461
7661 10745 2015
5626 1 13811
17093 17920 9103
1260 5941 6956
7029 8181 9418
16277 13988 354
14474 15227 4982
18507 16641 9235
16900 4898 4480
1289 3301 13793
19466 18556 6597
8834 261 19131
19944 18987 9560
14166 7854 1087
16689 3937 4380
18836 4342 18874
1751 16536 17990
10936 3627 1271
12006 16719 4693
12954 6746 5867
17098 16955 4125
18143 8067 2266
14889 8692 60
14736 14274 10644
16270 7210 3708
*/
