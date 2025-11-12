#include<bits/stdc++.h>
using namespace std;
long long read(){
	long long x=0,y=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') y=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return x*y;
}
struct yll{
	long long a,id;
}a[100001][4];
bool cmp1(yll x,yll y){
	return x.a>y.a;
}
long long n,sum,t[4];
long long answer;
void work(){
	n=read();
	answer=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++){
			a[i][j].a=read();
			a[i][j].id=j;
		}
		sort(a[i]+1,a[i]+3+1,cmp1);
		t[a[i][1].id]++;
		answer+=a[i][1].a;
	}
	if(t[1]>n/2) sum=1;
	else if(t[2]>n/2) sum=2;
	else if(t[3]>n/2) sum=3;
	else{
		cout<<answer;
		t[1]=t[2]=t[3]=0;
		puts("");
		return ;
	}
	vector<long long> q;
	for(int i=1;i<=n;i++){
		if(a[i][1].id==sum){
			q.push_back(a[i][1].a-a[i][2].a);
		}
	}
	sort(q.begin(),q.end());
	for(int i=0;t[sum]>n/2;i++){
		t[sum]--;
		answer-=q[i];
	}
	cout<<answer;
	puts("");
	t[1]=t[2]=t[3]=0;
	return ;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int Tt;
	cin>>Tt;
	while(Tt--) work();
	return 0;
}
