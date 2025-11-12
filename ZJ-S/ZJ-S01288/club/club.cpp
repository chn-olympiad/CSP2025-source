#include<bits/stdc++.h>
using namespace std;
struct people{
	int a,b,c;
	int mx;
	
};
bool p(people bb,people ba){
		int mmx;
		if(bb.a==bb.mx){
			mmx=max(bb.b,bb.c);
		}
		if(bb.b==bb.mx){
			mmx=max(bb.a,bb.c);
		}
		if(bb.c==bb.mx){
			mmx=max(bb.b,bb.a);
		}
		int mmxx;
		if(ba.a==ba.mx){
			mmxx=max(ba.b,ba.c);
		}
		if(ba.b==ba.mx){
			mmxx=max(ba.a,ba.c);
		}
		if(ba.c==ba.mx){
			mmxx=max(ba.b,ba.a);
		}
		return ba.mx-mmxx<bb.mx-mmx;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int n;
	cin>>n;


	for(int dk=0;dk<n;dk++){
		int m;
		cin>>m;
		int zong=0;
		int r1=0,r2=0,r3=0;
		int m1=0,m2=0,m3=0;
		vector<people>r;
		
		for(int i=0;i<m;i++){
			int a,b,c;
			cin>>a>>b>>c;
			people z;
			z.a=a;
			z.b=b;
			z.c=c;
			z.mx=max(max(a,b),c);
			r.push_back(z);
		}
		sort(r.begin(),r.end(),p);
		for(int i=0;i<m;i++){
			if(r1<m/2 &&r2<m/2 &&r3<m/2){
				zong+=r[i].mx;
				if(r[i].mx==r[i].a){
					r1++;
				}
				if(r[i].mx==r[i].b){
					r2++;
				}
				if(r[i].mx==r[i].c){
					r3++;
				}
			}else{
				if(r1==m/2 && r[i].mx==r[i].a){
					
					zong+=max(r[i].b,r[i].c);
				}else if(r2==m/2 && r[i].mx==r[i].b){
					zong+=max(r[i].a,r[i].c);
				}else if(r3==m/2 && r[i].mx==r[i].c){
					zong+=max(r[i].a,r[i].b);			
				}else{
					zong+=r[i].mx;
				}
				
			}
		}
		cout<<zong<<endl;
		
	}
}
