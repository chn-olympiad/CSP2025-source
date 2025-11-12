#include <bits/stdc++.h>
using namespace std;
struct st{
	int a,b,c,d,e;
};
int cmp(st a,st b){
	return a.d>=b.d;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin >>t;
	for(int k=0;k<t;t++){
		int n;
		cin >>n;
		int cnt1=0,cnt2=0,cnt3=0;
		long long cnt=0;
		st a[n];
		for(int i=0;i<n;i++){
			int tep,tmp,temp;
			cin >>tep >>tmp >>temp;
			tmp-=tep;
			temp-=tep;
			a[i].a=tep;
			a[i].b=tmp;
			a[i].c=temp;
			if(0>=tmp and 0>=temp){
				a[i].d=0;
				a[i].e=1;
			}
			else if(tmp>=0 and tmp>=temp){
				a[i].d=tmp;
				a[i].e=2;
			}
			else if(temp>=0 and temp>=tmp){
				a[i].d=temp;
				a[i].e=3;
			}
		} 
		sort(a+0,a+n,cmp);
		for(int i=0;i<n;i++){
			cnt+=a[i].a;
			if(a[i].e==1){
				if(cnt1<n/2){
					cnt1++;
				}
				else{
					if(a[i].b>a[i].c){
						if(cnt2<n/2){
							cnt+=a[i].b;
							cnt2++;
						}
						else{
							cnt+=a[i].c;
							cnt3++;
						}
					}
					else{
						if(cnt3<n/2){
							cnt+=a[i].c;
							cnt3++;
						}
						else{
							cnt+=a[i].b;
							cnt2++;
						}
					}
				}
			}
			else if(a[i].e==2){
				if(cnt2<n/2){
					cnt+=a[i].d;
					cnt2++;
				}
				else{
					if(0>a[i].c){
						if(cnt1<n/2){
							cnt1++;
						}
						else{
							cnt+=a[i].c;
							cnt3++;
						}
					}
					else{
						if(cnt3<n/2){
							cnt+=a[i].c;
							cnt3++;
						}
						else{
							cnt1++;
						}
					}
				}
			}
			else{
				if(cnt3<n/2){
					cnt+=a[i].d;
					cnt3++;
				}
				else{
					if(a[i].b>0){
						if(cnt2<n/2){
							cnt+=a[i].b;
							cnt2++;
						}
						else{
							cnt1++;
						}
					}
					else{
						if(cnt1<n/2){
							cnt1++;
						}
						else{
							cnt+=a[i].b;
							cnt2++;
						}
					}
				}
			}
		}
		cout <<cnt <<endl;
	}
	return 0;
}

