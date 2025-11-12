#include<bits/stdc++.h>
using namespace std;
struct node{
	int aaa,bbb,ccc;
}stu[100001];
struct cha{
	int num;
	char from;
}b[100001];
bool cmp(cha x,cha y){
	 return x.num<y.num;
}
bool cmp1(cha xa,cha ya){
	 return xa.num<ya.num;
}
bool cmp2(cha xb,cha yb){
	 return xb.num<yb.num;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int ans=0,aa=0,bb=0,cc=0,m=0,xx=0;
		for(int i=1;i<=n;i++){
			cin >> stu[i].aaa >> stu[i].bbb >> stu[i].ccc;
			if(max(stu[i].aaa,stu[i].bbb)==stu[i].aaa && max(stu[i].aaa,stu[i].ccc)==stu[i].aaa){
				if(stu[i].bbb==stu[i].aaa){
					if(stu[i].ccc==stu[i].aaa){
						if(aa<bb && aa<=cc)aa++;ans+=stu[i].aaa;
						if(bb<=aa && bb<cc)bb++;ans+=stu[i].bbb;
						if(cc<aa && cc<=bb)cc++;ans+=stu[i].ccc;
					}
					else{
						if(aa<=bb){
							aa++;ans+=stu[i].aaa;	
						}
						else{
							bb++;ans+=stu[i].bbb;	
						} 
					}
				}
				else{
					aa++;
					ans+=stu[i].aaa;
				}
			}
			else if(max(stu[i].aaa,stu[i].bbb)==stu[i].bbb && max(stu[i].bbb,stu[i].ccc)==stu[i].bbb){
				if(stu[i].bbb==stu[i].ccc){
					if(stu[i].bbb==stu[i].aaa){
						if(aa<bb && aa<=cc)aa++;ans+=stu[i].aaa;
						if(bb<=aa && bb<cc)bb++;ans+=stu[i].bbb;
						if(cc<aa && cc<=bb)cc++;ans+=stu[i].ccc;
					}
					else{
						if(bb<=cc){
							bb++;ans+=stu[i].bbb;
						}
						else{
							cc++;ans+=stu[i].ccc;
						} 
					}
				}
				else{
					bb++;
					ans+=stu[i].bbb;
				}
			}
			else{
				if(stu[i].aaa==stu[i].ccc){
					if(stu[i].bbb==stu[i].aaa){
						if(aa<bb && aa<=cc)aa++;ans+=stu[i].aaa;
						if(bb<=aa && bb<cc)bb++;ans+=stu[i].bbb;
						if(cc<aa && cc<=bb)cc++;ans+=stu[i].ccc;
					}
					else{
						if(cc<=aa){
							cc++;ans+=stu[i].ccc;	
						}
						else{
							aa++;ans+=stu[i].aaa;
						}
					}
				}
				else{
					cc++;
					ans+=stu[i].ccc;
				}
			}
		}
		if(aa>n/2){
			for(int i=1;i<=n;i++){
				if(max(stu[i].aaa,stu[i].bbb)==stu[i].aaa && max(stu[i].aaa,stu[i].ccc)==stu[i].aaa){
					b[++m].num=stu[i].aaa-stu[i].bbb;
					b[m].from='b';
					b[++m].num=stu[i].aaa-stu[i].ccc;
					b[m].from='c';
				}
			}
			sort(b+1,b+m+1,cmp);
			while(aa>n/2){
				if(b[++xx].from=='b'){
					if(bb+1<=n/2){
						ans-=b[xx].num;
						aa--;
						bb++;
					}
				}
				else{
					if(cc+1<=n/2){
						ans-=b[xx].num;
						aa--;
						cc++;
					}
				}
			}
		}
		if(bb>n/2){
			for(int i=1;i<=n;i++){
				if(max(stu[i].aaa,stu[i].bbb)==stu[i].bbb && max(stu[i].bbb,stu[i].ccc)==stu[i].bbb){
					b[++m].num=stu[i].bbb-stu[i].aaa;
					b[m].from='a';
					b[++m].num=stu[i].bbb-stu[i].ccc;
					b[m].from='c';
				}
			}
			sort(b+1,b+1+m,cmp1);
			while(bb>n/2){
				if(b[++xx].from=='a'){
					if(aa+1<=n/2){
						ans-=b[xx].num;
						bb--;
						aa++;
					}
				}
				else{
					if(cc+1<=n/2){
						ans-=b[xx].num;
						bb--;
						cc++;
					}
				}
			}
		}
		if(cc>n/2){
			for(int i=1;i<=n;i++){
				if(max(stu[i].ccc,stu[i].bbb)==stu[i].ccc && max(stu[i].aaa,stu[i].ccc)==stu[i].ccc){
					b[++m].num=stu[i].ccc-stu[i].aaa;
					b[m].from='a';
					b[++m].num=stu[i].ccc-stu[i].bbb;
					b[m].from='b';
				}
			}
			sort(b+1,b+1+m,cmp2);
			while(cc>n/2){
				if(b[++xx].from=='a'){
					if(aa+1<=n/2){
						ans-=b[xx].num;
						cc--;
						aa++;
					}
				}
				else{
					if(bb+1<=n/2){
						ans-=b[xx].num;
						cc--;
						bb++;
					}
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
//Ren5Jie4Di4Ling5%
