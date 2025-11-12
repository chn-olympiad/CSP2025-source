#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

struct con{
	public:
		int dpm;
		int stf;
};

struct man{
	public:
		con c[4];
		int sub,lsub;
}p[100010];

bool cmp(man x,man y){
	if(x.lsub>y.lsub){
		return true;
	}
	else if(x.lsub==y.lsub){
		if(x.sub>y.sub){
			return true;
		}
	}
	
	return false;
}

bool cmn(con x,con y){
	if(x.stf>y.stf){
		return true;
	}
	
	return false;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	int T;
	cin>>T;
	
	for(int k=1;k<=T;k++){
		int n;
		cin>>n;
		
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>p[i].c[j].stf;
				p[i].c[j].dpm=j;
			}
			sort(p[i].c+1,p[i].c+4,cmn);
			p[i].sub=p[i].c[1].stf-p[i].c[3].stf;
			p[i].lsub=p[i].c[1].stf-p[i].c[2].stf;
		}
		
		sort(p+1,p+n+1,cmp);
		
		int ans=0;
		int d[4]={0};
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				if(d[p[i].c[j].dpm]<n/2){
					d[p[i].c[j].dpm]++;
					ans+=p[i].c[j].stf;
					break;
				}
			}
		}
		
		cout<<ans<<endl;
	}
	
	
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}