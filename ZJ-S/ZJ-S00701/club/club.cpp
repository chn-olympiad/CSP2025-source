#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
const int N=100010;
int t,n;
struct point{
	int maxx,pos,cha;
}people[N];
inline int read(){
	char c=getchar();
	int num=0,op=1;
	while(c<'0'||c>'9'){
		if(c=='-')
			op=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
		num=num*10+c-'0',c=getchar();
	return num*op;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	t=read();
	while(t--){
		n=read();
		for(int i=1;i<=n;i++){
			int a=read(),b=read(),c=read();
			int maxx=max(a,max(b,c)),maxx2;
			if(maxx==a){
				maxx2=max(b,c);
				if(maxx2==b)
					people[i]=(point){maxx,1,maxx-maxx2};
				else
					people[i]=(point){maxx,1,maxx-maxx2};
			}
			else if(maxx==b){
				maxx2=max(a,c);
				if(maxx2==a)
					people[i]=(point){maxx,2,maxx-maxx2};
				else
					people[i]=(point){maxx,2,maxx-maxx2};
			}
			else{
				maxx2=max(a,b);
				if(maxx2==a)
					people[i]=(point){maxx,3,maxx-maxx2};
				else
					people[i]=(point){maxx,3,maxx-maxx2};
			}
		}
		int cnt[4]={0,0,0,0},res=0,pos=0;
		for(int i=1;i<=n;i++){
			cnt[people[i].pos]++,res+=people[i].maxx;
			if(cnt[people[i].pos]*2>n)
				pos=people[i].pos;
		}
		vector<int> more;
		for(int i=1;i<=n;i++)
			if(people[i].pos==pos)
				more.push_back(people[i].cha);
		sort(more.begin(),more.end());
		int del=more.size()-n/2,count=0;
		for(int i=0;i<more.size();i++){
			count++,res-=more[i];
			if(count==del)
				break;
		}
		cout<<res<<endl;
	}
}
//Ren5Jie4Di4Ling5%
