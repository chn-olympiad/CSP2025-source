#include <bits/stdc++.h>
using namespace std;
struct person{
	int a;
	int b;
	int c;
	int ar;
	int br;
	int cr;
}p[100005];
bool cmpa(person p,person q)
{
	return p.ar > q.ar;
}
bool cmpb(person p,person q)
{
	return p.br > q.br;
}
bool cmpc(person p,person q)
{
	return p.cr > q.cr;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int cnta = 0,cntb = 0,cntc = 0;
		long long sum = 0;
		for(int i = 0;i < n;i++)
		{
			cin >> p[i].a >> p[i].b >> p[i].c;
			p[i].ar = p[i].br = p[i].cr = INT_MIN;
			if(max({p[i].a,p[i].b,p[i].c}) == p[i].a)
			{
				cnta++;
				sum+=p[i].a;
				p[i].ar = max(p[i].b-p[i].a,p[i].c-p[i].a);
			}
			else if(max({p[i].a,p[i].b,p[i].c}) == p[i].b)
			{
				cntb++;
				sum += p[i].b;
				p[i].br = max(p[i].a-p[i].b,p[i].c-p[i].b);
			}
			else{
				cntc++;
				sum+=p[i].c;
				p[i].cr = max(p[i].a-p[i].c,p[i].b-p[i].c);
			}
		}
		int i = 0;
		if(cnta > n/2)
		{
			sort(p,p+n,cmpa);
			while(cnta > n/2)
			{
				cnta--;
				sum += p[i].ar;
				i++;
			}
		}
		if(cntb > n/2)
		{
			sort(p,p+n,cmpb);
			while(cntb > n/2)
			{
				cntb--;
				sum += p[i].br;
				i++;
			}
		}
		if(cntc > n/2)
		{
			sort(p,p+n,cmpc);
			while(cntc > n/2)
			{
				cntc--;
				sum += p[i].cr;
				i++;
			}
		}
		cout << sum << endl;
	}
}
