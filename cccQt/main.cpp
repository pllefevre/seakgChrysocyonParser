
#define CCC_USE_QT
#include "../ccc/cccString.h"
// #include "../ccc/cccString.h"
// #include "../ccc/cccStream.h"

#include <iostream>
using namespace std;

/*
class cccStream
{
	public:
		cccStream & operator << (const int &g)
		{
			cout << g;
			return *this; 
		};
};
*/


int main()
{
  cccVar var;     

/*  cccStream out;
  for(int i = 0; i < 10; i++ )
	{
		//cccInt *c_i = new cccInt(i);
		//  out << i << cccInt(i) << c_i;
		//out << 0;
		cout << "\n";
	}*/

  


//	cccString str = cccString("123");
	
	//cout << str.Length().getInt() << "\n";

	#ifdef QT_VERSION
		cout << "QT_VERSION" << "\n";
	#endif


	cout << "hello \n";
	return 0;
}
