#include<bits/stdc++.h>
using namespace std;
int t,n,al,bl,cl,cnt1,cnt2,cnt3,p,m,v;
struct node{
	int a,b,c,z,k;
}a[100010];
bool cmp(node x,node y){
	if(x.k<y.k) return 1;
	else if(x.k>y.k) return 0;
	else return x.z<y.z; 
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin.tie(0);
	cin>>t;
	while(t--){
		al=0,bl=0,cl=0,cnt1=0,cnt2=0,cnt3=0;
		cin>>n;
		v=n;
		p=n/2;
		for(int i=1;i<=n;i++){
			cin>>a[i].a>>a[i].b>>a[i].c;
			m=max(max(a[i].a,a[i].b),a[i].c);
			cnt1+=a[i].a;
			cnt2+=a[i].b;
			cnt3+=a[i].c;
			a[i].a=m-a[i].a;
			a[i].b=m-a[i].b;
			a[i].c=m-a[i].c;
			if(a[i].a==0) al++;
			if(a[i].b==0) bl++;
			if(a[i].c==0) cl++;
		}
		if(al>=bl&&al>=cl){
			for(int i=1;i<=n;i++){
				a[i].z=a[i].a;
				a[i].k=min(a[i].b-a[i].a,a[i].c-a[i].a);
			}
			sort(a+1,a+1+n,cmp);
			for(int i=1;i<=n;i++){
				if(a[i].k<=0){
					cnt1-=a[i].k;	
					v--;
				} 
				else{
					if(v>p){
						while(v-p>0){
							cnt1-=a[n-v+1].k;
							v--; 
						}
					}
					break;
				}
			}
			cout<<cnt1<<endl;
		}
		else if(bl>=al&&bl>=cl){
			for(int i=1;i<=n;i++){
				a[i].z=a[i].b;
				a[i].k=min(a[i].a-a[i].b,a[i].c-a[i].b);
			}
			sort(a+1,a+1+n,cmp);
			for(int i=1;i<=n;i++){
				if(a[i].k<=0){
					cnt2-=a[i].k;	
					v--;
				} 
				else{
					if(v>p){
						while(v-p>0){
							cnt2-=a[n-v+1].k;
							v--; 
						}
					}
					break;
				}
			}
			cout<<cnt2<<endl;
		}
		else{
			for(int i=1;i<=n;i++){
				a[i].z=a[i].c;
				a[i].k=min(a[i].a-a[i].c,a[i].b-a[i].c);
			}
			sort(a+1,a+1+n,cmp);
			for(int i=1;i<=n;i++){
				if(a[i].k<=0){
					cnt3-=a[i].k;	
					v--;
				} 
				else{
					if(v>p){
						while(v-p>0){
							cnt3-=a[n-v+1].k;
							v--; 
						}
					}
					break;
				}
			}
			cout<<cnt3<<endl;
		}
	}
	return 0;
}

