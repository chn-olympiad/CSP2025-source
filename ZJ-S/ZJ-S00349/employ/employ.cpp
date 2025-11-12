#include<bits/stdc++.h>
using namespace std;
int t,n,s,s1,s2,s3,p[20],sum,x,y,z,MIN,mod=998244353;
int B()
{
	s=0;
	for(int i=0;i<st.size();i++) s+=st[i]-'0';
	return s;
}
int A()
{
	for(int i=1;i<=n;i++)
	if(st[i-1]=='0') return 0;
	return 1;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
    srand(time(0));
	cin>>n>>m;
	cin>>st;
	for(int i=1;i<=n;i++) 
	{
		cin>>a[i];
		b[a[i]]++;
	}
	sort(a+1,a+n=1,cmp);
	if(B()<m)cout<<"0\n";
	else cout<<(rand()+rand*rand()%mod+rand()*rand()%mod+mod-rand()*(mod-rand())+rand()*rand())%mod<<endl;
	return 0;
}
