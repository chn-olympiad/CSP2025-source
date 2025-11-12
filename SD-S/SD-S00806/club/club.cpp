#include<bits/stdc++.h>
using namespace std;
int t,n,mas;
struct ml{
	int a,b,c;
	int ab,bc,ac;
}x[10000010];
int aa[1000010],aaa;
int bb[1000010],bbb;
int cc[1000010],ccc;
int df[1000010],dd;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(0);
	cin>>t;
	while(t--){
		mas=0,aaa=0,bbb=0,ccc=0,dd=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>x[i].a>>x[i].b>>x[i].c;
			if(x[i].a>=x[i].b&&x[i].a>=x[i].c){
				aa[++aaa]=i;
				mas+=x[i].a;
			}else{
				if(x[i].b>=x[i].c&&x[i].b>=x[i].a){
					bb[++bbb]=i;
					mas+=x[i].b;
				}else{
					cc[++ccc]=i;
					mas+=x[i].c;
				}
			}
			x[i].ab=x[i].a-x[i].b;
			x[i].bc=x[i].b-x[i].c;
			x[i].ac=x[i].a-x[i].c;
		}
		if(aaa>n/2){
			for(int i=1;i<=aaa;i++){
				df[++dd]=min(x[aa[i]].ab,x[aa[i]].ac);
			}
			sort(df+1,df+1+dd);
			for(int i=1;i<=aaa-n/2;i++){
				mas-=df[i];
			}
		}
		if(bbb>n/2){
			for(int i=1;i<=bbb;i++){
				df[++dd]=min(-x[bb[i]].ab,x[bb[i]].bc);
			}
			sort(df+1,df+1+dd);
			for(int i=1;i<=bbb-n/2;i++){
				mas-=df[i];
			}
		}
		if(ccc>n/2){
			for(int i=1;i<=ccc;i++){
				df[++dd]=min(-x[cc[i]].bc,-x[cc[i]].ac);
			}
			sort(df+1,df+1+dd);
			for(int i=1;i<=ccc-n/2;i++){
				mas-=df[i];
			}
		}
		cout<<mas<<'\n';
	}
	return 0;
}

