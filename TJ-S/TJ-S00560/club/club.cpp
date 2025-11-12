#include<bits/stdc++.h>
using namespace std;
long long k[110][110];
long long biao[110][110];
long long person[3];
long long kk,kkk;
struct like{
	int a,b,c,name;
}li[100010];
long long t,n;
long long ans;
bool we(like a,like b){
	if(a.a==b.a){
		if(a.b==b.b){
			return a.c>=b.c;
		}
		return a.b>b.b;
	}
	return a.a>b.a;
}
bool qw(int a,int b){
	return a>b;
}
void find(int a,int b,int c,int i,long long anss){
	if(i==n+1){
		ans=max(ans,anss);
		return;
	}
	if((a+1)<=(n/2)){
		find(a+1,b,c,i+1,anss+li[i].a);
	}
	if((b+1)<=(n/2)){
		find(a,b+1,c,i+1,anss+li[i].b);
	}
	if((c+1)<=(n/2)){
		find(a,b,c+1,i+1,anss+li[i].c);
	}
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int q=1;q<=t;q++){
		cin>>n;
		kk=kkk=0;
		for(int i=1;i<=n;i++){
			cin>>li[i].a>>li[i].b>>li[i].c;
			li[i].name=i;
			kk+=li[i].b;
			kkk+=li[i].c;
		}
		ans=0;
		sort(li+1,li+1+n,we);
		if(n<=30){
			find(0,0,0,1,0);
			cout<<ans;		
		}else{
			if(kk==0 && kkk==0){
				for(int i=1;i<=n/2;i++){
					ans+=li[i].a;
				}
				cout<<ans;
			}
			else if(kkk==0){
				int chaa[50010];
				int chab[50010];
				for(int i=1;i<=n;i++){
					if(i<=n/2){
						chaa[i]=li[i].b-li[i].a;
						ans+=li[i].a;
					}else{
						int y=i-(n/2);
						chab[y]=li[y].a-li[y].b;
						ans+=li[i].b;
					}
				}
				sort(chaa+1,chaa+1+n,qw);
				sort(chab+1,chab+1+n,qw);
				int qwer=1;
				while(chaa[qwer]+chab[qwer]>=0){
					ans+=chaa[qwer]+chab[qwer];
					qwer++;
				}
				cout<<ans;
			}else{
				find(0,0,0,1,0);
				cout<<ans;
			}			
		}
	fclose(stdin);
	fclose(stdout);
	}
}
