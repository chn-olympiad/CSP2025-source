#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct stu{
	ll a1,a2,a3;
};
struct node{
	ll x,y;
};
ll cmp(node a,node b){
	return a.x>b.x;
}
ll t,n,ans1,ans2,ans3,cnt1,cnt2,cnt3;
node c1[100005],c2[100005],c3[100005],d1[100005],d2[100005],d3[100005];
stu a[100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cnt1=0,cnt2=0,cnt3=0,ans1=0,ans2=0,ans3=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].a1>>a[i].a2>>a[i].a3;
			c1[i].x=a[i].a1,c1[i].y=i;
			c2[i].x=a[i].a2,c2[i].y=i;
			c3[i].x=a[i].a3,c3[i].y=i;
			ll j=max(max(a[i].a1,a[i].a2),a[i].a3);
			d1[i].x=c1[i].x-max(a[i].a2,a[i].a3),d1[i].y=i;
			d2[i].x=c2[i].x-max(a[i].a1,a[i].a3),d2[i].y=i;
			d3[i].x=c3[i].x-max(a[i].a2,a[i].a1),d3[i].y=i;
			if(j==a[i].a1){
				ans1++;
				cnt1+=j;
			}else if(j==a[i].a2){
				ans2++;
				cnt2+=j;
			}else{
				ans3++;
				cnt3+=j;
			} 
		}
		if(ans1*2<=n&&ans2*2<=n&&ans3*2<=n){
			cout <<cnt1+cnt2+cnt3<<endl;
			continue;
		}
		if(ans1*2>n){
		    sort(d1+1,d1+n+1,cmp);
			for(int i=n/2+1;i<=ans1;i++){
				stu m=a[c1[d1[i].y].y];
				cnt1-=m.a1;
				if(a[i].a2>=a[i].a3)cnt2+=m.a2;
				else cnt3+=m.a3;
			}
		}else if(ans2*2>n){
			sort(d2+1,d2+n+1,cmp);
			for(int i=n/2+1;i<=ans2;i++){
				stu m=a[c2[d2[i].y].y];
				cnt2-=m.a2;
				if(a[i].a1>=a[i].a2)cnt1+=m.a1;
				else cnt3+=m.a3;
			}
		}else{
			sort(d3+1,d3+n+1,cmp);
			for(int i=n/2+1;i<=ans3;i++){
				stu m=a[c3[d3[i].y].y];
				cnt3-=m.a3;
				if(a[i].a2>=a[i].a1)cnt2+=m.a2;
				else cnt1+=m.a1;
			}
		}
		cout <<cnt1+cnt2+cnt3<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
