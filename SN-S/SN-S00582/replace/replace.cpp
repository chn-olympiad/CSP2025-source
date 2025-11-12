#include <bits/stdc++.h>
using namespace std;
int n,q;
struct node{
	node* fail;
	node* to[26];
	vector<int> end;
	node(){
		fail=nullptr;
		for(int i=0;i<26;i++) to[i]=nullptr;
		end.clear();
	}
};
node *ac,*ac1;
int cnt,cnt1;
char s[5000006];
vector<int> pos[200005];
void build(node* root)
{
	queue<node*> q;
	for(int i=0;i<26;i++)
	{
		if(root->to[i]==nullptr) root->to[i]=root;
		else
		{
			root->to[i]->fail=root;
			q.push(root->to[i]);
		}
	}
	while(!q.empty())
	{
		node* tmp=q.front();
		q.pop();
		for(int i=0;i<26;i++)
		{
			if(tmp->to[i]==nullptr) tmp->to[i]=tmp->fail->to[i];
			else
			{
				tmp->to[i]->fail=tmp->fail->to[i];
				q.push(root->to[i]);
			}
		}
	}
}
int main()
{
//	freopen("replace.in","r",stdin);
//	freopen("replace.out","w",stdout);
	ac=new node;
	ac1=new node();
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",s+1);
		int m=strlen(s+1);
		int tmp=0;
		node* root=ac;
		for(int j=1;j<=m;j++)
		{
			if(root->to[s[j]-'a']==nullptr) root->to[s[j]-'a']=new node;
			root=root->to[s[j]-'a'];
		}
		root->end.push_back(i);
		scanf("%s",s+1);
		m=strlen(s+1);
		tmp=0;
		root=ac1;
		for(int j=1;j<=m;j++)
		{
			if(root->to[s[j]-'a']==nullptr) root->to[s[j]-'a']=new node;
			root=root->to[s[j]-'a'];
		}
		root->end.push_back(i);
	}
	build(ac);build(ac1);
	for(int i=1;i<=q;i++)
	{
		scanf("%s",s+1);
		
	}
	return 0;
}
// È¼¾¡ÁË 
