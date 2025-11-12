#include<bits/stdc++.h>
using namespace std;
int a[100005][5],n,cnt=0,s1,s2,s3,t;
int vec1[100005],vec2[100005],vec3[100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		s1=s2=s3=0;
		cnt=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
			if(a[i][1]>a[i][2] and a[i][1]>a[i][3]){
				s1++;
				cnt+=a[i][1];
				vec1[s1]=i;
			}
			else if(a[i][2]>a[i][3] and a[i][2]>a[i][1]){
				s2++;
				cnt+=a[i][2];
				vec2[s2]=i;
			}
			else{
				s3++;
				cnt+=a[i][3];
				vec3[s3]=i;
			}
		}
		if(s1>n/2){
			int s11=s1;
			while(s1>n/2){
				int minc=40005,mini=0;
				for(int i=1;i<=s11;i++){
					if(minc>=(a[vec1[i]][1]-max(a[vec1[i]][3],a[vec1[i]][2])) and a[vec1[i]][1]!=-1){
						minc=(a[vec1[i]][1]-max(a[vec1[i]][3],a[vec1[i]][2]));
						mini=i;
					}
				}
				a[vec1[mini]][1]=-1;
				cnt-=minc;
				s1--;
			}
		}
		else if(s2>n/2){
			int s22=s2;
			while(s2>n/2){
				int minc=40005,mini=0;
				for(int i=1;i<=s22;i++){
					if(minc>=(a[vec2[i]][2]-max(a[vec2[i]][3],a[vec2[i]][1])) and a[vec2[i]][2]!=-1){
						minc=(a[vec2[i]][2]-max(a[vec2[i]][3],a[vec2[i]][1]));
						mini=i;
					}
				}
				a[vec2[mini]][2]=-1;
				cnt-=minc;
				s2--;
			}
		}
		else if(s3>n/2){
			int s33=s3;
			while(s3>n/2){
				int minc=40005,mini=0;
				for(int i=1;i<=s33;i++){
					if(minc>(a[vec3[i]][3]-max(a[vec3[i]][1],a[vec3[i]][2])) and a[vec3[i]][3]!=-1){
						minc=(a[vec3[i]][3]-max(a[vec3[i]][1],a[vec3[i]][2]));
						mini=i;
					}
				}
				a[vec3[mini]][3]=-1;
				cnt-=minc;
				s3--;
			}
		}
		printf("%d\n",cnt);
	}
	return 0;
}
