#include<bits/stdc++.h>
using namespace std;
struct myst{
	long long a,b,c,d;
	const operator <(const myst &k)const{
		return d>k.d;
	}
}temp;
priority_queue<myst>qu1;
priority_queue<myst>qu2;
priority_queue<myst>qu3;
priority_queue<myst>clear;
long long n,T,ans;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		qu1=clear;
		qu2=clear;
		qu3=clear;
		ans=0;
		cin>>n;
		for(long long i=1;i<=n;i++){
			cin>>temp.a>>temp.b>>temp.c;
			if(temp.a>=temp.b&&temp.a>=temp.c)temp.d=temp.a-max(temp.b,temp.c),qu1.push(temp),ans+=temp.a;
			else if(temp.b>=temp.a&&temp.b>=temp.c)temp.d=temp.b-max(temp.a,temp.c),qu2.push(temp),ans+=temp.b;
			else if(temp.c>=temp.a&&temp.c>=temp.b)temp.d=temp.c-max(temp.a,temp.b),qu3.push(temp),ans+=temp.c;
		}
//		cout<<qu1.size()<<" "<<qu2.size()<<" "<<qu3.size()<<endl;
		while(max(qu1.size(),max(qu2.size(),qu3.size()))>n/2){
			while(qu1.size()>n/2){
				temp=qu1.top();
				qu1.pop();
				ans-=temp.a;
				if(temp.b>=temp.c)temp.d=temp.b-temp.c,temp.c,qu2.push(temp),ans+=temp.b;
				else temp.d=temp.c-temp.b,qu3.push(temp),ans+=temp.c;
			}
//			cout<<qu1.size()<<" "<<qu2.size()<<" "<<qu3.size()<<endl;
			if(max(qu1.size(),max(qu2.size(),qu3.size()))<=(n/2))break;
			while(qu2.size()>n/2){
				temp=qu2.top();
				qu2.pop();
				ans-=temp.b;
				if(temp.a>=temp.c)temp.d=temp.a-temp.c,temp.c,qu1.push(temp),ans+=temp.a;
				else temp.d=temp.c-temp.a,qu3.push(temp),ans+=temp.c;
			}
//			cout<<qu1.size()<<" "<<qu2.size()<<" "<<qu3.size()<<endl;
			if(max(qu1.size(),max(qu2.size(),qu3.size()))<=(n/2))break;
			while(qu3.size()>n/2){
				temp=qu3.top();
				qu3.pop();
				ans-=temp.c;
				if(temp.a>=temp.b)temp.d=temp.a-temp.b,temp.b,qu1.push(temp),ans+=temp.a;
				else temp.d=temp.b-temp.a,qu2.push(temp),ans+=temp.b;
			}
//			cout<<qu1.size()<<" "<<qu2.size()<<" "<<qu3.size()<<endl;
			if(max(qu1.size(),max(qu2.size(),qu3.size()))<=(n/2))break;
		}
		cout<<ans<<endl;
	}
	return 0;
}
