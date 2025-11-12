#include<bits/stdc++.h>
using namespace std;
const int e=2e6;
long long int t,n,d,d1,d2,d3;
struct V{
	long long int _1,_2,_3,a1,a2,a3,choice,val,no,choice_val,first,second,third;
}a[e];
bool cmp(V x,V y){
	if(x.no==0){
		if(y.no==0){
			if(x.choice_val>=y.choice_val)return 1;
			else return 0;
		}
		else return 1;
	}
	else return 0;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;++i){
			int x,y,z,r;
			cin>>x>>y>>z;
			a[i]._1=x;a[i]._2=y;a[i]._3=z;
			a[i].a1=x-y-z;a[i].a2=y-x-z;a[i].a3=z-x-y;
			r=max(a[i].a1,max(a[i].a2,a[i].a3));
			if(r==a[i].a1){
				a[i].choice=1;
				a[i].val=x;
				a[i].choice_val=a[i].a1;
				a[i].first=1;
				int p=max(a[i].a2,a[i].a3);
				if(p==a[i].a2){
					a[i].second=2;
					a[i].third=3;
				}
				else{
					a[i].second=3;
					a[i].third=2;
				}
			}
			else if(r==a[i].a2){
				a[i].choice=2;
				a[i].val=y;
				a[i].choice_val=a[i].a2;
				a[i].first=2;
				int p=max(a[i].a1,a[i].a3);
				if(p==a[i].a1){
					a[i].second=1;
					a[i].third=3;
				}
				else{
					a[i].second=3;
					a[i].third=1;
				}
			}
			else{
				a[i].choice=3;
				a[i].val=z;
				a[i].choice_val=a[i].a3;
				a[i].first=3;
				int p=max(a[i].a2,a[i].a1);
				if(p==a[i].a2){
					a[i].second=2;
					a[i].third=1;
				}
				else{
					a[i].second=1;
					a[i].third=2;
				}
			}
		}
		sort(a+1,a+1+n,cmp);
		for(int i=1;i<=n;++i){
			if(a[i].choice==1){
				if(d1==n/2)continue;
				else{
					d1+=1;
					d+=a[i].val;
					a[i].no=1;
				}
			}
			if(a[i].choice==2){
				if(d2==n/2)continue;
				else{
					d2+=1;
					d+=a[i].val;
					a[i].no=1;
				}
			}
			if(a[i].choice==3){
				if(d3==n/2)continue;
				else{
					d3+=1;
					d+=a[i].val;
					a[i].no=1;
				}
			}
		}
		if(d1+d2+d3!=n){
			for(int i=1;i<=n;++i){
				if(a[i].no==0){
					if(a[i].first==1){
						if(a[i].second==2){
							a[i].choice=2;
							a[i].choice_val=a[i]._2-a[i]._3;
							a[i].val=a[i]._2;
						}
						else{
							a[i].choice=3;
							a[i].choice_val=a[i]._3-a[i]._2;
							a[i].val=a[i]._3;
						}
					}
					if(a[i].first==2){
						if(a[i].second==1){
							a[i].choice=1;
							a[i].choice_val=a[i]._1-a[i]._3;
							a[i].val=a[i]._1;
						}
						else{
							a[i].choice=3;
							a[i].choice_val=a[i]._3-a[i]._1;
							a[i].val=a[i]._3;
						}
					}
					if(a[i].first==3){
						if(a[i].second==2){
							a[i].choice=2;
							a[i].choice_val=a[i]._2-a[i]._1;
							a[i].val=a[i]._2;
						}
						else{
							a[i].choice=1;
							a[i].choice_val=a[i]._1-a[i]._2;
							a[i].val=a[i]._1;
						}
					}
				}
			}
			sort(a+1,a+1+n,cmp);
			for(int i=1;i<=n,a[i].no==0;++i){
				if(a[i].choice==1){
					if(d1==n/2)continue;
					else{
						d1+=1;
						d+=a[i].val;
						a[i].no=1;
					}
				}
				if(a[i].choice==2){
					if(d2==n/2)continue;
					else{
						d2+=1;
						d+=a[i].val;
						a[i].no=1;
					}
				}
				if(a[i].choice==3){
					if(d3==n/2)continue;
					else{
						d3+=1;
						d+=a[i].val;
						a[i].no=1;
					}
				}
			}
		}
		cout<<d<<'\n';
		d=0;
		d1=0;
		d2=0;
		d3=0;
		for(int i=1;i<=n;++i){
			a[i].a1=0;a[i].a2=0;a[i].a3=0;
			a[i].choice=0;
			a[i].no=0;
			a[i].val=0;
		}
	}
	return 0;
} 