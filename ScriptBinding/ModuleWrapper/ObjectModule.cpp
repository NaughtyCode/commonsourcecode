#define BOOST_PYTHON_STATIC_LIB
#include <boost/python.hpp>

#include <stdio.h>

using namespace boost::python;


class  TBaseIterator
{
public:
	TBaseIterator(int idx):Index(idx){}
	~TBaseIterator(){}

	void SetIndex(int idx){
		Index=idx;
	}

	int GetIndex(){
		return Index;
	}

private:
	int Index;
};

BOOST_PYTHON_MODULE(C_Object)
{
	class_<TBaseIterator>("TBaseIterator", init<int>())
		.def("SetIndex",&TBaseIterator::SetIndex)
		.def("GetIndex",&TBaseIterator::GetIndex);

}
