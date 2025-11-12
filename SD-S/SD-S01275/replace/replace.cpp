#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <bitset>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <cmath>
#include <string>
#include <iostream>
#include <unordered_map>

using namespace std;
const int maxn=2e5+10;
typedef long long ll;

struct hsdt
{
	ll hs[2];
	ll& operator[](const unsigned& x)
	{
		return hs[x];
	}
};
const hsdt mod={1535592857,6097209949};
const hsdt base={31,29};
bool operator==(const hsdt& A,const hsdt& B)
{
	return A[0]==B[0]&&A[1]==B[1];
}
hsdt operator+(const hsdt& A,const hsdt& B)
{
	return {A[0]+B[0],A[1]+B[1]};
}
hsdt operator*(const hsdt& A,const hsdt& B)
{
	return {A[0]*B[0],A[1]*B[1]};
}
hsdt operator%(const hsdt& A,const hsdt& B)
{
	return {A[0]%B[0],A[1]%B[1]};
}
hsdt operator-(const hsdt& A,const hsdt& B)
{
	return {A[0]-B[0],A[1]-B[1]};
}
hsdt hsans[maxn];
vector<hsdt> S_hs[maxn];
hsdt ksm[maxn];
void hashstr(int len,const char* s)
{
	hsans[0]={0,0};
	for(int i=1;i<=len;++i)
	{
		for(int k=0;k<=1;++k)
		{
			hsans[i][k]=(hsans[i-1][k]*base[k]%mod[k]+s[i]-'a')%mod;
		}
	}
}
int n,q;
void initft()
{
	for(int k=0;k<=1;++k)
	{
		ksm[0][k]=1;
		for(int i=1;i<=n;++i)
		{
			ksm[i][k]=ksm[i-1][k]*base[k]%mod;
		}
	}
}
hsdt cuter(int p,int l,int r)
{
	return (((S_hs[p][r]-S_hs[p][l-1]*ksm[r-l+1]%mod)%mod+mod)%mod);
}
int main()
{
	scanf("%d%d",&n,&q);
	return 0;
}
