#include<bits/stdc++.h>
#include<cstdio> 
using namespace std;
int n,k;
int a[200010];
int s[200010][21];
int p[200010][21];
int k2[21];
int shortest[200010];
struct node{
	int x,y;
}q[200010];
void intto2(int id,int res){
	int cur=1;
	while(res){
		s[id][cur]=res%2;
		res/=2;
		cur++;
	}
}
bool check(int l,int r){
	for(int i=1;i<=20;i++){
		if((p[r][i]-p[l-1][i])%2!=k2[i])return 0;
	}
	return 1;
}
bool cmp(node x,node y){
	if(x.y!=y.y)return x.y<y.y;
	else return x.x<y.x;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout); 
	cin >> n >> k;
	int cur=1;
	while(k){
		k2[cur]=k%2;
		k/=2;
		cur++;
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		intto2(i,a[i]);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=20;j++){
			p[i][j]=p[i-1][j]+s[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(check(i,j)){
				shortest[i]=j;
				break;
			}
		}
	}
	int cu=0;
	for(int i=1;i<=n;i++){
		if(shortest[i]){
			cu++;
			q[cu].x=i;
			q[cu].y=shortest[i];
		}
	}
	sort(q+1,q+cu+1,cmp);
	int line=0;int cnt=0;
	for(int i=1;i<=cu;i++){
		if(q[i].x>line){
			cnt++;
			line=q[i].y;
		}
	}
	cout << cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
