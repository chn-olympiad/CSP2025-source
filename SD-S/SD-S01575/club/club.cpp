#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+10;
struct node{
	int a,b,c,id;
	int Max,Maxclub;
	int Maxc,Maxcclub;
	int Maxcc,Maxccclub;
	int all;
}stu[N];
int n;
node c1[N],c2[N],c3[N];
bool cmp(node x,node y){
	if(x.Max==y.Max){
		if(x.Maxc==y.Maxc)return x.Maxcc>y.Maxcc;
		return x.Maxc>y.Maxc;
	}
	return x.Max>y.Max;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		memset(c1,0,sizeof(c1));
		memset(c2,0,sizeof(c2));
		memset(c3,0,sizeof(c3));
		cin>>n;
		if(n==2){
			int a1,b1,c1;
			cin>>a1>>b1>>c1;
			int a2,b2,c2;
			cin>>a2>>b2>>c2;
			int k1=a1+b2;
			int k2=a1+c2;
			int k3=b1+a2;
			int k4=b1+c2;
			int k5=c1+a2;
			int k6=c1+b2;
			int ans=0;
			ans=max(max(max(k1,k2),max(k3,k4)),max(k5,k6));
			cout<<ans<<"\n"; 
			break;
		}
		/*if(n==4){
			int a1,a2,a3;
			int b1,b2,b3;
			int c1,c2,c3;
			int d1,d2,d3;
			cin>>a1>>a2>>a3;
			cin>>b1>>b2>>b3;
			cin>>c1>>c2>>c3;
			cin>>d1>>d2>>d3;
			int k[60]={0};
			 k[1]=a1+b1+c2+d2; 
			 k[2]=a1+b1+c2+d3;
			 k[3]=a1+b1+c3+d2;
			 k[4]=a1+b1+c3+d3;
			 k[5]=a1+b2+c1+d2;
			 k[6]=a1+b2+c1+d3;
			 k[7]=a1+b2+c2+d1;
			 k[8]=a1+b2+c2+d3;
			 k[9]=a1+b2+c3+d1;
			 k[10]=a1+b2+c3+d2;
			 k[11]=a1+b2+c3+d3;
			 k[12]=a1+b3+c1+d2;
			 k[13]=a1+b3+c1+d3;
			 k[14]=a1+b3+c2+d1;
			 k[15]=a1+b3+c2+d2;
			 k[16]=a1+b3+c2+d3;
			 k[17]=a1+b3+c3+d1;
			 k[18]=a1+b3+c3+d2;
			 k[19]=a1+b3+c3+d2;
			 k[20]=a2+b1+c1+d2;
			 k[21]=a2+b1+c1+d3;
			 k[22]=a2+b1+c2+d1;
			 k[23]=a2+b1+c2+d3;
			 k[24]=a2+b1+c3+d1;
			 k[25]=a2+b1+c3+d3;
			 k[26]=a2+b1+c3+d2;
			 k[27]=a2+b2+c1+d1;
			 k[28]=a2+b2+c1+d3;
			 k[29]=a2+b2+c3+d1;
			 k[30]=a2+b3+c1+d1;
			 k[31]=a2+b3+c1+d3;
			 k[32]=a2+b3+c2+d1;
			 k[33]=a2+b3+c3+d1;
			 k[34]=a2+b3+c3+d2;
			 k[35]=a3+b1+c1+d2;
			 k[36]=a3+b1+c1+d3;
			 k[37]=a3+b1+c2+d1;
			 k[38]=a3+b1+c2+d2;
			 k[39]=a3+b1+c2+d3;
			 k[40]=a3+b1+c3+d1;
			 k[41]=a3+b1+c3+d2;
			 k[42]=a3+b2+c1+d1;
			 k[43]=a3+b2+c1+d2;
			 k[44]=a3+b2+c1+d3;
			 k[45]=a3+b2+c2+d1;
			 k[46]=a3+b2+c2+d3;
			 k[47]=a3+b2+c3+d1;
			 k[48]=a3+b2+c3+d2;
			 k[49]=a3+b3+c1+d2;
			 k[50]=a3+b3+c2+d1;
			 k[51]=a3+b3+c2+d2;
			 k[52]=a3+b3+c1+d1;
			 int ans=0;
			 for(int i=1;i<=52;i++){
			 	ans=max(ans,k[i]); 
			 }
			 cout<<ans<<"\n";
			 break;
		}*/
		for(int i=1;i<=n;i++){
			cin>>stu[i].a>>stu[i].b>>stu[i].c;
			stu[i].id=i;
			if(stu[i].a>stu[i].b){
				if(stu[i].b>stu[i].c){
					stu[i].Max=stu[i].a;
					stu[i].Maxclub=1;
				}
				else{
					if(stu[i].c>stu[i].a){
						stu[i].Max=stu[i].c;
						stu[i].Maxclub=3;
					}
					else{
						stu[i].Max=stu[i].a;
						stu[i].Maxclub=1;
					}
				}
			}
			else{
				if(stu[i].a>stu[i].c){
					stu[i].Max=stu[i].b;
					stu[i].Maxclub=2;
				}
				else{
					if(stu[i].c>stu[i].b){
						stu[i].Max=stu[i].c;
						stu[i].Maxclub=3;
					}
					else{
						stu[i].Max=stu[i].b;
						stu[i].Maxclub=2;
					}
				}
			}
			if(stu[i].Max==stu[i].a){
				if(stu[i].b>stu[i].c){
					stu[i].Maxc=stu[i].b;
					stu[i].Maxcclub=2;
					stu[i].Maxcc=stu[i].c;
					stu[i].Maxccclub=3;
				}
				else{
					stu[i].Maxc=stu[i].c;
					stu[i].Maxcclub=3;
					stu[i].Maxcc=stu[i].b;
					stu[i].Maxccclub=2;
				}
			}
			else if(stu[i].Max==stu[i].b){
				if(stu[i].a>stu[i].c){
					stu[i].Maxc=stu[i].a;
					stu[i].Maxcclub=1;
					stu[i].Maxcc=stu[i].c;
					stu[i].Maxccclub=3;
				}
				else{
					stu[i].Maxc=stu[i].c;
					stu[i].Maxcclub=3;
					stu[i].Maxcc=stu[i].a;
					stu[i].Maxccclub=1;
				}
			}
			else{
				if(stu[i].a>stu[i].b){
					stu[i].Maxc=stu[i].a;
					stu[i].Maxcclub=1;
					stu[i].Maxcc=stu[i].b;
					stu[i].Maxccclub=2;
				}
				else{
					stu[i].Maxc=stu[i].b;
					stu[i].Maxcclub=2;
					stu[i].Maxcc=stu[i].a;
					stu[i].Maxccclub=1;
				}
			}
		}
		int tot1=0,tot2=0,tot3=0;
		for(int i=1;i<=n;i++){
			if(stu[i].Maxclub==1){
				c1[++tot1]=stu[i];
				c1[tot1].all=1;
			}
			if(stu[i].Maxclub==2){
				c2[++tot2]=stu[i];
				c2[tot2].all=2;
			}
			if(stu[i].Maxclub==3){
				c3[++tot3]=stu[i];
				c3[tot3].all=3;
			}
		}
		if(tot1>n/2){
			int k=n/2-tot1;
			sort(c1+1,c1+tot1+1,cmp);
			for(int i=tot1;i>=2*tot1-n/2+1;i++){
				if(c1[i].Maxcclub==2){
					c2[++tot2]=c1[i];
					c2[tot2].all=2;
				}
				else if(c1[i].Maxcclub==3){
					c3[++tot3]=c1[i];
					c3[tot3].all=3;
				}
			}
			tot1=n/2;
		}
		else if(tot2>n/2){
			int k=n/2-tot2;
			sort(c2+1,c2+tot2+1,cmp);
			for(int i=tot2;i>=2*tot2-n/2+1;i++){
				if(c2[i].Maxcclub==1){
					c1[++tot1]=c2[i];
					c1[tot1].all=1;
				}
				else if(c2[i].Maxcclub==3){
					c3[++tot3]=c2[i];
					c3[tot3].all=3;
				}
			}
			tot2=n/2;
		}
		else if(tot3>n/2){
			int k=n/2-tot3;
			sort(c3+1,c3+tot3+1,cmp);
			for(int i=tot3;i>=2*tot3-n/2+1;i++){
				if(c3[i].Maxcclub==1){
					c1[++tot1]=c3[i];
					c1[tot1].all=1;
				}
				else if(c3[i].Maxcclub==2){
					c2[++tot2]=c3[i];
					c2[tot2].all=2;
				}
			}
			tot3=n/2;
		}
		int ans=0;
		for(int i=1;i<=tot1;i++){
			ans+=c1[i].a;
		}
		for(int i=1;i<=tot2;i++){
			ans+=c2[i].b;
		}
		for(int i=1;i<=tot3;i++){
			ans+=c3[i].c;
		}
		cout<<ans<<"\n";
	}
	return 0;
}
