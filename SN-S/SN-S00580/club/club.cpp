//缑致玮-SN-S00580-延安新区第三中学 
#include<bits/stdc++.h>
using namespace std;
int a1[100010],a2[100010],a3[100010],s[5][100010],s1[400000];//s1[100010],s2[100010],s3[100010];
void big(){
	int w1;
	int w2;
	int w3;
};

int main(){
	
	freopen("power.in","r",stdin);
	freopen("power.out","r",stdout);
	int n;
	cin>>n;
	for(int o=0;o<n;o++){
		int r,e1,e2,e3,t,g,h=0;
		cin>>r;
		g=r-1;
		e1=r-1;
		e2=e1;
		e3=e2;
		for(int i=0;i<r;i++){
			cin>>a1[i]>>a2[i]>>a3[i];
			s[1][i]=a1[i];
			s[2][i]=a2[i];
			s[3][i]=a3[i];
			s[4][i]=i+1;
		}
		sort(a1,a1+r);
		sort(a2,a2+r);
		sort(a3,a3+r);
		if(a1[e1]>=a2[e2]){
			if(a1[e1]<=a3[e3]){
				t=3;
			}else{
				t=1;
			}
		}else{
			if(a2[e2]<=a3[e3]){
				t=3; 
			}else{
				t=2;
			}
		}
		int s2[10][100010];
		int cc=1;
		for(int i=1;i<r;i++){
			if(s[t][i]==a1[e1]&&t==1){
				s1[1][i]=s1[1][g];
				s1[2][i]=s1[2][g];
				s1[3][i]=s1[3][g];
				s1[4][i]=s1[4][g];
				g--;
				h+=e1;
			}else if(s[t][i]==a2[e2]&&t==2){
				s1[1][i]=s1[1][g];
				s1[2][i]=s1[2][g];
				s1[3][i]=s1[3][g];
				s1[4][i]=s1[4][g];
				g--;
				h+=e2;
			}else if(s[t][i]==a3[e3]&&t==3){
				s1[1][i]=s1[1][g];
				s1[2][i]=s1[2][g];
				s1[3][i]=s1[3][g];
				s1[4][i]=s1[4][g];
				g--;
				h+=e3;
			}else{
				cc=cc;
			}
		}
		cout<<e3;
	}
	
	return 0;
}
