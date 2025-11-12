#include <bits/stdc++.h>
using namespace std;
const int N=100005;
struct v{
	int a,b,c;
}v1[N],a1[N],a2[N],a3[N];
bool cmp(v p,v q){
	return p.a>q.a;
}
bool cmp1(v p,v q){
	return p.b>q.b;
}
bool cmp2(v p,v q){
	return p.c>q.c;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int i=1;i<=t;i++){
		int n,n1=0,n2=0,n3=0,m1=0,m2=0,m3=0;
		cin>>n;
		int maxx=n/2;
		for(int j=1;j<=n;j++){
			cin>>v1[j].a>>v1[j].b>>v1[j].c;
			if(v1[j].a>=v1[j].b&&v1[j].a>=v1[j].c){
				a1[n1].a=v1[j].a;
				a1[n1].b=v1[j].b;
				a1[n1++].c=v1[j].c;
				m1+=v1[j].a;
			}else if(v1[j].b>=v1[j].a&&v1[j].b>=v1[j].c){
				a2[n2].a=v1[j].a;
				a2[n2].b=v1[j].b;
				a2[n2++].c=v1[j].c;
				m2+=v1[j].b;
			}else if(v1[j].c>=v1[j].b&&v1[j].c>=v1[j].a){
				a3[n3].a=v1[j].a;
				a3[n3].b=v1[j].b;
				a3[n3++].c=v1[j].c;
				m3+=v1[j].c;
			}else{
				a1[n1].a=v1[j].a;
				a1[n1].b=v1[j].b;
				a1[n1++].c=v1[j].c;
				m1+=v1[j].a;
			}
		}
		sort(a1+1,a1+1+n,cmp1);
		sort(a2+1,a2+1+n,cmp2); 
		sort(a3+1,a3+1+n,cmp);
		if(n1<=maxx&&n2<=maxx&&n3<=maxx)  cout<<m1+m2+m3<<endl;
		else{
			while(!(n1<=maxx&&n2<=maxx&&n3<=maxx)){
			if(n1>maxx){
				a2[n+1].a=a1[1].a;
				a2[n+1].b=a1[1].b;
				a2[n+1].c=a1[1].c;
				m1-=a1[1].a;
				m2+=a1[1].b; 
				a1[1].a=0;
				a1[1].b=0;
				a1[1].c=0;
				n1--;
				n2++;
				sort(a1+1,a1+1+n,cmp1);
				sort(a2+1,a2+1+n,cmp2);
			}if(n2>maxx){
				a3[n+1].a=a2[1].a;
				a3[n+1].b=a2[1].b;
				a3[n+1].c=a2[1].c;
				m2-=a2[1].b;
				m3+=a2[1].c;
				a2[1].a=0;
				a2[1].b=0;
				a2[1].c=0;
				n2--;
				m3++;
				sort(a2+1,a2+1+n,cmp2);
				sort(a3+1,a3+1+n,cmp);
			}if(n3>maxx){
				a1[n+1].a=a3[1].a;
				a1[n+1].b=a3[1].b;
				a1[n+1].c=a3[1].c;
				m3-=a3[1].c;
				m1+=a3[1].a;
				a3[1].a=0;
				a3[1].b=0;
				a3[1].c=0;
				n3--;
				n1++;
				sort(a3+1,a3+1+n,cmp);
				sort(a1+1,a1+1+n,cmp1);
			}
			for(int j=1;j<=n;j++){
				a1[j].a=0;
				a1[j].b=0;
				a1[j].c=0;
				a2[j].a=0;
				a2[j].b=0;
				a2[j].c=0;
				a3[j].a=0;
				a3[j].b=0;
				a3[j].c=0;
			}
			}
			cout<<m1+m2+m3<<endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*呜呜呜我实在不会了=_=|||写了整整100行两个半小时感觉脑子要炸了，还是不对
这回大概率是要爆零了…… 
这是我第一次参加CSP-S，但却是我最后一次参加CSP了
我也不相信自己才学了两年就要放弃了
因为一些听起来很荒唐的现实原因 
再见了CCF
再见了和我一起学习编程的小伙伴
几年后我一定会因为热爱再与你们相见的^u^  */ 
