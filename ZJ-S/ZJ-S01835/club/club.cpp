/*code by cbh_chen*//*Éû ≈‘⁄Œ“*/
/*CSP-S 2025 , 114 lines , lenth 2085*/
#include<bits/stdc++.h>
using namespace std;
struct hob
{
	long long value;
	long long club;
};
struct peo
{
	hob fir;
	hob sec;
	hob thi;
};
long long t;
long long n,ans;
long long cnt[5];	//	cnt[1]=>cnt_a	cnt[2]=>cnt_b	cnt[3]=>cnt_c
long long max_peo;
peo stu[100005];
bool cmp_hob(hob x,hob y)
{
	return x.value>y.value;
}
bool cmp_peo(peo x,peo y)
{
	if(x.fir.value-x.sec.value>y.fir.value-y.sec.value)	return true;
	if(x.fir.value-x.sec.value<y.fir.value-y.sec.value)	return false;
	if(x.sec.value-x.thi.value>y.sec.value-y.thi.value)	return true;
	return false;
}
void cho(long long i)
{
	long long f_cho=stu[i].fir.club;
	long long s_cho=stu[i].sec.club;
	long long t_cho=stu[i].thi.club;
	long long f_val=stu[i].fir.value;
	long long s_val=stu[i].sec.value;
	long long t_val=stu[i].thi.value;
	if(cnt[f_cho]<max_peo)
	{
		cnt[f_cho]++;
		ans=ans+f_val;
//		cout<<endl<<f_cho<<" "<<f_val<<endl;
	}
	else
	{
		if(cnt[s_cho]<max_peo)
		{
			cnt[s_cho]++;
			ans=ans+s_val;
//			cout<<endl<<s_cho<<" "<<s_val<<endl;
		}
		else
		{
			cnt[t_cho]++;
			ans=ans+t_val;
//			cout<<endl<<t_cho<<" "<<t_val<<endl;
		}
	}
	return ;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		ans=0;
		max_peo=0;
		memset(cnt,0,sizeof cnt);
		memset(stu,0,sizeof stu);
		cin>>n;
		max_peo=n/2;
		for(long long i=1;i<=n;i++)
		{
			hob read[5];
			cin>>read[1].value>>read[2].value>>read[3].value;
			read[1].club=1,read[2].club=2,read[3].club=3;
			sort(read+1,read+3+1,cmp_hob);
			stu[i]={read[1],read[2],read[3]};
		}
//		cout<<endl;
		
		sort(stu+1,stu+n+1,cmp_peo);
//		for(long long i=1;i<=n;i++)
//		{
//			cout<<stu[i].fir.value<<"\t"<<stu[i].sec.value<<"\t"<<stu[i].thi.value<<endl;
//		}
		for(long long i=1;i<=n;i++)
		{
			cho(i);
		}
		cout<<ans<<endl;
	}
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
