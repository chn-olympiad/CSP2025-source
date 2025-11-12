#include<bits/stdc++.h>
using namespace std;
int T,n;
struct a_member{
	int a_,b_,c_,in;
			   //in a:1 b:2 c:3
}s[100010];
int sum,suma,sumb,sumc;
bool cmpa(a_member a,a_member b){
	if(a.a_==b.a_)
		return min(a.a_-a.b_,a.a_-a.c_)<min(b.a_-b.b_,b.a_-b.c_);
	return a.a_<b.a_;
}
bool cmpb(a_member a,a_member b){
	if(a.b_==b.b_)
		return min(a.b_-a.a_,a.b_-a.c_)<min(b.b_-b.a_,b.b_-b.c_);
	return a.b_<b.b_;
}
bool cmpc(a_member a,a_member b){
	if(a.c_==b.c_)
		return min(a.c_-a.a_,a.c_-a.b_)<min(b.c_-b.a_,b.c_-b.b_);
	return a.c_<b.c_;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		sum=suma=sumb=sumc=0;
		cin>>n;
		for(int i=0;i<n;i++)
			cin>>s[i].a_>>s[i].b_>>s[i].c_;
		for(int i=0;i<n;i++){
			if(s[i].a_>=s[i].b_&&s[i].a_>=s[i].c_){suma++;s[i].in=1;}
			if(s[i].b_>=s[i].a_&&s[i].b_>=s[i].c_){sumb++;s[i].in=2;}
			if(s[i].c_>=s[i].a_&&s[i].c_>=s[i].b_){sumc++;s[i].in=3;}
		}
		
		cout<<suma<<' '<<sumb<<' '<<sumc<<'\n';
		if(suma>(n/2)){
			sort(s,s+n,cmpa);
			for(int i=0;i<n;i++)cout<<'['<<s[i].a_<<' '<<s[i].b_<<' '<<s[i].c_<<']';
			int i=0;while(suma>(n/2)){
			if(s[i].b_>=s[i].c_){if(sumb<(n/2)){s[i].in=2;suma--;sumb++;
				}else{s[i].in=3;suma--;sumc++;}
			}else{if(sumb<(n/2)){s[i].in=3;suma--;sumc++;
				}else{s[i].in=2;suma--;sumb++;}}
			i++;}
		}
		if(sumb>(n/2)){sort(s,s+n,cmpb);
			for(int i=0;i<n;i++)cout<<'['<<s[i].a_<<' '<<s[i].b_<<' '<<s[i].c_<<']';
			int i=0;while(sumb>(n/2)){
			if(s[i].a_>=s[i].c_){if(suma<(n/2)){s[i].in=1;sumb--;suma++;
				}else{s[i].in=3;sumb--;sumc++;}
			}else{if(sumc<(n/2)){s[i].in=3;sumb--;sumc++;
				}else{s[i].in=1;sumb--;suma++;}}
			i++;}
		}
		if(sumc>(n/2)){
			sort(s,s+n,cmpc);
			for(int i=0;i<n;i++)cout<<'['<<s[i].a_<<' '<<s[i].b_<<' '<<s[i].c_<<']';
			int i=0;while(sumc>(n/2)){
			if(s[i].a_>=s[i].b_){if(suma<(n/2)){s[i].in=1;sumc--;suma++;
				}else{s[i].in=2;sumc--;sumb++;}
			}else{if(sumb<(n/2)){s[i].in=2;sumc--;sumb++;
				}else{s[i].in=1;sumc--;suma++;}
			i++;}
			}
		}
		cout<<suma<<' '<<sumb<<' '<<sumc<<'\n';
		for(int i=0;i<n;i++){
			if(s[i].in==1)sum+=s[i].a_;
			if(s[i].in==2)sum+=s[i].b_;
			if(s[i].in==3)sum+=s[i].c_;
		}
		cout<<sum<<"\n";
	}
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/