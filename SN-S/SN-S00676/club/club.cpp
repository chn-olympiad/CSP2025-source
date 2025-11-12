#include<bits/stdc++.h>
using namespace std;
struct person{
	int a,b,c;
	int key;
};
vector<person> s(100005);	
vector<person>x,y;
vector<bool> vis;
bool cmp1(person x,person y){
	return x.a>y.a;
}
bool cmp2(person x,person y){ 
	return x.b > y.b;
}
bool cmp3(person x,person y){ 
	return x.c > y.c;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n;
		
		cin>>n;
		long long ans = 0;
		int nowa=0,nowb=0,nowc=0;
		for(int i=1;i<=n;i++){
			int x,y,z;
			cin>>x>>y>>z;
			s[i].a = x;
			s[i].b = y;
			s[i].c = z;
			if(s[i].b>0) nowb=1;
			if(s[i].c>0) nowc=1;
			if(s[i].a>0) nowa=1;
		}	
		if(nowb == 0 && nowc == 0){
			sort(s.begin(),s.end(),cmp1);
			for(int i=0;i<(n/2);i++) ans+=s[i].a;
			cout<<ans<<"\n";
		}
		else if(nowa==0 && nowc==0){
			sort(s.begin(),s.end(),cmp2);
			for(int i=0;i<(n/2);i++) ans+=s[i].b;
			cout<<ans<<"\n";
		}
		else if(nowb ==0 && nowa == 0){
			sort(s.begin(),s.end(),cmp3);
			for(int i=0;i<(n/2);i++) ans+=s[i].c;
			cout<<ans<<"\n";
		}
		else if(nowa==0 && nowb==0 && nowc==0) cout<<0<<"\n";
		else
		{
			for(int i=1;i<=n;i++)
			{
				if(s[i].a>s[i].b && s[i].a>s[i].c)
				{
					ans+=s[i].a;
				}
				if(s[i].b>s[i].a && s[i].b>s[i].c)
				{
					ans+=s[i].b;
				}
				if(s[i].c>s[i].b && s[i].c>s[i].a)
				{
					ans+=s[i].a;
				}
				if(s[i].a== s[i].b &&s[i].b == s[i].c)
				{
					ans+=s[i].a;
				}
			}
			cout<<ans;
		}
	}
	return 0;
} 
