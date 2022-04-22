#include <iostream> 
#include <stdexcept> 
#include <string> 
#include <numeric>
#include <vector>
#include <fstream>
#include <algorithm>
#include <list>

using namespace std;

struct Item
{
   string name;
   int iid;
   double value;
   
};
void print(const vector<Item>& v)
{
   for(auto& i:v)
   {
      cout<<i.name<<' '<<i.iid<<' '<<i.value<<endl;
   }
}

void print_list(const list<Item>& l)
{
   for(auto& i:l)
   {
      cout<<i.name<<' '<<i.iid<<' '<<i.value<<endl;
   }
}

struct sort_name
{
   bool operator()(const Item& a, const Item& b) const
   {
      return a.name<b.name;
   }
};

struct sort_id
{
   bool operator()(const Item& a, const Item& b) const
   {
      return a.iid<b.iid;
   }
};

struct sort_value
{
   bool operator()(const Item& a, const Item& b) const
   {
      return a.value>b.value;
   }
};


int main()
{
   try
   {
      const std::string iname {"fajl.txt"};
      std::ifstream ifs {iname};
      if(!ifs) throw std::runtime_error("Could not read file:"+iname);
   
      vector<Item> vi(10);
      for(auto& i:vi)
      {
         ifs>>i.name>>i.iid>>i.value;
      }
      ifs.close();
      print(vi);
      
      cout<<endl;
      cout<<"Sort by name: "<<endl;
      sort(vi.begin(), vi.end(), sort_name());
      print(vi);
      
      cout<<endl;
      cout<<"Sort by id: "<<endl;
      sort(vi.begin(), vi.end(), sort_id());
      print(vi);
      
      cout<<endl;
      cout<<"Sort by value: "<<endl;
      sort(vi.begin(), vi.end(), sort_value());
      print(vi);
      
      
      
      
      list<Item>li(vi.size());
      copy(vi.begin(), vi.end(), li.begin());
      
      cout<<endl;
      cout<<"Sort by name(list): "<<endl;
      li.sort([](const Item& a, const Item&b) {return a.name<b.name;});
      print_list(li);
	      
      cout<<endl;
      cout<<"Sort by id(list): "<<endl;
      li.sort([](const Item& a, const Item&b) {return a.iid<b.iid;});
      print_list(li);
	      
      cout<<endl;
      cout<<"Sort by value(list): "<<endl;
      li.sort([](const Item& a, const Item&b) {return a.value<b.value;});
      print_list(li);
      
      
      
      
      cout<<endl;
      cout<<"Insert: "<<endl;
      vi.push_back(Item{"horse shoe",99,12.34});
      vi.push_back(Item{"Canon S400",9988,499.95});
      print(vi);
      
      cout<<endl;
      cout<<"After erase 2 name: "<<endl;
      vi.erase(find_if(vi.begin(), vi.end(), [] (Item i) {return i.name=="audi";}));
      vi.erase(find_if(vi.begin(), vi.end(), [] (Item i) {return i.name=="kia";}));
      print(vi);
      
      cout<<endl;
      cout<<"After erase 2 id: "<<endl;
      vi.erase(find_if(vi.begin(), vi.end(), [] (Item i) {return i.iid==8;}));
      vi.erase(find_if(vi.begin(), vi.end(), [] (Item i) {return i.iid==5;}));
      print(vi);
      
      
      
      
      cout<<endl;
      cout<<"After erase 2 name(list): "<<endl;
      li.erase(find_if(li.begin(), li.end(), [] (Item i) {return i.name=="audi";}));
      li.erase(find_if(li.begin(), li.end(), [] (Item i) {return i.name=="kia";}));
      print_list(li);
      
      cout<<endl;
      cout<<"After erase 2 id(list): "<<endl;
      li.erase(find_if(li.begin(), li.end(), [] (Item i) {return i.iid==8;}));
      li.erase(find_if(li.begin(), li.end(), [] (Item i) {return i.iid==5;}));
      print_list(li);
      
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
}
