#include<bits/stdc++.h>
using namespace std;
int n,m,k,sum;//道路数量,城市数量、准备进行城市化改造的乡镇数量
struct Book{
	int ui,vi,wi;//第 i 条道路连接的两座城市与修复该道路的费用
}a[10005];
struct Book2{
	int wn=0,c[10005];
}b[10005];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
    cin>>m>>n>>k;
    for(int i=1;i<=n;i++) 
    {
    	cin>>a[i].ui>>a[i].vi>>a[i].wi;
    	sum+=a[i].wi;
	} 

	cout<<sum;
	return 0;
}
