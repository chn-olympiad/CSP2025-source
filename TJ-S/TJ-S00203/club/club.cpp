#include<bits/stdc++.h>
using namespace std;

int t=0,n;
int v[100007][5];
int m0[100007];
int m1[100007];
int m2[100007];

int m0f[100007];
int m1f[100007];
int m2f[100007];

int fx[100007];

bool nflag[100007][5]; //pd if paoqi 2 ci

int m0s=0,m1s=0,m2s=0;

void sort0()
{
	for(int i=0;i<m0s;i++)
	{
		for(int j=i+1;j<m0s;j++)
		{
			if(m0[i]>m0[j])
			{
				swap(m0[i],m0[j]);
				swap(m0f[i],m0f[j]);
			}
		}
	}
	return;
}

void sort1()
{
	for(int i=0;i<m1s;i++)
	{
		for(int j=i+1;j<m1s;j++)
		{
			if(m1[i]>m1[j])
			{
				swap(m1[i],m1[j]);
				swap(m1f[i],m1f[j]);
			}
		}
	}
	return;
}

void sort2()
{
	for(int i=0;i<m2s;i++)
	{
		for(int j=i+1;j<m2s;j++)
		{
			if(m2[i]>m2[j])
			{
				swap(m2[i],m2[j]);
				swap(m2f[i],m2f[j]);
			}
		}
	}
	return;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int e=0;e<t;e++)
	{
	cin>>n;
	int x=0,flagx=0,sum=0,pdA=0,pdB=0;
	sum=0;
	int t=0,n;
int v[100007][5];
int m0[100007];
int m1[100007];
int m2[100007];

int m0f[100007];
int m1f[100007];
int m2f[100007];

int fx[100007];

bool nflag[100007][5]; //pd if paoqi 2 ci
	for(int i=0;i<n;i++)
	{
		x=0;
		for(int j=0;j<3;j++)
		{
			cin>>v[i][j];
			if(v[i][j]==0 && (j==1 || j==2)) pdA++;
			if(v[i][j]==0 && j==2) pdB++;
			if(v[i][j]>x)
			{
				x=v[i][j];
				flagx=j;
			}
		}
		if(flagx==0)
		{
			m0[m0s]=x;
			m0f[m0s]=i;
			m0s++;
		}
		else if(flagx==1)
		{
			m1[m1s]=x;
			m1f[m1s]=i;
			m1s++;
		}
		else
		{
			m2[m2s]=x;
			m2f[m2s]=i;
			m2s++;
		}
		sum+=x;
	}
	if(pdA==n*2)
	{
		sort(m0,m0+n);
		sum=0;
		int pe=n/2;
		for(int i=n-1;i>=pe;i--)
		{
			sum+=m0[i];
		}
		cout<<sum<<'\n';
//		cout<<666;
		continue;
	}
	int pdsize=n/2;
	if(pdB==n)
	{
		sort0();
		if(m0s>pdsize)
		{
			for(int i=0;i<m0s-pdsize;i++)
			{
				m1[m1s]=m0[i];
				m1f[m1s]=m0f[i];
				m1s++;
				m0[i]=-1;
			}
		}
		sort1();
		if(m1s>pdsize)
		{
			for(int i=0;i<m0s-pdsize;i++)
			{
				m2[m2s]=m1[i];
				m2f[m2s]=m1f[i];
				m2s++;
				m1[i]=-1;
			}
		}
		sum=0;
		for(int i=0;i<m0s;i++)
		{
			if(m0[i]==-1) continue;
			sum+=m0[i];
		}
		for(int i=0;i<m1s;i++)
		{
			if(m1[i]==-1) continue;
			sum+=m1[i];
		}
		for(int i=0;i<m2s;i++)
		{
			if(m2[i]==-1) continue;
			sum+=m2[i];
		}
		cout<<sum<<'\n';
		continue;
	}
	if(m0s<=pdsize && m1s<=pdsize && m2s<=pdsize)
	{
		cout<<sum<<'\n';
		continue;
	}

//
	sort0();
	sort1();
	sort2();
	
	int fxnum,pdcimin,fxnumf,flag=1,fxmin=10000,fxminf,blmin,blminf;
	int mj0=0,mj1=0,mj2=0;
	while(!(m0s-mj0<=pdsize && m1s-mj1<=pdsize && m2s-mj2<=pdsize))
//	while(1)
	{
		if(!(m0s-mj0<=pdsize))
		{
			for(int i=0;i<m0s;i++)
			{
				fxnum=0;
				if(m0[i]==-1) continue;
				for(int j=0;j<3;j++)
				{
					pdcimin=v[m0f[i]][j];
					if(pdcimin!=m0[i] && pdcimin>fxnum)
					{
						fxnum=pdcimin;
						fxnumf=j;
					}
				}
				if(fxmin>m0[i]-fxnum)
				{
					fxmin=m0[i]-fxnum;
					fxminf=i;
					blmin=fxnum;
					blminf=fxnumf;
				}
			}
			nflag[m0f[fxminf]][0]=1;
			m0[fxminf]=-1;
			mj0++;
			if(m1s<m2s && nflag[m0f[fxminf]][1]==0)
			{
				m1[m1s]=blmin;
				m1f[m1s]=blminf;
				m1s++;
			}
			else if(nflag[m0f[fxminf]][0]==1 && nflag[m0f[fxminf]][1]==1 && nflag[m0f[fxminf]][2]==1)
			{
				break;
			}
			else
			{
				m2[m2s]=blmin;
				m2f[m2s]=blminf;
				m2s++;
			}
//			break;
//			flag=0;
		}
		else if(!(m1s-mj1<=pdsize))
		{
			for(int i=0;i<m1s;i++)
			{
				fxnum=0;
				if(m1[i]==-1) continue;
				for(int j=0;j<3;j++)
				{
					pdcimin=v[m1f[i]][j];
					if(pdcimin!=m1[i] && pdcimin>fxnum)
					{
						fxnum=pdcimin;
						fxnumf=j;
					}
				}
				if(fxmin>m1[i]-fxnum)
				{
					fxmin=m1[i]-fxnum;
					fxminf=i;
					blmin=fxnum;
					blminf=fxnumf;
				}
			}
			nflag[m1f[fxminf]][1]=1;
			m1[fxminf]=-1;
			mj1++;
			if(m0s<m2s && nflag[m1f[fxminf]][0]==0)
			{
				m0[m0s]=blmin;
				m0f[m0s]=blminf;
				m0s++;
			}
			else if(nflag[m1f[fxminf]][0]==1 && nflag[m1f[fxminf]][1]==1 && nflag[m1f[fxminf]][2]==1)
			{
				break;
			}
			else
			{
				m2[m2s]=blmin;
				m2f[m2s]=blminf;
				m2s++;
			}
//			break;
		}
		else
		{
			for(int i=0;i<m2s;i++)
			{
				fxnum=0;
				if(m2[i]==-1) continue;
				for(int j=0;j<3;j++)
				{
					pdcimin=v[m2f[i]][j];
					if(pdcimin!=m2[i] && pdcimin>fxnum)
					{
						fxnum=pdcimin;
						fxnumf=j;
					}
				}
				if(fxmin>m2[i]-fxnum)
				{
					fxmin=m2[i]-fxnum;
					fxminf=i;
					blmin=fxnum;
					blminf=fxnumf;
				}
			}
			nflag[m2f[fxminf]][2]=1;
			m2[fxminf]=-1;
			mj2++;
			if(m0s<m1s && nflag[m2f[fxminf]][0]==0)
			{
				m0[m0s]=blmin;
				m0f[m0s]=blminf;
				m0s++;
			}
			else if(nflag[m2f[fxminf]][0]==1 && nflag[m2f[fxminf]][1]==1 && nflag[m2f[fxminf]][2]==1)
			{
				break;
			}
			else
			{
				m1[m1s]=blmin;
				m1f[m1s]=blminf;
				m1s++;
			}
		}
	}
	sum=0;
	for(int i=0;i<m0s;i++)
	{
		if(m0[i]==-1) continue;
		sum+=m0[i];
	}
	for(int i=0;i<m1s;i++)
	{
		if(m1[i]==-1) continue;
		sum+=m1[i];
	}
	for(int i=0;i<m2s;i++)
	{
		if(m2[i]==-1) continue;
		sum+=m2[i];
	}
	cout<<sum<<'\n';
	}
	return 0;
}
