#include<bits/stdc++.h>
using namespace std;
int t; 
struct club{
	int a,b,c;
}s[100005];
bool f1(club x,club y){
	return x.a>y.a;
}
bool f2(club x,club y){
	return x.b>y.b;
}

bool f3(club x,club y){
	return x.c>y.c;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		int sum=0;
		priority_queue<int> q1,q2,q3;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&s[i].a,&s[i].b,&s[i].c);
			q1.push(s[i].a);
			q2.push(s[i].b);
			q3.push(s[i].c);
		}
		int s1=q1.size()/2,s2=q2.size()/2,s3=q3.size()/2;
		while(n--){
			 if(q1.top()>=q2.top()&&q1.top()>=q3.top() &&s1>0){
			 	s1--;
			 	sum+=q1.top();
			 	q1.pop();
			 	continue;
			 }
			 if(q2.top()>=q1.top()&&q2.top()>=q3.top() &&s2>0){
			 	s2--;
			 	sum+=q2.top();
			 	q2.pop();
			 	continue;
			 }
			 if(q3.top()>=q2.top()&&q3.top()>=q1.top() &&s3>0){
			 	s3--;
			 	sum+=q3.top();
			 	q3.pop();
			 	continue;
			 }
		}
		printf("%d\n",sum);
	}
	return 0;
}