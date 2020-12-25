// Question from SPOJ : Pattern Find
// Question link : https://www.spoj.com/problems/NAJPF/
// Solved using Rabin - Karp algorithm

#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;

ll dp[1000001];    //to store hash values from(0,i)
ll p_power[1000001];

void init(string s)
{
  ll p=31;
  p_power[0]=1;
  dp[0]=(s[0]-'a'+1);

  for(ll i=1;i<s.length();i++)
  {
    char ch=s[i];
    p_power[i]=(p_power[i-1]*p)%mod;
    dp[i]=(dp[i-1]+(ch-'a'+1)*p_power[i])%mod;
  }
}

ll substringHash(ll L ,ll R)
{
  ll res=dp[R];
  if(L>0)
  {
    res=(res-dp[L-1]+mod)%mod;
  }
  res=(res)%mod;
  return res;
}

ll getHash(string key)
{
	ll value = 0;
	ll p = 31;
	ll p_power1 = 1;

	for(char ch : key)
	{
		value = (value + (ch - 'a' + 1)*p_power1) % mod;
		p_power1 = (p_power1 * p) % mod;
	}

	return value;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int t;
  cin>>t;

  while(t--)
  {
    string s,pattern;
    cin>>s>>pattern;

    ll hash=getHash(pattern);
    init(s);

    vector<ll> arr;
    for(ll L=0,R=pattern.length()-1;R<s.length();L++,R++)
    {
      if(substringHash(L,R)==(hash*p_power[L])%mod)
      {
        arr.push_back(L+1);
      }
    }
    if(arr.size()==0)
    {
      cout<<"Not Found"<<endl;
    }
    else
    {
      cout<<arr.size()<<endl;
      for(int i=0;i<arr.size();i++)
      {
        cout<<arr[i]<<" ";
      }
    }
    cout<<endl;
  }
}
