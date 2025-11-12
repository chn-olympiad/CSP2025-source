#include<bits/stdc++.h>
using namespace std;
using ui=unsigned int;
using uli=unsigned long long int;
ifstream fin("replace.in");
ofstream fout("replace.out");
struct AcamNode{
  ui c;
  array<AcamNode*,27> nxt;
  AcamNode* fail;
  AcamNode(void):c{0},nxt{{}},fail{}{}
};
int main(void){
  ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
  size_t n,q;fin>>n>>q;
  deque<AcamNode> pool;
  unordered_map<string,AcamNode*> ss;
  while (n--){
    string s,t;fin>>s>>t;
    assert(s.size()==t.size());
    vector<size_t> diff;
    for (size_t i=0;i<s.size();++i) if (s[i]!=t[i]) diff.emplace_back(i);
    if (diff.empty()) continue;
    string dss(s.begin()+diff.front(),s.begin()+diff.back()+1),
        dst(t.begin()+diff.front(),t.begin()+diff.back()+1);
    string ds=dss+':'+dst;
    AcamNode* p;
    {
      auto it=ss.find(ds);
      if (it!=ss.end()) p=it->second;
      else pool.emplace_back(),p=ss.emplace(ds,&pool.back()).first->second;
    }
    string ts=string(s.begin(),s.begin()+diff.front())
        +char('z'+1)
        +string(s.begin()+diff.back()+1,s.end());
    for (char i:ts){
      if (!p->nxt[i-'a']) pool.emplace_back(),p->nxt[i-'a']=&pool.back();
      p=p->nxt[i-'a'];
    }
    ++p->c;
  }
  for (auto const& sp:ss){
    auto s=sp.second;
    pool.emplace_back();
    pool.back().nxt.fill(s);
    s->fail=&pool.back();
    queue<AcamNode*> q{{{s}}};
    while (!q.empty()){
      auto p=q.front();q.pop();
      for (ui i=0;i<27;++i)
        if (p->nxt[i]){
          q.emplace(p->nxt[i]);
          p->nxt[i]->fail=p->fail->nxt[i];
        }
        else p->nxt[i]=p->fail->nxt[i];
      p->c+=p->fail->c; 
    }
  }
  while (q--){
    string s,t;fin>>s>>t;
    if (s.size()!=t.size()){
      fout<<"0\n";
      continue;
    }
    vector<size_t> diff;
    for (size_t i=0;i<s.size();++i) if (s[i]!=t[i]) diff.emplace_back(i);
    assert(!diff.empty());
    string dss(s.begin()+diff.front(),s.begin()+diff.back()+1),
        dst(t.begin()+diff.front(),t.begin()+diff.back()+1);
    string ds=dss+':'+dst;
    auto pt=ss.find(ds);
    if (pt==ss.end()){
      fout<<"0\n";
      continue;
    }
    auto p=pt->second;
    string ts=string(s.begin(),s.begin()+diff.front())
        +char('z'+1)
        +string(s.begin()+diff.back()+1,s.end());
    ui ans=0;
    for (char i:ts){
      p=p->nxt[i-'a'];
      ans+=p->c;
    }
    fout<<ans<<'\n';
  }
}

