#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;

struct node1{
	string s1,s2;
	int asc,siz;
}a[200000+5];
bool cmp1(node1 aa,node1 bb){
	return aa.asc<bb.asc;
}
int as[200000+5];
struct node2{
	string s1,s2;
	int siz;
}b[200000+5];
bool cmp2(node2 aa,node2 bb){
	return aa.siz<bb.siz;
}


int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,m;
	string sxf,sxs;
	scanf("%d%d",&n,&m);
	int cnt1=0,cnt2=0;
	for(int i=1;i<=n;i++)
	{
		sxf.clear();
		sxs.clear();
		cin>>sxf>>sxs;
		if(sxf.length()>=3){
			cnt1++;
			a[cnt1].s1=sxf;
			a[cnt1].s2=sxs;
			a[cnt1].siz=sxf.length();
			a[cnt1].asc=(a[cnt1].s1[0]-'a'+1)*10000+(a[cnt1].s1[1]-'a'+1)*100+a[cnt1].s1[2]-'a'+1;
		}
		else{
			cnt2++;
			b[cnt2].s1=sxf;
			b[cnt2].s2=sxs;
			b[cnt2].siz=sxf.length();
		}
	}
	sort(a+1,a+cnt1+1,cmp1);
	for(int i=1;i<=cnt1;i++){
		as[i]=a[i].asc;
	}
	sort(b+1,b+cnt2+1,cmp2);
	for(int i=1;i<=m;i++)
	{
		int ans=0;
		sxf.clear();
		sxs.clear();
		cin>>sxf>>sxs;
		if(sxs.size()>sxf.size()){
			printf("0\n");
			continue;
		}
		int stt=sxf.size()+1,ed=0;
		for(int j=0;j<sxf.size();j++){
			if(sxf[j]!=sxs[j]){
				stt=min(stt,j);
				ed=max(ed,j);
			}
		}
		for(int j=0;j<sxf.size();j++){
			if(sxf.size()-j>=3){
				int asci=(sxf[j]-'a'+1)*10000+(sxf[j+1]-'a'+1)*100+sxf[j+2]-'a'+1; 
				int loct=lower_bound(as+1,as+cnt1+1,asci)-as;
				while(1){
					if(a[loct].asc>asci||loct>n){
						break;
					}
					if(ed-stt>=a[loct].siz){
						loct++;
						continue;
					}
					bool trl=true,trll=false;
					for(int ij=0;ij<a[loct].siz;ij++){
						if(a[loct].s1[ij]!=sxf[ij+j]||a[loct].s2[ij]!=sxs[ij+j]){
							trl=false;
							break;
						}
					}
					if(trl) ans++;
					loct++;
				}
			}
			if(ed-stt>1) continue;
			for(int ij=1;ij<=cnt2;ij++){
				if(b[ij].siz==1){
					if(sxf[j]==b[ij].s1[0]&&sxs[j]==b[ij].s2[0]&&ed-stt==0){
						ans++;
					}
				}
				else{
					if(sxf[j]==b[ij].s1[0]&&sxf[j+1]==b[ij].s1[1]&&sxs[j]==b[ij].s2[0]&&sxs[j+1]==b[ij].s2[1]){
						ans++;
					}
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
