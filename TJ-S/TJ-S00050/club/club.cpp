#include<bits/stdc++.h>
using namespace std;
const int MX=2e5+29;
struct z{
	int s[29],n1,n2,n3,c1,c2;
}a[MX];
bool cmp(z a,z b){
	if(a.c1!=b.c1)return a.c1<b.c1;
	return a.c2<b.c2;
}
bool cmp2(z a,z b){
	return a.s[4]>b.s[4];
}
int b[29];
int z=0;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		if(n==2){
			long long z=0,a11=0,a22=0,a33=0,a44=0,a55=0,a66=0;
			int aaa,bbb,ccc,ddd,eee,fff;
			cin>>aaa>>bbb>>ccc>>ddd>>eee>>fff;
			a11=aaa+eee;
			a22=aaa+fff;
			a33=bbb+ddd;
			a44=bbb+fff;
			a55=ccc+ddd;
			a66=ccc+eee;
			z=max(max(max(a11,a22),max(a33,a44)),max(a55,a66));
			cout<<z<<'\n';
			continue;
		}else if(n==4){
			long long z=0,a11=0,a22=0,a33=0,a44=0,a55=0,a66=0,a77=0,a88=0;
			int aaa,bbb,ccc, ddd,eee,fff, ggg,hhh,iii, jjj,kkk,lll;
			cin>>aaa>>bbb>>ccc>>ddd>>eee>>fff>>ggg>>hhh>>iii>>jjj>>kkk>>lll;
			a11=max(aaa+ddd+hhh+kkk,aaa+ddd+iii+lll);
			a22=max(aaa+ddd+hhh+lll,aaa+ddd+iii+kkk);
			a33=max(aaa+eee+ggg+kkk,aaa+eee+hhh+jjj);
			a44=max(aaa+eee+ggg+lll,aaa+eee+iii+jjj);
			a55=max(bbb+ddd+hhh+lll,bbb+ddd+iii+kkk);
			a66=max(bbb+ddd+iii+jjj,bbb+ddd+ggg+lll);
			a77=max(ccc+ddd+hhh+jjj,ccc+ddd+ggg+kkk);
			a88=max(ccc+ddd+ggg+lll,ccc+ddd+iii+jjj);
			z=max(max(max(max(a11,a22),max(a33,a44)),max(a55,a66)),max(a77,a88));
			cout<<z<<'\n';
			continue;
		}
		int ss1=0,ss2=0,ss3=0,sss1=0,sss2=0,sss3=0;
		for(int i=1;i<=n;i++){
			cin>>a[i].s[1]>>a[i].s[2]>>a[i].s[3];
			if(a[i].s[1]>=a[i].s[2]&&a[i].s[2]>=a[i].s[3])
				a[i].n1=1,a[i].n2=2,a[i].n3=3,a[i].c1=a[i].s[1]-a[i].s[2],a[i].c2=a[i].s[2]-a[i].s[3],ss1++,sss2++,a[i].s[4]=a[i].s[1];
			else if(a[i].s[1]>=a[i].s[3]&&a[i].s[3]>=a[i].s[2])
				a[i].n1=1,a[i].n2=3,a[i].n3=2,a[i].c1=a[i].s[1]-a[i].s[3],a[i].c2=a[i].s[3]-a[i].s[2],ss1++,sss3++,a[i].s[4]=a[i].s[1];
			else if(a[i].s[2]>=a[i].s[1]&&a[i].s[1]>=a[i].s[3])
				a[i].n1=2,a[i].n2=1,a[i].n3=3,a[i].c1=a[i].s[2]-a[i].s[1],a[i].c2=a[i].s[1]-a[i].s[3],ss2++,sss1++,a[i].s[4]=a[i].s[2];
			else if(a[i].s[2]>=a[i].s[3]&&a[i].s[3]>=a[i].s[1])
				a[i].n1=2,a[i].n2=3,a[i].n3=1,a[i].c1=a[i].s[2]-a[i].s[3],a[i].c2=a[i].s[3]-a[i].s[1],ss2++,sss3++,a[i].s[4]=a[i].s[2];
			else if(a[i].s[3]>=a[i].s[1]&&a[i].s[1]>=a[i].s[2])
				a[i].n1=3,a[i].n2=1,a[i].n3=2,a[i].c1=a[i].s[3]-a[i].s[1],a[i].c2=a[i].s[1]-a[i].s[2],ss1++,sss2++,a[i].s[4]=a[i].s[3];
			else a[i].n1=3,a[i].n2=2,a[i].n3=1,a[i].c1=a[i].s[3]-a[i].s[2],a[i].c2=a[i].s[2]-a[i].s[1],ss2++,sss1++,a[i].s[4]=a[i].s[3];
		}
		sort(a+1,a+n+1,cmp);
		long long z1=0,z2=0,z=0;
		for(int i=1;i<=3;i++)b[i]=0;
		for(int i=1;i<=n;i++){
			if(b[a[i].n1]<n/2){
				z1+=a[i].s[a[i].n1];
				b[a[i].n1]++;
			}else if(b[a[i].n2]<n/2){
				z1+=a[i].s[a[i].n2];
				b[a[i].n2]++;
			}else{
				z1+=a[i].s[a[i].n3];
				b[a[i].n3]++;
			}
		}
		sort(a+1,a+n+1,cmp2);
		for(int i=1;i<=3;i++)b[i]=0;
		for(int i=1;i<=n;i++){
			if(b[a[i].n1]<n/2){
				z2+=a[i].s[a[i].n1];
				b[a[i].n1]++;
			}else if(b[a[i].n2]<n/2){
				z2+=a[i].s[a[i].n2];
				b[a[i].n2]++;
			}else{
				z2+=a[i].s[a[i].n3];
				b[a[i].n3]++;
			}
		}
		z=max(z1,z2);
		cout<<z<<'\n';
	}
	return 0;
}
