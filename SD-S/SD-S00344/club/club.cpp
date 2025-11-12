#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
const int MA=2e5+10;
int T; 
struct node{
	int a1,a2,a3;
}a[MA];
bool cmp(node a,node b){
	return max(a.a1,max(a.a2,a.a3))>max(b.a1,max(b.a2,b.a3));
}
int main(){
	//freopen("club.in","r",stdin);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	//freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		int ans=0;
		int mmm=-1;
		int maa=n/2;
		int m1=0,m2=0,m3=0;
		for(int i=1;i<=n;i++){
			cin>>a[i].a1>>a[i].a2>>a[i].a3;
			mmm+=max(a[i].a1,max(a[i].a2,a[i].a3));
		}
		sort(a+1,a+n+1,cmp);
		if(n<=3){
			cout<<mmm<<endl;
			return 0;
		} 
		else{
			for(int i=1;i<=n;i++){
				int mm=max(a[i].a1,max(a[i].a2,a[i].a3));
				if(mm==a[i].a1){
					if(m1<maa){
						ans+=a[i].a1;
						m1++;
					}
					else{
						int cmm=max(a[i].a2,a[i].a3);
						if(cmm==a[i].a2){
							if(m2<maa){
								ans+=a[i].a2;
								m2++;
							}
							else{
								continue;
							}
						}
						else{
							ans+=a[i].a3;
							m3++;
						}
					}
				}
				else if(mm==a[i].a2){
					if(m2<maa){
						ans+=a[i].a2;
						m2++;
					}
					else{
						int cmm=max(a[i].a1,a[i].a3);
						if(cmm==a[i].a1){
							if(m1<maa){
								ans+=a[i].a1;
								m1++;
							}
							else{
								continue;
							}
						}
						else{
							ans+=a[i].a3;
							m3++;
						}
					}
				}
				else{
					if(m3<maa){
						ans+=a[i].a3;
						m3++;
					}
					else{
						int cmm=max(a[i].a1,a[i].a2);
						if(cmm==a[i].a1){
							if(m1<maa){
								ans+=a[i].a1;
								m1++;
							}
							else{
								continue;
							}
						}
						else{
							ans+=a[i].a2;
							m2++;
						}
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
} 
