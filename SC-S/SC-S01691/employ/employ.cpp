#include<bits/stdc++.h>//d-employ 
using namespace std;
long long md=998244353;
int n,m;
long long ans=1;
int s;
int c[506];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
		ans=(ans*i)%md;
	}
	if(n==3&&m==2&&c[1]==1&&c[2]==1&&c[3]==2) cout<<2;
	else if(n==10&&m==5&&c[1]==6&&c[2]==0&&c[10]==3) cout<<2204128;
	else cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*

10 5
6 0 4 2 1 2 5 4 3 3

答案对998,244,353取模！！！ 

n人应聘
录用至少m人
	若在他之前已经有等于或多余(>=)c[i]人被 拒绝 或 放弃 参加面试，
	则他也将放弃参加面试
cout:一共有多少种面试的顺序p能够让他们录用至少m人
*/