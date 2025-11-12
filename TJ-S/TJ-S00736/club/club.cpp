#include<bits/stdc++.h>
using namespace std;
int t[3];
struct ac{
	int x1,x2,x3,fl=0;
}a[100005];
bool cmp1(ac x,ac y){
		return x.x1>y.x1;
}
bool cmp2(ac x,ac y){
		return x.x2>y.x2;
}
bool cmp3(ac x,ac y){
		return x.x3>y.x3;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		int n,s=0;
		cin>>n;
		memset(t,0,sizeof(t));
		memset(a,0,sizeof(a));
		for(int i=1;i<=n;i++){
			cin>>a[i].x1>>a[i].x2>>a[i].x3;
		}
		sort(a+1,a+n+1,cmp1);
		for(int i=1;i<=n;i++){
		}
		for(int i=1;i<=n;i++){
			if(!a[i].fl&&a[i].x1>a[i].x2&&a[i].x1>a[i].x3&&t[1]<n/2){
				a[i].fl=1;
				s+=a[i].x1;
				t[1]++;
			}
		}
		sort(a+1,a+n+1,cmp2);
		for(int i=1;i<=n;i++){
			if(!a[i].fl&&a[i].x2>a[i].x1&&a[i].x2>a[i].x3&&t[2]<n/2){
				a[i].fl=1;
				s+=a[i].x2;
				t[2]++;
			}
		}
		sort(a+1,a+n+1,cmp3);
		for(int i=1;i<=n;i++){
			if(!a[i].fl&&a[i].x3>a[i].x1&&a[i].x3>a[i].x2&&t[3]<n/2){
				a[i].fl=1;
				s+=a[i].x3;
				t[3]++; 
			}
		}
		sort(a+1,a+n+1,cmp1);
		for(int i=1;i<=n;i++){
			if(!a[i].fl&&(a[i].x1==a[i].x2||a[i].x1==a[i].x3)&&a[i].x2!=a[i].x3){
				a[i].fl=1;
				if(a[i].x1==a[i].x2){
					if(t[1]<=t[2]&&t[1]<n/2){
						s+=a[i].x1;
						t[1]++;
					}
					else if(t[1]>t[2]&&t[2]<n/2){
						s+=a[i].x2;
						t[2]++;
					}
				}
				if(a[i].x1==a[i].x3){
					if(t[1]<=t[3]&&t[1]<n/2){
						s+=a[i].x1;
						t[1]++;
					}
					else if(t[1]>t[3]&&t[3]<n/2){
						s+=a[i].x3;
						t[3]++;
					}
				}
			}
		}
		sort(a+1,a+n+1,cmp2);
		for(int i=1;i<=n;i++){
			if(!a[i].fl&&a[i].x2==a[i].x3&&a[i].x1!=a[i].x2&&a[i].x1!=a[i].x3){
				a[i].fl=1;
				if(t[2]<=t[3]&&t[2]<n/2){
					s+=a[i].x2;
					t[2]++;
				}
				else if(t[2]>t[3]&&t[3]<n/2){
					s+=a[i].x3;
					t[3]++;
				}
			}
		}
		for(int i=1;i<=n;i++){
			if(!a[i].fl){
				a[i].fl=1;
				s+=a[i].x1;
				int minn=min(t[1],min(t[2],t[3]));
				if(t[1]==minn&&minn<n/2){
					t[1]++;
				}
				if(t[2]==minn&&minn<n/2){
					t[2]++;
				}
				if(t[3]==minn&&minn<n/2){
					t[3]++;
				}
			}
		}
		cout<<s<<endl;
	}
	return 0;
}
