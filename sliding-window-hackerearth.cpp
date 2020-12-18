// Question link : https://www.hackerearth.com/practice/algorithms/string-algorithm/string-searching/practice-problems/algorithm/search-me/
// Question based on sliding window algorithm
// Complexity is (N*M)

#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;

bool match(int l,int r,string s,string p)
{
  int j=0;
  for(int i=l;i<=r;i++)
  {
    if(s[i]!=p[j])
    {
      return false;
    }
    j++;
  }
  if(l==0&&r==s.length()-1)
  return true;
  if(l==0&&(r+1<s.length())&&s[r+1]==' ')
  return true;
  if(l>0&&s[l-1]==' '&&r==s.length()-1)
  return true;
  if(l>0&&s[l-1]==' '&&(r+1<s.length())&&s[r+1]==' ')
  return true;
  return false;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string s;
    getline(cin, s);
    // cout<<s;
    int len1=s.length();
    string p="to the";
    int len2=p.length(),k=0;
    for(int l=0,r=len2-1;r<len1;l++,r++)
    {
        if(match(l,r,s,p))
        {
            k=-1;
            cout<<"YES"<<endl;
            break;
        }
    }
    if(k!=-1)
    {
        cout<<"NO"<<endl;
    }
  return 0;
}
