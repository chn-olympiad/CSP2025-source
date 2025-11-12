#include<bits/stdc++.h>
using namespace std;
int a[5005],n=5,ans;
queue<string> s;
void ejz(){
	s.push("0");
	s.push("1");
	string s1="";
	for(int i=1;i<=pow(2,n);i++){
		s.push(s.front()+'0');
		s.push(s.front()+'1');
		s.pop();
	}
	for(int i=s.size();i>5;i--){
		s1=s.front();
		s.push(s1);
		s.pop();
	}
	for(int i=1;i<=8;i++) s.pop();
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	ejz();
	for(;!s.empty();){
		string s1=s.front();
		int sum=0,ed=0;
		int fl=0;
		for(int i=0;i<n;i++){
			fl+=s1[i]-'0';
			ed=(s1[i]-'0')?i:ed;
		}
		if(fl-2){
			for(int i=0;i<n;i++){
				sum+=(s1[i]-'0')*a[i];
			}
			ans=(ans+int(s1[ed]*2<sum))%998244353;	
		}
		s.pop();
	}
	printf("%d",ans);
	return 0; 
}
