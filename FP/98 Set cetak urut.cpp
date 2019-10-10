#include <iostream>
#include <set>
using namespace std;
int main ()
{
 set<int> iniset;//inisialisasi set
 set<int>::iterator ini;//iterator
 int a,b,t;
 cin>>t;
 for(int i=1;i<t+1;i++)//looping untuk insert
iniset.insert(i);
for( ini=iniset.begin();ini!=iniset.end();ini++)//looping untuk print
cout<<*ini<<" ";//print
  return 0;
}
