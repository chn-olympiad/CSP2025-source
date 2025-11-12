#include<bits/stdc++.h>
using namespace std;
struct aa{
	int a;
	int b;
	int c;
}a[20008];
bool cmp1(aa a,aa b){
	return a.a+a.b+a.c>b.a+b.b+b.c;
}
bool cmp2(aa a,aa b){
	return a.a+a.b+a.c<b.a+b.b+b.c;
}
int a_,b_,c_;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n,mx=0,mx1=0,cnt=0,cnt1=0;
	cin>>t;
	while(t--){
		a_=0;
		b_=0;
		c_=0;
		cin>>n;
		cnt=cnt1=0;
		for(int i=1;i<=n;i++){
			cin>>a[i].a>>a[i].b>>a[i].c;
		}
		sort(a+1,a+1+n,cmp1);
		for(int i=1;i<=n;i++){
			mx=max(a[i].a,max(a[i].b,a[i].c));
			if(a[i].a==mx){
				a_++;
				cnt+=a[i].a;
			}
			else if(a[i].b==mx){
				b_++;
				cnt+=a[i].b;	
			}
			else if(a[i].c==mx){
				c_++;
				cnt+=a[i].c;
			}
			if(a_>n/2){
				a_--;
				cnt-=a[i].a;
				mx=max(a[i].b,a[i].c);
				if(a[i].b==mx){
					cnt+=a[i].b;
					b_++;
				}
				else if(a[i].c==mx){
					cnt+=a[i].c;
					c_++;	
				}
				if(b_>n/2){
					b_--;
					c_++;
					cnt-=a[i].b;
					cnt+=a[i].c;
				}
				if(c_>n/2){
					c_--;
					b_++;
					cnt-=a[i].c;
					cnt+=a[i].b;
				}
			}
			if(b_>n/2){
				b_--;
				cnt-=a[i].b;
				mx=max(a[i].a,a[i].c);
				if(a[i].a==mx){
					cnt+=a[i].a;
					a_++;
				}
				else if(a[i].c==mx){
					cnt+=a[i].c;
					c_++;	
				}
				if(a_>n/2){
					a_--;
					c_++;
					cnt-=a[i].a;
					cnt+=a[i].c;
				}
				if(c_>n/2){
					c_--;
					a_++;
					cnt-=a[i].c;
					cnt+=a[i].a;
				}
			}
			if(c_>n/2){
				c_--;
				cnt-=a[i].c;
				mx=max(a[i].b,a[i].a);
				if(a[i].b==mx){
					cnt+=a[i].b;
					b_++;
				}
				else if(a[i].a==mx){
					cnt+=a[i].a;
					a_++;	
				}
				if(b_>n/2){
					b_--;
					a_++;
					cnt-=a[i].b;
					cnt+=a[i].a;
				}
				if(a_>n/2){
					a_--;
					b_++;
					cnt-=a[i].a;
					cnt+=a[i].b;
				}
			}
		}
		sort(a+1,a+1+n,cmp2);
		a_=b_=c_=0;
		for(int i=1;i<=n;i++){
			mx1=max(a[i].a,max(a[i].b,a[i].c));
			if(a[i].a==mx1){
				a_++;
				cnt1+=a[i].a;
			}
			else if(a[i].b==mx1){
				b_++;
				cnt1+=a[i].b;	
			}
			else if(a[i].c==mx1){
				c_++;
				cnt1+=a[i].c;
			}
			if(a_>n/2){
				a_--;
				cnt1-=a[i].a;
				mx1=max(a[i].b,a[i].c);
				if(a[i].b==mx1){
					cnt1+=a[i].b;
					b_++;
				}
				else if(a[i].c==mx1){
					cnt1+=a[i].c;
					c_++;	
				}
				if(b_>n/2){
					b_--;
					c_++;
					cnt1-=a[i].b;
					cnt1+=a[i].c;
				}
				if(c_>n/2){
					c_--;
					b_++;
					cnt1-=a[i].c;
					cnt1+=a[i].b;
				}
			}
			if(b_>n/2){
				b_--;
				cnt1-=a[i].b;
				mx1=max(a[i].a,a[i].c);
				if(a[i].a==mx1){
					cnt1+=a[i].a;
					a_++;
				}
				else if(a[i].c==mx1){
					cnt1+=a[i].c;
					c_++;	
				}
				if(a_>n/2){
					a_--;
					c_++;
					cnt1-=a[i].a;
					cnt1+=a[i].c;
				}
				if(c_>n/2){
					c_--;
					a_++;
					cnt1-=a[i].c;
					cnt1+=a[i].a;
				}
			}
			if(c_>n/2){
				c_--;
				cnt1-=a[i].c;
				mx1=max(a[i].b,a[i].a);
				if(a[i].b==mx1){
					cnt1+=a[i].b;
					b_++;
				}
				else if(a[i].a==mx){
					cnt1+=a[i].a;
					a_++;	
				}
				if(b_>n/2){
					b_--;
					a_++;
					cnt1-=a[i].b;
					cnt1+=a[i].a;
				}
				if(a_>n/2){
					a_--;
					b_++;
					cnt1-=a[i].a;
					cnt1+=a[i].b;
				}
			}
		}
		cout<<max(cnt,cnt1)<<endl; 
	}
	return 0;
}