#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+9;
struct p{
	int a,b,c;
};
p s[MAXN],a[MAXN],b[MAXN],c[MAXN];
int ai=0,bi=0,ci=0;
bool compa(p a,p b){
	return min(a.a-a.b,a.a-a.c)>min(b.a-b.b,b.a-b.c);
}
bool compb(p a,p b){
	return min(a.b-a.a,a.b-a.c)>min(b.b-b.a,b.b-b.c);
}
bool compc(p a,p b){
	return min(a.c-a.b,a.c-a.a)>min(b.c-b.b,b.c-b.a);
}
void replace(int o){
	if(o==0){
		p temp=a[ai-1];
		if(temp.b>temp.c){
			b[bi]=temp;
			bi++;
		}else{
			c[ci]=temp;
			ci++;
		}
		ai--;
		return ;
	}
	if(o==1){
		p temp=b[bi-1];
		if(temp.a>temp.c){
			a[ai]=temp;
			ai++;
		}else{
			c[ci]=temp;
			ci++;
		}
		bi--;
		return ;
	}
	p temp=c[ci-1];
	if(temp.a>temp.b){
		a[ai]=temp;
		ai++;
	}else{
		b[bi]=temp;
		bi++;
	}
	ci--;
	return ;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		ai=0;
		bi=0;
		ci=0;
		int n,ans=0;
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>s[i].a>>s[i].b>>s[i].c;
		}
		for(int i=0;i<n;i++){
			int temp=max(s[i].a,max(s[i].b,s[i].c));
			if(s[i].a==temp){
				a[ai]=s[i];
				ai++;
			}else if(s[i].b==temp){
				b[bi]=s[i];
				bi++;
			}else{
				c[ci]=s[i];
				ci++;
			};
		}
		int th=0,mp=0;
		if(ai>th){
			th=ai;
		}
		if(bi>th){
			th=bi;
			mp=1;
		}
		if(ci>th){
			th=ci;
			mp=2;
		}
		sort(a,a+ai,compa);
		sort(b,b+bi,compb);
		sort(c,c+ci,compc);
		for(int i=th;i>n/2;i--){
			replace(mp);
		}
		for(int i=0;i<ai;i++){
			ans+=a[i].a;
			//clog<<a[i].a<<" "<<a[i].b<<" "<<a[i].c<<endl;
		}
		//clog<<endl;
		for(int i=0;i<bi;i++){
			ans+=b[i].b;
			//clog<<b[i].a<<" "<<b[i].b<<" "<<b[i].c<<endl;
		}
		//clog<<endl;
		for(int i=0;i<ci;i++){
			ans+=c[i].c;
			//clog<<c[i].a<<" "<<c[i].b<<" "<<c[i].c<<endl;
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
