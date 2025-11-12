#include<bits/stdc++.h>
using namespace std;
int t;
struct h{
	int d1;
	int d2;
	int d3;
};
h a[100010];
long long c1,c2,c3;
int w1[100010],w2[100010],w3[100010];
int b[100010];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		c1=0;
		c2=0;
		c3=0;
		int n;
		cin>>n;
		int cnt1=0,cnt2=0,cnt3=0;
		for(int i=1;i<=n;i++){
			cin>>a[i].d1>>a[i].d2>>a[i].d3;
			if(max(a[i].d1,max(a[i].d2,a[i].d3))==a[i].d1){
				c1+=a[i].d1;
				cnt1++;
				w1[cnt1]=i;
				continue;
			}
			if(max(a[i].d1,max(a[i].d2,a[i].d3))==a[i].d2){
				c2+=a[i].d2;
				cnt2++;
				w2[cnt2]=i;
				continue;
			}
			if(max(a[i].d1,max(a[i].d2,a[i].d3))==a[i].d3){
				c3+=a[i].d3;
				cnt3++;
				w3[cnt3]=i;
				continue;
			}
		}
		if(cnt1<=n/2&&cnt2<=n/2&&cnt3<=n/2){
			cout<<c1+c2+c3<<endl;
			continue;
		}
		if(cnt1>n/2){
			for(int i=1;i<=cnt1;i++){
				b[i]=a[w1[i]].d1-max(a[w1[i]].d2,a[w1[i]].d3);
			}
			sort(b+1,b+cnt1+1);
			int sum=0;
			for(int i=1;i<=cnt1-n/2;i++)sum+=b[i];
			cout<<c1+c2+c3-sum<<endl;
			continue;
		}
		if(cnt2>n/2){
			for(int i=1;i<=cnt2;i++){
				b[i]=a[w2[i]].d2-max(a[w2[i]].d1,a[w2[i]].d3);
			}
			sort(b+1,b+cnt2+1);
			int sum=0;
			for(int i=1;i<=cnt2-n/2;i++)sum+=b[i];
			cout<<c1+c2+c3-sum<<endl;
			continue;
		}
		if(cnt3>n/2){
			for(int i=1;i<=cnt3;i++){
				b[i]=a[w3[i]].d3-max(a[w3[i]].d1,a[w3[i]].d2);
			}
			sort(b+1,b+cnt3+1);
			int sum=0;
			for(int i=1;i<=cnt3-n/2;i++)sum+=b[i];
			cout<<c1+c2+c3-sum<<endl;
			continue;
		}
	}
	return 0;
}
//Ren5Jie4Di4Ling5%
