#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int x[N][5];
int a[5][N];
int s[10];
int n;
int cc2(int j1,int j2,int sum){
	int czz[N];
	for(int i=1;i<=s[j1];i++){
		int m=a[j1][i];
		czz[i]=x[m][j1]-x[m][j2];
	}
	sort(czz+1,czz+1+s[j1]);
	for(int i=1;i<=s[j1]-n/2;i++){
		sum-=czz[i];
	}
	return sum;
}
struct ccz{
	int s;
	int ss;
	int s1;
}cz[N];
bool cmp(ccz aa,ccz bb){
	return aa.s<bb.s;
}
int cc(int j,int sum){
	int j1=(j+1)%3,j2=(j+2)%3;
	if(j1==0) j1=3;
	if(j2==0) j2=3;
	int aa=0,pp=0;
	for(int i=1;i<=s[j];i++){
		int m=a[j][i],q2=x[m][j]-x[m][j1],q3=x[m][j]-x[m][j2];
		cz[i].s=min(q2,q3);
		cz[i].ss=m;
		if(q2<q3) cz[i].s1=j1;
		else cz[i].s1=j2;
	}
	sort(cz+1,cz+1+s[j],cmp);
	for(int i=1;i<=s[j]-n/2;i++){
		sum-=cz[i].s;
		if(cz[i].s1==j1) aa++,a[j1][s[j1]+aa]=cz[i].ss;
		else{
			pp++,a[j2][s[j2]+pp]=cz[i].ss;
		}
	}
	s[j1]+=aa;
	s[j2]+=pp;
	if(s[j1]>n/2){
		sum=cc2(j1,j2,sum);
	}
	else if(s[j2]>n/2){
		sum=cc2(j2,j1,sum);
	}
	return sum;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		s[1]=s[2]=s[3]=0;
		int js=0;
		int aa=0,bb=0,pp=0;
		for(int i=1;i<=n;i++){
			cin>>x[i][1]>>x[i][2]>>x[i][3];
	        if(x[i][1]>x[i][2]&&x[i][1]>x[i][3]){
	        	aa++;
				a[1][aa]=i;
				js+=x[i][1];
				continue;
			} 
			else if(x[i][2]>x[i][1]&&x[i][2]>x[i][3]){
				bb++;
				a[2][bb]=i;
				js+=x[i][2];
				continue;
			} 
			else{
				pp++;
				a[3][pp]=i;
				js+=x[i][3];
				continue;
			} 
		}
	    s[1]=aa;
		s[2]=bb;
		s[3]=pp;
		if(s[1]>n/2){
			js=cc(1,js);
		}
		else if(s[2]>n/2){
			js=cc(2,js);
		}
		else if(s[3]>n/2){
			js=cc(3,js);
		}
		printf("%d\n",js);
	}
	return 0;
}