#include<bits/stdc++.h>
using namespace std;
struct node{
	long long a;
	long long b;
	long long c;
};
struct wei{
	long long num;
	long long w;
};
node a[100010];
vector <wei>s;
vector <wei>q;
bool cmp(wei s1,wei s2){
	return s1.num>s2.num;
}
long long cl(int ch){
	long long sum=0;
	for(int i=1;i<=ch;i++){
		s.push_back({a[i].a-a[i].b,i});
	}
	sort(s.begin(),s.end(),cmp);
	for(int i=0;i<ch/2;i++){
		if(a[s[i].w].a>a[s[i].w].c){
			sum+=a[s[i].w].a;
		}
		else{
			sum+=a[s[i].w].c;
		}
	}
	for(int i=ch/2;i<ch;i++){
		if(a[s[i].w].b>a[s[i].w].c){
			sum+=a[s[i].w].b;
		}
		else{
			sum+=a[s[i].w].c;
		}
	}
	s.clear();
	return sum;
}
long long clc(int ch){
	long long sum=0;
	for(int i=1;i<=ch;i++){
		s.push_back({a[i].c-a[i].b,i});
	}
	sort(s.begin(),s.end(),cmp);
	for(int i=0;i<ch/2;i++){
		if(a[s[i].w].c>a[s[i].w].a){
			sum+=a[s[i].w].c;
		}
		else{
			sum+=a[s[i].w].a;
		}
	}
	for(int i=ch/2;i<ch;i++){
		if(a[s[i].w].b>a[s[i].w].a){
			sum+=a[s[i].w].b;
		}
		else{
			sum+=a[s[i].w].a;
		}
	}
	s.clear();
	return sum;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int i=1;i<=t;i++){
		int n;
		cin>>n;
		long long sumc=0;
		for(int i=1;i<=n;i++){
			cin>>a[i].a>>a[i].b>>a[i].c;
			if(a[i].c>a[i].b&&a[i].c>a[i].a){
				sumc++;
			}
		}
		if(sumc<=n/2){
			long long  l=cl(n);
			cout<<l<<endl;
		}
		else{
			long long l=clc(n);
			cout<<l<<endl;
		}
	}
	return 0;
} 
