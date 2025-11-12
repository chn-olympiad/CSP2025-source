#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int t, n;
int m[4];
bool f[4];
long long ans;
struct satis{
	int num, v;
};
struct student{
	int num;
	satis sa[4];
	int deng;
} stu[N];
queue <student> q;
bool cmp(student &x, student &y){
	int ax=x.sa[1].v, bx=x.sa[2].v, cx=x.sa[3].v;
	int ay=y.sa[1].v, by=y.sa[2].v, cy=y.sa[3].v;
	if (ax==ay){
		if (bx==by)
			return cx>cy;
		return bx>by;
	}
	return ax>ay;
}
bool cmp2(satis &x, satis &y){
	return x.v>y.v;
}

int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin>>t;
	while (t--){
		cin>>n;
		ans=0;
		memset(m, 0, sizeof(m));
		memset(f, 0, sizeof(f));
		for (int i=1; i<=n; i++){
			//printf("%d:  ", i);
			stu[i].num=i;
			int d=0;
			for (int j=1; j<=3; j++){
				cin>>stu[i].sa[j].num>>stu[i].sa[j].v;
				//printf("%d ", stu[i].sa[j].v);
			}
			sort(stu[i].sa+1, stu[i].sa+4, cmp2);
			int va=stu[i].sa[1].v, vb=stu[i].sa[2].v, vc=stu[i].sa[3].v;
			bool dx=va==vb, dy=vb==vc, dz=va==vc;
			if (dx && dy){
				stu[i].deng=3;
				continue;
			}
			else if (dx || dy || dz)
				d=2;
			stu[i].deng=d;
			//printf("\n");
		}
		sort(stu+1, stu+1+n, cmp);
		for (int i=1; i<=n; i++)
			//printf("%d  ", stu[i].num);
		//printf("\n");
		for (int i=1; i<=n; i++){
			if (stu[i].deng==3){
				ans+=stu[i].sa[1].v;
				continue;
			}
			/*
			else if(s[i].deng==2)
				q.push_back(s[i]);
			*/
			int a=stu[i].sa[1].num, b=stu[i].sa[2].num, c=stu[i].sa[3].num;
			/*
			if (s[i].a[b]==0){
				continue;
			}
			*/
			if (!f[a]){
				ans+=stu[i].sa[a].v;
				m[a]++;
				f[a]=m[a]>(n/2);
			}
			else if (!f[b]){
				ans+=stu[i].sa[b].v;
				m[b]++;
				f[b]=m[b]>(n/2);
			}
			else {
				ans+=stu[i].sa[c].v;
				m[c]++;
				f[c]=m[c]>(n/2);
			}
		}
		for (int i=1; i<=3; i++)
			m[i]=(n/2-m[i])*2;
		while (!q.empty()){
			student top=q.front();
			q.pop();
			int va=top.sa[1].v, vb=top.sa[2].v, vc=top.sa[3].v;
			bool dx=va==vb, dy=vb==vc;
			for (int i=1; i<=3; i++){
				if (dx){
					bool flag=false;
					if (m[top.sa[1].num]!=0)
						flag=true, m[top.sa[1].num]--;
					if (m[top.sa[2].num]!=0)
						flag=true, m[top.sa[2].num]--;
					if (flag)
						ans+=va;
				}
				else{
					bool flag=false;
					if (vb==0)
						continue;
					if (m[top.sa[2].num]!=0)
						flag=true, m[top.sa[2].num]--;
					if (m[top.sa[3].num]!=0)
						flag=true, m[top.sa[3].num]--;
					if (flag)
						ans+=vb;
				}
			}
		}
		//printf("ans: ");
		printf("%lld\n", ans);
	}
	return 0;
}