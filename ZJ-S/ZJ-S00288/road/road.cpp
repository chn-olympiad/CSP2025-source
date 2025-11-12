#include<bits/stdc++.h>
using namespace std;
#define int long long
int a,b,c,m[10050],s1,s2,o[20][10010],ss;
struct node{
	int x,y,z;
};
node n[1000010],p[200010];
bool r[20];
bool cmp(node a,node b){
	return a.z<b.z;
}
int f(int x){
	return m[x]=(m[x]==x?x:f(m[x]));
}
void g(int x){
	if(x==c){
		if(!ss){
			return;
		}
		int s3=0,s4=0;
		for(int i=0;i<c;i++){
			s3+=o[i][0]*r[i];
		}
		for(int i=1;i<=a+c;i++){
			m[i]=i;
		}
		for(int i=0;i<a-1+c*a;i++){
			if(p[i].x>a and !r[p[i].x-a-1]){
				continue;
			}
			int y=f(p[i].x),z=f(p[i].y);
			if(y==z){
				continue;
			}
			if(y>z){
				m[y]=z;
			}
			else{
				m[z]=y;
			}
			s4++;
			s3+=p[i].z;
			if(s4==a+ss-1){
				break;
			}
		}
		s1=min(s1,s3);
		return;
	}
	g(x+1);
	ss++;
	r[x]=1;
	g(x+1);
	ss--;
	r[x]=0;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&a,&b,&c);
	for(int i=0;i<b;i++){
		scanf("%lld%lld%lld",&n[i].x,&n[i].y,&n[i].z);
	}
	for(int i=0;i<c;i++){
		for(int j=0;j<=a;j++){
			scanf("%lld",&o[i][j]);
		} 
	}
	for(int i=1;i<=a;i++){
		m[i]=i;
	}
	sort(n+0,n+b,cmp);
	for(int i=0;i<b;i++){
		int x=f(n[i].x),y=f(n[i].y);
		if(x==y){
			continue;
		}
		p[s2]=n[i];
		if(x<y){
			m[y]=x;
		}
		else{
			m[x]=y;
		}
		s2++;
		s1+=n[i].z;
		if(s2==a-1){
			break;
		}
	}
	for(int i=a-1;i<a-1+c*a;i++){
		p[i].x=(i-a+1)/a+a+1;
		p[i].y=(i-a+1)%a+1;
		p[i].z=o[p[i].x-a-1][p[i].y];
	}
	sort(p+0,p+a-1+c*a,cmp);
	g(0);
	printf("%lld",s1);
	return 0;
}
