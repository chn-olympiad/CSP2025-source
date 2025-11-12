#include<bits/stdc++.h>
using namespace std;
long long n,T,num,a[5][100010],b[5];
struct node{
	long long  x,y,z,xx=1,yy=2,zz=3;
	long long  c12,c23;
}s[100010];		
long long cnt=0;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		memset(a,0,sizeof(a));
		cnt=0;
		memset(b,0,sizeof(b));
		cin>>n;
		num=n/2;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&s[i].x,&s[i].y,&s[i].z);
			s[i].xx=1;
			s[i].yy=2;
			s[i].zz=3;
			if(s[i].x<s[i].y)swap(s[i].x,s[i].y),swap(s[i].xx,s[i].yy);
			if(s[i].y<s[i].z)swap(s[i].y,s[i].z),swap(s[i].yy,s[i].zz);
			if(s[i].x<s[i].y)swap(s[i].x,s[i].y),swap(s[i].zz,s[i].xx);
			s[i].c12=s[i].x-s[i].y;
			s[i].c23=s[i].y-s[i].z;
			if(b[s[i].xx]>=num){
				if(i!=1&&s[a[s[i].xx][num]].c12<s[i].c12){
					cnt+=s[a[s[i].xx][num]].y-s[a[s[i].xx][num]].x;
					a[s[i].xx][num]=i;
				}else{
					if(i!=1&&s[a[s[i].xx][num]].c12==s[i].c12){
						if(s[a[s[i].xx][num]].y>s[i].y){
							cnt+=s[a[s[i].xx][num]].y-s[a[s[i].xx][num]].x;			
							a[s[i].xx][num]=i;
						}else{
							cnt+=s[i].y-s[i].x;
						}
					}else{
						cnt+=s[i].y-s[i].x;
					}
				}
				b[s[i].xx]=num;
				
			}else{
				b[s[i].xx]++;
			}
			a[s[i].xx][b[s[i].xx]]=i;
			if(i!=1&&s[a[s[i].xx][b[s[i].xx]-1]].c12<s[i].c12){
				swap(a[s[i].xx][b[s[i].xx]-1],a[s[i].xx][b[s[i].xx]]);
			}else{
				if(i!=1&&s[a[s[i].xx][b[s[i].xx]-1]].c12==s[i].c12){
					if(s[a[s[i].xx][b[s[i].xx]-1]].y>s[i].y){
						swap(a[s[i].xx][b[s[i].xx]-1],a[s[i].xx][b[s[i].xx]]);
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			cnt+=s[i].x;
		}
		cout<<cnt<<endl;
	}
	return 0;
} 
