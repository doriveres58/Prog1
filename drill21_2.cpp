#include <iostream> 
#include <stdexcept> 
#include <map> 
#include <string> 
#include <numeric> 

template<typename K, typename V>
void print(const std::map<K,V>& m)
{
  //for(auto& i:m)
  for(std::pair<K,V> i:m)
  {
     std::cout<<i.first<<'\t'<<i.second<<std::endl;
  }
}

void read_map(std::map<std::string, int>& m)
{
   std::string s;
   int i=0;
   while(m.size()<10)
   {
      std::cin>>s>>i;
      //m[s]=i
      m.insert(std::make_pair(s,i));
   }
} 
int main()
try
{
  std::map<std::string, int> msi;
  msi["a"]=2;
  msi["b"]=3;
  msi["abc"]=4;
  msi["cd"]=5;
  msi["qwert"]=2;
  msi["po"]=32;
  msi["xy"]=4;
  msi["zs"]=91;
  msi["ac"]=79;
  msi["ax"]=81;
  
  print(msi);
  
  msi.erase("a");
  std::cout<<std::endl<<"Egy elem törlése után:"<<std::endl;
  print(msi);
  
  msi.erase(msi.begin(),msi.end());
  std::cout<<std::endl<<"Teljes törlése után:"<<std::endl;
  print(msi);
  
  std::cout<<"Adj meg 10 kulcs érték párt"<<std::endl;
  read_map(msi);
  print(msi);
  
  /*nt total=std::accumulate(msi.begin(), msi.end(),0)
    [](int sum, const std::pair<std::string, int>& p)
    {return sum +=p.second;}
  );*/
  
  
  int total2=0;
  for(std::pair<std::string, int>a:msi)
  {
     total2+=a.second;
  }
  std::cout<<"sum of ints: " <<total2<<" "<<std::endl;
  
  std::map<int, std::string>mis;
  for(std::pair<std::string, int>a:msi)
  {
     mis[a.second]=a.first;
  }
  std::cout<<"mis map" <<std::endl;
  print(mis);
}
catch(std::exception& e)
{
   std::cerr<<"Exception: "<<e.what()<<'\n';
   return 1;
}
catch(...)
{
   std::cerr<<"unknown exception\n";
   return 2;
}

