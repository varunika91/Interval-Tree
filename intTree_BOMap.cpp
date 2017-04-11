#include <iostream>
#include <bits/stdc++.h>
#include <map>
#include <errno.h>
#include <stdint.h>

class BOMap{
	
	class node{
		public:
			node(void){
				nStrt =0;
				nSize =0;
			}
			explicit node(uint64_t item, uint64_t size =0){
				nStrt = item;
				nSize = size; 
			}
			
			const int getStart() const { return nStrt; }
			void setStart(int strtVal) { nStrt= strtVal; }
			const int getEnd () const {return (nStrt +nSize);}
			void setSize(int sizeVal) { nSize = sizeVal; }
			
			//For insertion
			bool operator<(const node& newN) const 
			{
				if (nStrt < newN.getStart())       
				{            
					return true;
				} else if (nStrt == newN.getStart())  
				{ 
					if ((nStrt+nSize) < newN.getEnd()) 
					{ 
						return true;
					} 
					else if ((nStrt+nSize) == newN.getEnd())
					{
						return false;
					}
				} 
					return false;
			}
			
		private:
			uint64_t nStrt;
			uint64_t nSize;
	};
	
	std::map<node,uint32_t> intTree;
	typedef std::pair<node,uint32_t> inputPair;
	class Predicate{

		public:
		Predicate(uint64_t x): x(x) {}
		bool operator()( const inputPair& chkNode ) const
		{
			//if(second.getEnd()== second.getStart()){
				if((x<=chkNode.first.getEnd()) && (x >=chkNode.first.getStart()))
					return true;
				else	
					return false;
				
			if (chkNode.first.getStart() < x)
				return true;
			else	
				return false;
			
			if (x < chkNode.first.getStart())
				return true;
			else	
				return false;
			}
		private:
		const uint64_t x;
	};
	//BOMap public
	
	public:
	int map_insert(uint64_t strtAddr, uint64_t size, uint32_t value){
		node n;
		n.setStart(strtAddr);
		n.setSize(size);
		std::pair<node,uint64_t> tmp1(n,value);
		intTree.insert(tmp1);
		
	}
	
	//find func will return the handle
	uint32_t map_find(uint64_t valChk){ 
		std::map<node,uint64_t>::const_iterator it =  std::find_if(intTree.begin(),intTree.end(), Predicate(valChk));

		if (it == intTree.end()){
			std::cout<<"Not Found"<<std::endl;
			std::cout<< it->second<<std::endl;
			return it->second;
		}
		else{ 
			std::cout<<"Found"<<std::endl;
			std::cout<< it->second<<std::endl;	//Handle
			return it->second;
		}
	}
};




int main()
{
	BOMap map1;
	map1.map_insert(0,10,1);
	map1.map_insert(15,10,2);
	map1.map_insert(30,10,3);
	map1.map_insert(45,10,4);
    	
    uint64_t newval = 20;
	uint32_t BOhandle;
	BOhandle = map1.map_find(newval);
	std::cout<<"Result: "<<BOhandle<<std::endl;
	
	
	/*Test 2 
	std::map<node,int, NodeComparer>::iterator it;
	it =intTree.find(newchk);
	if(it!= intTree.end())
		std::cout<<it->second<<std::endl;
	else 
		std::cout<<"No element"<<std::endl;
	
	//Print the tree
	std::cout<<std::endl;
	it = intTree.begin();
    for(; it != intTree.end(); it++)
    {
        std::cout<<it->first.getStart()<<"-"<<it->first.getEnd()<<" = "<<it->second<<std::endl;
    }
	
*/
    return 0;
}

