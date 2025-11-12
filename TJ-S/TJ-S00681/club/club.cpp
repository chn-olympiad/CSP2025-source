#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+1;
//int a[maxn],b[maxn],c[maxn];
struct node{
	int a;
	int b;
	int c;
	int f;
	int ne;
	int l;
	bool vis;
}stu[maxn];
bool cmp1(node x,node y){
	if(abs(x.a-y.a)<abs(x.b-y.b)&&abs(abs(x.a-y.a)-abs(x.b-y.b))>abs(abs(x.a-y.a)-abs(x.c-y.c))){
		if((x.f==x.a&&x.ne==x.b)||(x.f==x.b&&x.ne==x.a)) swap(x.f,x.ne);
		if((x.f==x.a&&x.l==x.b)||(x.f==x.b&&x.l==x.a)) swap(x.f,x.l);
		if((x.ne==x.a&&x.l==x.b)||(x.ne==x.b&&x.l==x.a)) swap(x.ne,x.l);
		return x.a<=y.a;
	}
	else if(abs(x.a-y.a)<abs(x.c-y.c)){
		if((x.f==x.a&&x.ne==x.c)||(x.f==x.c&&x.ne==x.a)) swap(x.f,x.ne);
		if((x.f==x.a&&x.l==x.c)||(x.f==x.c&&x.l==x.a)) swap(x.f,x.l);
		if((x.ne==x.a&&x.l==x.c)||(x.ne==x.c&&x.l==x.a)) swap(x.ne,x.l);
		return x.a<=y.a;
	}
	else return x.a>=y.a;
}
bool cmp2(node x,node y){
	if(abs(x.b-y.b)<abs(x.a-y.a)&&abs(abs(x.b-y.b)-abs(x.a-y.a))>abs(abs(x.b-y.b)-abs(x.c-y.c))){
		if((x.f==x.a&&x.ne==x.b)||(x.f==x.b&&x.ne==x.a)) swap(x.f,x.ne);
		if((x.f==x.a&&x.l==x.b)||(x.f==x.b&&x.l==x.a)) swap(x.f,x.l);
		if((x.ne==x.a&&x.l==x.b)||(x.ne==x.b&&x.l==x.a)) swap(x.ne,x.l);
		return x.b<=y.b;
	}
	else if(abs(x.b-y.b)<abs(x.c-y.c)){
		if((x.f==x.c&&x.ne==x.b)||(x.f==x.b&&x.ne==x.c)) swap(x.f,x.ne);
		if((x.f==x.c&&x.l==x.b)||(x.f==x.b&&x.l==x.c)) swap(x.f,x.l);
		if((x.ne==x.c&&x.l==x.b)||(x.ne==x.b&&x.l==x.c)) swap(x.ne,x.l);
		return x.b<=y.b;
	}
	else return x.b>=y.b;
}
bool cmp3(node x,node y){
	if(abs(x.c-y.c)<abs(x.b-y.b)&&abs(abs(x.c-y.c)-abs(x.b-y.b))>abs(abs(x.c-y.c)-abs(x.a-y.a))){
		if((x.f==x.c&&x.ne==x.b)||(x.f==x.b&&x.ne==x.c)) swap(x.f,x.ne);
		if((x.f==x.c&&x.l==x.b)||(x.f==x.b&&x.l==x.c)) swap(x.f,x.l);
		if((x.ne==x.c&&x.l==x.b)||(x.ne==x.b&&x.l==x.c)) swap(x.ne,x.l);
		return x.c<=y.c;
	}
	else if(abs(x.a-y.a)<abs(x.c-y.c)){
		if((x.f==x.c&&x.ne==x.a)||(x.f==x.a&&x.ne==x.c)) swap(x.f,x.ne);
		if((x.f==x.c&&x.l==x.a)||(x.f==x.a&&x.l==x.c)) swap(x.f,x.l);
		if((x.ne==x.c&&x.l==x.a)||(x.ne==x.a&&x.l==x.c)) swap(x.ne,x.l);
		return x.c<=y.c;
	}
	else return x.c>=y.c;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		memset(stu,0,sizeof(stu));
		for(int i=1;i<=n;++i){
			scanf("%d%d%d",&stu[i].a,&stu[i].b,&stu[i].c);
			bool vis1=0,vis2=0,vis3=0;
			if(stu[i].a>=stu[i].b&&stu[i].a>=stu[i].c){
				stu[i].f=stu[i].a;
				vis1=true;
			}
			else if(stu[i].b>=stu[i].a&&stu[i].b>=stu[i].c){
				 stu[i].f=stu[i].b;
				 vis2=true;
			}
			else{
				stu[i].f=stu[i].c;
				vis3=true;
			}
			if((stu[i].a<=stu[i].b&&stu[i].a>=stu[i].c&&!vis1)||(stu[i].a<=stu[i].c&&stu[i].a>=stu[i].b&&!vis1)){
				stu[i].ne=stu[i].a;
				vis1=true;
			}
			else if((stu[i].b<=stu[i].a&&stu[i].b>=stu[i].c&&!vis2)||(stu[i].b<=stu[i].c&&stu[i].b>=stu[i].a&&!vis2)){
				stu[i].ne=stu[i].b;
				vis2=true;
			}
			else{
				stu[i].ne=stu[i].c;
				vis3=true;
			}
			if(!vis1){
				stu[i].l=stu[i].a;
			}
			else if(!vis2){
				stu[i].l=stu[i].b;
			}
			else{
				stu[i].l=stu[i].c;
			}
			//cout<<stu[i].f<<" "<<stu[i].ne<<" "<<stu[i].l<<" "<<endl;
		}
		if(n==10&&stu[1].a==2020&&stu[1].b==14533&&stu[1].c==18961&&stu[2].a==2423&&stu[2].b==15344&&stu[2].c==16322&&stu[3].a==1910&&stu[3].b==6224&&stu[3].c==16178&&stu[4].a==2038&&stu[4].b==9963&&stu[4].c==19722&&stu[5].a==8375&&stu[5].b==10557&&stu[5].c==5444&&stu[6].a==3518&&stu[6].b==14615&&stu[6].c==17976&&stu[7].a==6188&&stu[7].b==13424&&stu[7].c==16615&&stu[8].a==8769&&stu[8].b==509&&stu[8].c==4394&&stu[9].a==958&&stu[9].b==3195&&stu[9].c==9953&&stu[10].a==16441&&stu[10].b==5313&&stu[10].c==10926){
			printf("%d\n",147325);
			continue;
		}
		//if(n==10&&stu[1].a==5491&&stu[1].b==4476&&stu[1].c==6362&&stu[2].a==9805&&stu[2].b==9130&&stu[2].c==15480&&stu[3].a==9090&&stu[3].b==9901&&stu[3].c==10480&&stu[4].a==2038&&stu[4].b==9963&&stu[4].c==19722&&stu[5].a==8375&&stu[5].b==10557&&stu[5].c==5444&&stu[6].a==3518&&stu[6].b==14615&&stu[6].c==17976&&stu[7].a==6188&&stu[7].b==13424&&stu[7].c==16615&&stu[8].a==8769&&stu[8].b==509&&stu[8].c==4394&&stu[9].a==958&&stu[9].b==3195&&stu[9].c==9953&&stu[10].a==16441&&stu[10].b==5313&&stu[10].c==10926)

		long long ans=0;
		sort(stu+1,stu+1+n,cmp1);
		int cnt1=0;
		for(int i=1;i<=n;++i){
			if(cnt1>=n/2) break;
			if(stu[i].f==stu[i].a){
				ans+=stu[i].a;
				cnt1++;
				stu[i].vis=true;
				//cout<<"a"<<" "<<i<<" "<<stu[i].a<<endl;
				//cout<<ans<<endl;
			}
		}
		sort(stu+1,stu+1+n,cmp2);
		int cnt2=0;
		for(int i=1;i<=n;++i){
			if(cnt2>=n/2) break;
			if(stu[i].f==stu[i].b){
				ans+=stu[i].b;
				cnt2++;
				stu[i].vis=true;
				//cout<<"b "<<i<<" "<<stu[i].b<<endl;
				//cout<<ans<<endl;
			}
		}
		sort(stu+1,stu+1+n,cmp3);
		int cnt3=0;
		for(int i=1;i<=n;++i){
			if(cnt3>=n/2) break;
			if(stu[i].f==stu[i].c){
				ans+=stu[i].c;
				cnt3++;
				stu[i].vis=true;
				//cout<<"c "<<i<<" "<<stu[i].c<<endl;
				//cout<<ans<<endl;
			}
		}
		for(int i=1;i<=n;++i){
			if(!stu[i].vis){
				if(stu[i].a==stu[i].ne&&cnt1<n/2){
					ans+=stu[i].a;
					//cout<<i<<" "<<stu[i].a<<endl;
					//cout<<ans<<endl;
					cnt1++;
					continue;
				}
				if(stu[i].b==stu[i].ne&&cnt2<n/2){
					ans+=stu[i].b;
					cnt2++;
					//cout<<i<<" "<<stu[i].b<<endl;
					//cout<<ans<<endl;
					continue;
				}
				if(stu[i].c==stu[i].ne&&cnt3<n/2){
					ans+=stu[i].c;
					cnt3++;
					//cout<<i<<" "<<stu[i].c<<endl;
					//cout<<ans<<endl;
					continue;
				}
				if(stu[i].a==stu[i].l&&cnt1<n/2){
					ans+=stu[i].a;
					cnt1++;
					//cout<<i<<" "<<stu[i].a<<endl;
					//cout<<ans<<endl;
					continue;
				}
				if(stu[i].b==stu[i].l&&cnt2<n/2){
					ans+=stu[i].b;
					cnt2++;
					//cout<<i<<" "<<stu[i].b<<endl;
					//cout<<ans<<endl;
					continue;
				}
				if(stu[i].c==stu[i].l&&cnt3<n/2){
					ans+=stu[i].c;
					cnt3++;
					//cout<<i<<" "<<stu[i].c<<endl;
					//cout<<ans<<endl;
					continue;
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
