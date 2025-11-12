#include<bits/stdc++.h>
using namespace std;
int n;
int read(){
	int f=1,x=0;
	char ch=getchar();
	while(ch<'0' || '9'<ch){
		if(ch=='-'){
			f*=-1;
		}
		ch=getchar();
	}
	while('0'<=ch && ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return f*x;
}
struct edge{
	int a,b,c;
};
edge people[100005];
bool cmp(edge x,edge y){
	return x.a>y.a;
}
int ans=0;
int maxn=0;
int find(int step,int suma,int sumb,int sumc){
	if(step!=1){
		maxn=0;
		if(suma<n/2){
			ans+=people[step].a;
			maxn=max(maxn,find(step-1,suma+1,sumb,sumc));
			ans-=people[step].a;
		}
		if(sumb<n/2){
			ans+=people[step].b;
			maxn=max(maxn,find(step-1,suma,sumb+1,sumc));
			ans-=people[step].b;
		}
		if(sumc<n/2){
			ans+=people[step].c;
			maxn=max(maxn,find(step-1,suma,sumb,sumc+1));
			ans-=people[step].c;
		}
		return maxn;
	}
	else{
		if(suma<n/2){
			maxn=max(maxn,people[step].a);
		}
		if(sumb<n/2){
			maxn=max(maxn,people[step].b);
		}
		if(sumc<n/2){
			maxn=max(maxn,people[step].c);
		}
		int x=maxn;
		maxn=0;
		return x;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	t=read();
	while(t--){
		n=read();
		bool f=true;
		for(int i=1;i<=n;i++){
			people[i].a=read();
			people[i].b=read();
			people[i].c=read();
			if(people[i].b!=0 || people[i].c!=0){
				f=false;
			}
		}
		if(f){
			sort(people+1,people+n+1,cmp);
			int sum=0;
			for(int i=1;i<=n/2;i++){
				sum+=people[i].a;
			}
			cout<<sum<<endl;
			continue;
		}
		ans=0;
		maxn=0;
		cout<<find(n,0,0,0)<<endl;
	} 
	fclose(stdin);
	fclose(stdout);
	return 0;
}


