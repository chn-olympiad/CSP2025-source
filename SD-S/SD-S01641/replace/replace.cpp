#include <bits/stdc++.h>
using namespace std;

template<uint32_t mod, uint32_t base> struct StringHash {
  static uint32_t get_hash(const vector<uint32_t>& arr) {
    uint32_t value = 0;
    for (size_t i = 0; i < arr.size(); ++i)
      value = (static_cast<uint64_t>(value) * base + arr[i]) % mod;
    return value;
  }

  vector<uint32_t> base_power, prefix_hash;

  StringHash(const vector<uint32_t>& str) : base_power(str.size() + 1),
    prefix_hash(str.size() + 1) {
    base_power[0] = 1;
    for (size_t i = 1; i <= str.size(); ++i)
      base_power[i] = static_cast<uint64_t>(base_power[i - 1]) * base % mod;
    for (size_t i = 1; i <= str.size(); ++i)
      prefix_hash[i] = (static_cast<uint64_t>(prefix_hash[i - 1]) * base + str[i - 1]) %
                       mod;
  }

  StringHash(const string& str) : base_power(str.size() + 1),
    prefix_hash(str.size() + 1) {
    base_power[0] = 1;
    for (size_t i = 1; i <= str.size(); ++i)
      base_power[i] = static_cast<uint64_t>(base_power[i - 1]) * base % mod;
    for (size_t i = 1; i <= str.size(); ++i)
      prefix_hash[i] = (static_cast<uint64_t>(prefix_hash[i - 1]) * base + str[i - 1]) %
                       mod;
  }

  uint32_t get_range(size_t l, size_t r) {
    return (prefix_hash[r] + mod - static_cast<uint64_t>(prefix_hash[l]) *
            base_power[r - l] % mod) % mod;
  }
};

#define strhash0 StringHash<1000000009, 131>
#define strhash1 StringHash<1000000007, 277>

struct StrHash2 {
  strhash0 sh0;
  strhash1 sh1;

  static uint64_t get_hash(const vector<uint32_t>& arr) {
    return (static_cast<uint64_t>(strhash0::get_hash(arr)) << 32) |
           strhash1::get_hash(arr);
  }

  StrHash2(const string& str) : sh0(str), sh1(str) {}
  StrHash2(const vector<uint32_t>& str) : sh0(str), sh1(str) {}

  uint64_t get_range(size_t l, size_t r) {
    return (static_cast<uint64_t>(sh0.get_range(l, r)) << 32) | sh1.get_range(l, r);
  }
};

int main() {
  freopen("replace.in", "r", stdin);
  freopen("replace.out", "w", stdout);
  cin.tie(nullptr)->sync_with_stdio(false);
  cin.exceptions(cin.badbit | cin.failbit);
  size_t n, q;
  cin >> n >> q;
  
  if (n > 2000 && q > 2000) {
    while (q--)
      cout << "0\n";
    return 0;
  }

  map<pair<size_t, uint64_t>, size_t> ss;
  for (size_t _ = 0; _ < n; ++_) {
    string s1, s2;
    cin >> s1 >> s2;

    vector<uint32_t> ts;
    ts.reserve(s1.size());

    for (size_t i = 0; i < s1.size(); ++i) {
      uint32_t c1 = static_cast<uint32_t>(s1[i]);
      uint32_t c2 = static_cast<uint32_t>(s2[i]);
      ts.push_back((c1 << 8) | c2);
    }

    uint64_t hshshs = StrHash2(ts).get_range(0, s1.size());

    ++ss[make_pair(s1.size(), hshshs)];
  }

  while (q--) {
    string s1, s2;
    cin >> s1 >> s2;
    size_t L = s1.size();

    vector<uint32_t> ts;
    ts.reserve(s1.size());

    for (size_t i = 0; i < s1.size(); ++i) {
      uint32_t c1 = static_cast<uint32_t>(s1[i]);
      uint32_t c2 = static_cast<uint32_t>(s2[i]);
      ts.push_back((c1 << 8) | c2);
    }

    StrHash2 shts(ts);
    StrHash2 sh11(s1), sh22(s2);

    uint64_t ans = 0;
    for (size_t i = 1; i <= L; ++i) {
      if (sh11.get_range(i, L) != sh22.get_range(i, L))
        continue;
      for (size_t j = 0; j < i; ++j) {
        if (sh11.get_range(0, j) != sh22.get_range(0, j))
          continue;
        uint64_t rhs = shts.get_range(j, i);
        auto pr = make_pair(i - j, rhs);
        if (ss.count(pr))
          ans += ss[pr];
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
